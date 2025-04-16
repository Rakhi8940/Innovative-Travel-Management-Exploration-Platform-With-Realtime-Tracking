#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Galaxy M33 5G3921";
const char* password = "yashika170204";

// MQTT broker details
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// MQTT topics
const char* temp_topic = "iotfrontier/temperature";
const char* humidity_topic = "iotfrontier/humidity";
const char* soil_moisture_topic = "iotfrontier/soil_moisture";
const char* intensity_topic = "iotfrontier/intensity";
const char* visibility_topic = "iotfrontier/visibility";
const char* rain_topic = "iotfrontier/rain";
const char* object_count_topic = "iotfrontier/object_count";
const char* flow_topic = "iotfrontier/flow_rate";
const char* leak_topic = "iotfrontier/leak_status";
const char* buzzer_status_topic = "iotfrontier/buzzer_status"; // Topic for buzzer status
const char* object_topic = "iotfrontier/object"; // Topic for object detection status

// Pin Definitions
#define DHT_PIN 14           // DHT sensor pin
#define SOIL_MOISTURE_PIN 34 // Soil moisture sensor pin
#define LDR_PIN 35           // LDR sensor pin
#define RAIN_SENSOR_PIN 32   // Rain sensor pin
#define TRIG_PIN 13          // Ultrasonic sensor TRIG pin
#define ECHO_PIN 12          // Ultrasonic sensor ECHO pin
#define BUZZER_PIN 27        // Buzzer pin
#define OBJECT_COUNT_PIN 26  // Object count pin
#define IR_SENSOR_PIN 25     // GPIO pin for IR sensor

// Variables
long duration;
float distance;
int objectCount = 0;

// Setup WiFi and MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Function to read from DHT sensor (simulated)
float readTemperature() {
    return random(20, 30); // Simulated temperature between 20 to 30 °C
}

float readHumidity() {
    return random(40, 60); // Simulated humidity between 40% to 60%
}

int readSoilMoisture() {
    return analogRead(SOIL_MOISTURE_PIN); // Read the soil moisture
}

int readLightIntensity() {
    return analogRead(LDR_PIN); // Read light intensity
}

int readRainStatus() {
    return digitalRead(RAIN_SENSOR_PIN); // Read rain status (1 if rain, 0 if no rain)
}

void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);

    // Set pin modes
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SOIL_MOISTURE_PIN, INPUT);
    pinMode(LDR_PIN, INPUT);
    pinMode(RAIN_SENSOR_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(OBJECT_COUNT_PIN, INPUT_PULLUP);
    pinMode(IR_SENSOR_PIN, INPUT); // Set pin mode for IR sensor

    // Activate the buzzer when kit is powered on
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer
    delay(5000);                     // Keep buzzer on for 1 second
    digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");

    // Setup MQTT server
    client.setServer(mqtt_server, mqtt_port);
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP32Client")) {
            Serial.println("connected");
            client.subscribe(temp_topic);
            client.subscribe(humidity_topic);
            client.subscribe(soil_moisture_topic);
            client.subscribe(intensity_topic);
            client.subscribe(visibility_topic);
            client.subscribe(rain_topic);
            client.subscribe(object_count_topic);
            client.subscribe(flow_topic);
            client.subscribe(leak_topic);
            client.subscribe(buzzer_status_topic);
            client.subscribe(object_topic); // Subscribe to object topic
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();

    // Read sensors
    float temperature = readTemperature();
    float humidity = readHumidity();
    int soilMoisture = readSoilMoisture();
    int lightIntensity = map(readLightIntensity(), 0, 4095, 0, 100);
    int lightVisibility = map(readLightIntensity(), 0, 4095, 100, 0);
    int rainStatus = readRainStatus();
    
    // Ultrasonic sensor to measure distance
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * 0.0343) / 2; // Distance in cm
    
    // Flow and leak simulation
    float flowRate = abs(distance - 50) * 10; // Example calculation for flow rate
    String leakStatus = (distance < 5) ? "Leak Detected" : "No Leak";

    // Count objects (assuming a pulse on OBJECT_COUNT_PIN when an object passes)
    if (digitalRead(OBJECT_COUNT_PIN) == LOW) {
        objectCount++;
        digitalWrite(BUZZER_PIN, HIGH); // Sound buzzer when an object is detected
        client.publish(buzzer_status_topic, "1"); // Publish buzzer on status
        delay(100); // Buzzer sound duration
        digitalWrite(BUZZER_PIN, LOW);
        client.publish(buzzer_status_topic, "0"); // Publish buzzer off status
        delay(100);
    }

    // Read IR sensor state
    int irState = digitalRead(IR_SENSOR_PIN);
    if (irState == LOW) { // Change to `HIGH` if logic is reversed
        Serial.println("Object detected!");
        client.publish(object_topic, "1");
    } else {
        Serial.println("No object detected.");
        client.publish(object_topic, "0");
    }

    // Print all sensor values to Serial Monitor
    Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Soil Moisture: "); Serial.print(soilMoisture); Serial.println();
    Serial.print("Light Intensity: "); Serial.print(lightIntensity); Serial.println(" %");
    Serial.print("Light Visibility: "); Serial.print(lightVisibility); Serial.println(" %");
    Serial.print("Rain Status: "); Serial.print(rainStatus ? "No Rain Detected" : "No Rain"); Serial.println();
    Serial.print("Object Count: "); Serial.print(objectCount); Serial.println();
    Serial.print("Flow Rate: "); Serial.print(flowRate); Serial.println(" cm/s");
    Serial.print("Leak Status: "); Serial.println(leakStatus);

    // Publish data to MQTT topics
    Serial.println("Publishing data to MQTT...");
    client.publish(temp_topic, String(temperature).c_str());
    client.publish(humidity_topic, String(humidity).c_str());
    client.publish(soil_moisture_topic, String(soilMoisture).c_str());
    client.publish(intensity_topic, String(lightIntensity).c_str());
    client.publish(visibility_topic, String(lightVisibility).c_str());
    client.publish(rain_topic, String(rainStatus).c_str());
    client.publish(object_count_topic, String(objectCount).c_str());
    client.publish(flow_topic, String(flowRate).c_str());
    client.publish(leak_topic, leakStatus.c_str());

    // Delay before next reading
    delay(5000); // Delay for 5 seconds
}
