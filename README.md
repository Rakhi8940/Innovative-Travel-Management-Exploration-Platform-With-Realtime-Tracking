<p align="center">
  <img src="https://github.com/user-attachments/assets/59028196-d650-40ce-bf9a-fe5f9bd422b3" alt="Banner" width="100%">
</p>

# 🌍 Innovative Travel Management and Exploration Platform  
### 🚀 Real-Time Tracking | Predictive Analytics | AI & IoT Integration

---

## 📌 Overview

**AIoTravel Kit** is an **AI-powered travel assistant platform** designed for solo travelers, families, and tourism agencies. It merges **real-time tracking**, **predictive analytics**, and **IoT-based environmental monitoring** for a seamless, intelligent travel experience. The platform operates **entirely on ESP32 + Edge AI (TinyML)**––no backend, cloud, or external servers required.

---

## 🔧 Features

### 🧠 AI-Based Route Optimization
- Conversational **smart chatbot** for planning and guidance
- Predicts **ETA**, **traffic**, and **weather** using ML models
- Integrates **Google Maps API** and **TinyML** for on-device intelligence

### 📍 Real-Time Location Tracking
- Uses **Neo-6M GPS Module** for accurate positioning
- **Mobile-accessible dashboard** hosted on ESP32
- Supports **geo-fencing** and safety zone alerts

### 🌦️ IoT-Enabled Environmental Monitoring
- Monitors with sensors: `DHT11`, `MQ135`, `Rain Sensor`, `UV Sensor`, etc.
- Predicts weather/air quality trends with **LSTM/TinyML**
- Provides live data and alerts via ESP32-hosted webpage

### 📊 Dashboard Without Backend
- **Web dashboard** hosted directly on ESP32 (no external servers)
- Mobile-friendly and accessible on local WiFi

---

## 🛠️ Tech Stack

### 💻 Software
- **Arduino IDE** (ESP32 programming)
- **TensorFlow/TinyML** (Edge AI predictions)
- **HTML/CSS/JavaScript** (Web dashboard interface)
- **Dialogflow + Google Assistant** (Voice/Chatbot interaction)
- **ESPAsyncWebServer** (Web server on ESP32)

### 🔌 Hardware

<p align="center">
  <img src="https://github.com/user-attachments/assets/6c0667e2-9003-456f-82e1-84ba4d023de1" alt="Circuit Diagram" width="400">
  <br/>
  <b>Circuit Diagram</b>
</p>

- `ESP32` microcontroller  
- `Neo-6M GPS` module  
- `DHT11/DHT22` temperature & humidity
- `MQ135` air quality sensor  
- `Rain sensor`, `UV sensor`, `Vibration sensor`  
- `DFPlayer Mini` + speaker (voice/audio alerts)  
- `SD Card Module` (data logging)

<p align="center">
  <img src="https://github.com/user-attachments/assets/e8c7473b-e7ae-4438-aa21-3897fd67329f" alt="AIoTravel Kit" width="400">
  <br/>
  <b>AIoTravel Kit</b>
</p>

---

## 🧠 AI & Predictive Analytics

- Trained ML models in Python with **LSTM/Regression**
- Converted to `.tflite` (TinyML) for ESP32
- On-device predictions for:
  - ETA & traffic delays
  - Weather & environmental anomalies
  - Air quality alerts

---

## 🚦 Use Cases

- 🚗 **Route optimization** based on real-time conditions
- 🌫️ **Automated alerts** for weather, air quality, UV index, and more
- 📍 **Parental/group tracking** and geo-fenced safety
- 🧭 **Fully offline** operation with real-time dashboard and voice/chatbot support

---

## 🔧 Quick Start

#### 1. Hardware Setup
- Assemble ESP32 with GPS, sensors, SD card, and optional speaker

#### 2. Arduino Libraries
Install:
- DHT sensor library
- Adafruit BMP/BME280
- TinyGPS++
- ESPAsyncWebServer
- DFRobotDFPlayerMini
- TensorFlow Lite for Microcontrollers

#### 3. Flash the Code
- Open `main.ino` in Arduino IDE
- Connect ESP32 and upload code

#### 4. Access the Dashboard
- Connect your device to the same WiFi as ESP32
- Visit `http://<ESP32-IP>` in your browser
- View real-time sensor data, interact with the chatbot, and receive voice alerts

---

## 🧪 Demo Highlights

- 🔄 **Live updates** on the dashboard
- 🎤 Ask: “Find best route from Mumbai to Pune” via chatbot or voice
- 🌩️ ESP32 predicts storms from environmental data, alerts with audio
- 🚨 Air Quality alert (<50 AQI) triggers mobile and buzzer notifications

---

## 📷 Screenshots

### 1. Website Homepage
<p align="center">
  <img src="https://github.com/user-attachments/assets/0931155b-c7b9-4110-9383-089c59f36fe6" alt="Website Homepage" width="600">
</p>

### 2. AI Chatbot
<p align="center">
  <img src="https://github.com/user-attachments/assets/66204325-532f-4ccf-b85e-e9aa2d9f1402" alt="AI Chatbot" width="600">
</p>

### 3. Real-Time Tracking Page
<p align="center">
  <img src="https://github.com/user-attachments/assets/42522e35-4a00-4509-94db-96e25cd45aca" alt="Real-Time Tracking" width="600">
</p>

### 4. Login Page
<p align="center">
  <img src="https://github.com/user-attachments/assets/b468b7dc-60df-46be-b4f4-6068d09f1cc1" alt="Login Page" width="600">
</p>

### 5. Booking Section
<p align="center">
  <img src="https://github.com/user-attachments/assets/0c5b9496-4602-4685-bebf-25254a2ab8d8" alt="Booking Section" width="600">
</p>

### 6. Booking & Accommodation Page
<p align="center">
  <img src="https://github.com/user-attachments/assets/4c7c7a8c-29b9-4602-b333-fda299e3cd0a" alt="Booking & Accommodation" width="600">
</p>

### 7. Node-RED Dashboard
<p align="center">
  <img src="https://github.com/user-attachments/assets/c0231319-328f-4454-9b09-8e135a4c5685" alt="Node-RED Dashboard" width="600">
</p>

### 8. Exploration Section
<p align="center">
  <img src="https://github.com/user-attachments/assets/c81e90e8-293d-45ac-b4a5-c22354445a4f" alt="Exploration Section" width="600">
</p>

### 9. Gallery & Packages Section
<p align="center">
  <img src="https://github.com/user-attachments/assets/28839a54-6878-46c0-992f-487eceb3eea9" alt="Gallery & Packages" width="600">
</p>

### 10. Support & Contact Section
<p align="center">
  <img src="https://github.com/user-attachments/assets/ef3dfa39-3f32-4e36-8b31-9af4a34e7696" alt="Support & Contact" width="600">
</p>

### 11. Additional Features
<p align="center">
  <img src="https://github.com/user-attachments/assets/50a95af5-b0d9-4030-856b-66ec596ce0c2" alt="Additional Features" width="600">
</p>

---

## ✨ Credits

Developed by: **Rakhi Yadav**  
Special thanks: Open Source contributors, Google Assistant, TensorFlow Lite, and the Arduino community.

---

> **Smart, secure, and seamless travel—powered by AI & IoT, right at the edge.**
