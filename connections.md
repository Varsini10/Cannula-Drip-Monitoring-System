<h2>🔌 Circuit Connections </h2>

**1. Ultrasonic Sensor (HC-SR04)**

- VCC → Arduino 5V

- GND → Arduino GND

- Trig → Arduino Pin 2

- Echo → Arduino Pin 4

**2. Buzzer**

- + (Positive) → Arduino Pin 3

- – (Negative) → Arduino GND

**3. LED Indicators**

- Green LED → Arduino Pin 7 (with 220Ω resistor to GND)

- Red LED → Arduino Pin 9 (with 220Ω resistor to GND)

**4. GSM Module (SIM900 / SIM800L)**

- VCC → External 5V / 4A power supply (⚠️ Do not power directly from Arduino 5V, it cannot handle GSM current surge)

- GND → Common GND with Arduino

- TX (GSM) → Arduino Pin 10 (RX of SoftwareSerial)

- RX (GSM) → Arduino Pin 11 (TX of SoftwareSerial)

- SIM Card → Insert a valid SIM card with SMS balance

**5. Arduino Power**

- Use USB (for testing) or 9V adapter (for standalone running).

- Ensure common ground between GSM and Arduino.

**⚠️ Important Notes:**

- GSM modules require a separate 5V / 2A–4A power source, as Arduino cannot supply enough current during SMS transmission.

- Always connect GND of Arduino and GSM together.

- Use resistors with LEDs to prevent burning them.
