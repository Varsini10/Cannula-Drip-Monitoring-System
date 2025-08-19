<h2>💧 Cannula-Drip-Monitoring-System </h2>

A smart healthcare project designed to monitor IV (saline) drip levels in real-time and alert medical staff before depletion. This system enhances nurse efficiency and ensures patient safety through continuous monitoring and remote notifications.

**📌 Features**

- Real-time Monitoring – Uses an Ultrasonic Sensor to track saline water levels.

- Smart Alerts – GSM module sends SMS notifications when IV levels are low.

- Local Alert System – Buzzer alarm notifies nearby nurses for immediate action.

- Improved Patient Care – Minimizes risk of air bubbles entering the cannula due to unnoticed IV depletion.

**🛠️ Tech Stack**

- Microcontroller: Arduino

- Sensors & Modules: Ultrasonic Sensor, GSM Module, Buzzer

- Programming Language: C/C++ (Arduino IDE)

**⚙️ Working Principle**

- The ultrasonic sensor continuously measures the saline water level in the IV bag.

- When the level reaches a critical threshold, the buzzer triggers an alert.

- Simultaneously, the GSM module sends an SMS to the assigned nurse/doctor.

- Continuous monitoring ensures timely intervention and better patient care.

**🚀 How to Use**

- Connect the Ultrasonic Sensor, GSM Module, and Buzzer to Arduino as per circuit diagram.

- Upload the Arduino code from this repository using Arduino IDE.

- Power the circuit and place the sensor above the IV bag.

- Configure GSM module with a valid SIM card to enable SMS alerts.

**🌟 Impact**

- Reduces nurse workload by automating IV monitoring.

- Improves hospital efficiency through remote alerts.

- Enhances patient safety by preventing IV-related complications.
