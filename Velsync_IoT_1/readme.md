# IoT Temperature & Humidity Monitor using ESP32 & DHT11

This project is part of **Task 01** of the **Internet of Things & Embedded Systems Internship** by **VELSYNC**.

The system reads temperature and humidity data from a **DHT11 sensor** using an **ESP32** and sends the data to the **ThingSpeak cloud platform** for real-time monitoring and visualization.

---

## 🔧 Components Used
- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- Jumper Wires
- WiFi Network
- ThingSpeak Cloud Platform

---

## 🛠️ Software & Tools
- Arduino IDE
- ThingSpeak
- ESP32 Board Package
- DHT Sensor Library

---

## 📡 Working Principle
1. The DHT11 sensor measures temperature and humidity.
2. ESP32 reads sensor data at regular intervals.
3. The ESP32 connects to WiFi.
4. Sensor data is sent to ThingSpeak using HTTP requests.
5. Data is visualized on the ThingSpeak dashboard in real time.

---

## 🔌 Pin Connections

| DHT11 Pin | ESP32 Pin |
|----------|-----------|
| VCC      | 3.3V      |
| DATA     | GPIO 4    |
| GND      | GND       |

---

## 📊 Output
- Live temperature and humidity data
- Graphical visualization on ThingSpeak dashboard

---

## 📸 Screenshots
_Add screenshots of:_
- Serial Monitor output  
- ThingSpeak dashboard graphs  
- Circuit diagram (optional)

---

## 📂 Files in This Repository
- `esp32_dht11_thingspeak.ino` – Main Arduino code
- `README.md` – Project documentation
- `screenshots/` – Output and dashboard images

---

## ✅ Task Status
✔ Task 01 Completed  
✔ GitHub Repository Created  
✔ Cloud Integration Done  

---

## 🚀 Learning Outcomes
- ESP32 WiFi connectivity
- DHT11 sensor interfacing
- Cloud data logging using ThingSpeak
- Basic IoT system architecture

---

## 👤 Author
**Abhishek Dubey**  
B.Tech ECE | Embedded Systems & IoT Intern
