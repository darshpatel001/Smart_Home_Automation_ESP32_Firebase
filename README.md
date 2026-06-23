# ESP32 Firebase Home Automation System

## Overview

This project implements a cloud-connected Home Automation System using the ESP32 microcontroller, Firebase Realtime Database, Google Cloud services, and DHT temperature/humidity sensors.

The system enables users to remotely monitor environmental conditions and control electrical appliances through cloud connectivity. Data is synchronized in real time between the ESP32 and Firebase, providing a scalable IoT-based smart home solution.

This project demonstrates practical implementation of:

* IoT Architecture
* Cloud Connectivity
* Firebase Realtime Database
* ESP32 Development
* Sensor Integration
* Remote Appliance Control
* Real-Time Monitoring

---

## Features

* Remote Appliance Control
* Firebase Realtime Database Integration
* Google Cloud Connectivity
* Real-Time Data Synchronization
* Temperature Monitoring
* Humidity Monitoring
* Wi-Fi Connectivity
* Cloud-Based Dashboard
* Multi-Device Access
* IoT Automation

---

## Hardware Used

| Component         | Purpose                       |
| ----------------- | ----------------------------- |
| ESP32             | Main Controller               |
| DHT11 / DHT22     | Temperature & Humidity Sensor |
| Relay Module      | Appliance Control             |
| Wi-Fi Network     | Cloud Communication           |
| Firebase Database | Cloud Data Storage            |

---

## Software Used

| Software                   | Purpose                |
| -------------------------- | ---------------------- |
| Arduino IDE                | Development            |
| Firebase Realtime Database | Cloud Backend          |
| Google Cloud               | IoT Infrastructure     |
| Firebase ESP32 Library     | Database Communication |
| DHT Sensor Library         | Sensor Interface       |

---

## Libraries Required

### Firebase ESP32

```text
https://github.com/mobizt/Firebase-ESP32
```

### Adafruit DHT Sensor Library

```text
https://github.com/adafruit/DHT-sensor-library
```

---

## Project Structure

```text
.
├── Final_sketch_For_5th_sem.ino
├── Firebase-ESP32/
├── DHT-sensor/
├── README.md
└── LICENSE
```

---

## System Architecture

```text
                +------------------+
                | Firebase Cloud   |
                +------------------+
                         ^
                         |
                      Wi-Fi
                         |
                         v

                +------------------+
                |      ESP32       |
                +------------------+
                   |           |
                   |           |
                   v           v

            +---------+   +---------+
            | DHT11   |   | Relay   |
            | Sensor  |   | Module  |
            +---------+   +---------+

                   |
                   v

            Temperature
            Humidity Data
```

---

## Working Principle

### Sensor Monitoring

The DHT sensor continuously measures:

* Temperature
* Humidity

Example:

```text
Temperature : 31°C
Humidity    : 58%
```

---

### Cloud Upload

ESP32 uploads sensor data to Firebase:

```text
Temperature -> Firebase
Humidity    -> Firebase
```

---

### Appliance Control

User changes appliance state from cloud dashboard:

```text
Firebase
   |
   v
ESP32
   |
   v
Relay ON/OFF
```

---

### Real-Time Synchronization

Changes made in Firebase are immediately reflected on the ESP32 device.

---

## Functional Modules

### Wi-Fi Module

#### connectWiFi()

* Connects ESP32 to local network.
* Maintains cloud communication.

---

### Firebase Module

#### firebaseInit()

* Initializes Firebase connection.

#### uploadSensorData()

* Sends sensor values to cloud.

#### readRelayState()

* Reads appliance state from database.

---

### Sensor Module

#### readTemperature()

* Reads temperature from DHT sensor.

#### readHumidity()

* Reads humidity from DHT sensor.

---

### Relay Control Module

#### relayControl()

* Controls appliances using relay outputs.

---

## Data Flow

```text
1. Read DHT Sensor
2. Connect Firebase
3. Upload Sensor Data
4. Read Appliance Status
5. Update Relay State
6. Repeat Continuously
```

---

## Build Instructions

### Install Libraries

1. Firebase ESP32 Library
2. Adafruit DHT Sensor Library

### Open Project

```text
Arduino IDE
```

### Select Board

```text
ESP32 Dev Module
```

### Upload Firmware

```text
Upload to ESP32
```

---

## Screenshots

Add screenshots of:

* Firebase Realtime Database
* ESP32 Serial Monitor
* Temperature Monitoring
* Humidity Monitoring
* Appliance Control Dashboard

---

## Demo Video

If your video exists in repository root:

```markdown
## 🎥 Demo Video

[Watch Demo](./home_automation_firebase_demo.mp4)
```

---

## Concepts Demonstrated

* ESP32 Programming
* Firebase Realtime Database
* Google Cloud Integration
* IoT System Design
* Wi-Fi Communication
* Sensor Interfacing
* Cloud Automation
* Embedded Firmware Development

---

## Applications

* Smart Homes
* Environmental Monitoring
* Remote Appliance Control
* Energy Management
* IoT Research Projects
* Building Automation

---

## Future Improvements

* Mobile Application
* MQTT Integration
* Voice Assistant Support
* Energy Consumption Monitoring
* OTA Firmware Updates
* Multi-Room Automation

---

## Learning Outcomes

Through this project, I gained practical experience in:

* ESP32 Development
* Firebase Integration
* Cloud Communication
* IoT Architecture
* Sensor Interfacing
* Remote Monitoring Systems
* Smart Home Automation

---

## Author

**Darsh Patel**

Electronics & Communication Engineer

Firmware Engineer | Embedded Systems | IoT Developer

GitHub: https://github.com/darshpatel001

---

## License

This project is licensed under the MIT License.
