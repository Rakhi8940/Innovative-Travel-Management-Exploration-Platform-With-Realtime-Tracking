# 🌍 Innovative Travel Management and Exploration Platform  
### 🚀 Real-Time Tracking | Predictive Analytics | AI & IoT Integration

## 📌 Overview
This project is an **AI-powered travel assistant platform** that combines **real-time tracking**, **predictive analytics**, and **IoT-based environmental monitoring** to create a seamless and intelligent travel experience. Designed for **solo travelers, families, and tourism agencies**, it works **without a backend**, running entirely on **ESP32 + Edge AI (TinyML)**.

## 🔧 Features

### 🧠 AI-Based Route Optimization
- Smart chatbot to assist with **travel planning**
- Uses **ML models** to predict **ETA**, **traffic**, and **weather**
- Integrated with **Google Maps API** and **TinyML** models

### 📍 Real-Time Location Tracking
- Tracks location using **Neo-6M GPS Module**
- Visualized on a **mobile-accessible web dashboard**
- Supports **geo-fencing** and safety zones

### 🌦️ IoT-Enabled Environmental Monitoring
- Sensors: `DHT11`, `MQ135`, `Rain Sensor`, `UV Sensor`, etc.
- Predicts weather/air quality trends using **LSTM/TinyML**
- Displays data & alerts on **ESP32-hosted webpage**

### 📊 Dashboard Without Backend
- Mobile-friendly **web dashboard hosted directly on ESP32**
- No external servers, APIs, or cloud storage needed

## 🛠️ Tech Stack

### 💻 Software
- `Arduino IDE` (ESP32 Programming)
- `TensorFlow / TinyML` (Edge AI for predictions)
- `HTML/CSS/JavaScript` (Web Interface)
- `Dialogflow + Google Assistant` (Voice Interaction)
- `ESPAsyncWebServer` (Web Server on ESP32)

### 🔌 Hardware
- `ESP32` microcontroller  
- `Neo-6M GPS` module  
- `DHT11 / DHT22`  
- `MQ135` air quality sensor  
- `Rain sensor`, `UV sensor`, `Vibration sensor`, etc.  
- `DFPlayer Mini` + speaker (for audio alerts)  
- `SD Card Module` (for data logging)

## 🧠 AI & Predictive Analytics

- Trained ML models in Python (using LSTM/Regression)
- Converted to **`.tflite` (TinyML)** models for ESP32 inference
- On-device predictions for:
  - ETA & traffic delays
  - Weather conditions
  - Air quality and anomalies
 
  ## 🚦 Use Cases
- 🚗 Route optimization based on traffic and weather
- 🌫️ Alerts for rain, poor air quality, or high UV index
- 📍 Parental tracking and safety for travel groups
- 🧭 Fully offline functionality with real-time dashboard

🔹 2. Setup Arduino Libraries
Install:
    DHT sensor library
    Adafruit BMP/BME280
    TinyGPS++
    ESPAsyncWebServer
    DFRobotDFPlayerMini
    TensorFlow Lite for Microcontrollers

🔹 3. Upload Code to ESP32
    Open main.ino in Arduino IDE
    Connect your ESP32 and flash the code

🔹 4. Access Dashboard
    Connect your mobile to same WiFi
    Open browser → visit http://<ESP32-IP>
    View sensor data, ask chatbot questions, hear voice alerts!

🧪 Demo Highlights
    🔄 Real-time updates on dashboard
    🎤 Ask: “Find best route from Mumbai to Pune” via chatbot or voice
    🌩️ ESP32 predicts storm based on pressure drop and alerts via speaker
    🚨 Air Quality drops below 50 → triggers mobile and buzzer alert

✨ Credits
Developed by: Rakhi Yadav
Special thanks to: Open Source contributors, Google Assistant, TensorFlow Lite, and the Arduino community.
