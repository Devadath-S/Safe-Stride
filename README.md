# 👨🏽‍🦯 Safe Stride

A smart blind stick powered by an ESP8266-based NodeMCU board that uses IR and ultrasonic sensors for real-time obstacle detection and sends proximity alerts to a mobile app via Wi-Fi.

## 🧰 Hardware Used

- NodeMCU ESP8266 board  
- HC-SR04 Ultrasonic Sensor  
- IR Sensor Module  
- Buzzer
- Jumper Wires
- Breadboard    
- Android smartphone  

## 👨🏽‍💻 Software Used

- Arduino IDE  
- MIT App Inventor

## ⚙️ How It Works

The ESP8266 board creates its own Wi-Fi network (Access Point). The mobile app connects to this network and sends periodic HTTP GET requests to fetch sensor data.

- If the ultrasonic sensor detects an obstacle within 100 cm, the ESP sends a message to the app. The app reads the message and announces it using text-to-speech.
- The IR sensor is independently monitored by the ESP, and it triggers a buzzer if a nearby object is detected.

## Getting Started

1. Upload the smart_stick.ino code to your NodeMCU using Arduino IDE  
2. Install and run the Android app built using the MIT App Inventor  
3. Connect your phone to the ESP8266's Wi-Fi network  
4. The app will start announcing obstacles when detected within 100 cm

