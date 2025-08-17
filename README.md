# Consentium IoT Light Intensity Monitor

This project demonstrates how to use the **ConsentiumThings Edge Board Library** with an ESP32 board to:

- Connect to Wi-Fi  
- Read data from an LDR (Light Dependent Resistor) sensor  
- Send the data to the Consentium IoT platform  
- Perform OTA (Over-The-Air) firmware updates

## 📦 Features

- ✅ Wi-Fi connectivity
- ✅ Light intensity monitoring using LDR
- ✅ Cloud data transmission via Consentium IoT
- ✅ OTA firmware update support
- ✅ Configurable transmission and update intervals

---

## 🛠️ Hardware Requirements

- ESP32 development board  
- LDR sensor (connected to analog pin 34)  
- Resistor for voltage divider (typically 10kΩ)  
- Breadboard and jumper wires  

---

## 🔧 Pin Configuration

| Component   | ESP32 Pin |
|-------------|-----------|
| LDR Sensor  | 34 (ADC)  |
| DHT 11      | 4         |

---

## 📶 Configuration

Edit the following values in the code:

```cpp
const char *ssid = "YOUR_WIFI_SSID";
const char *pass = "YOUR_WIFI_PASSWORD";

const char *SendApiKey = "YOUR_SEND_API_KEY";
const char *ReceiveApiKey = "YOUR_RECEIVE_API_KEY";
const char *BoardApiKey = "YOUR_BOARD_API_KEY";
