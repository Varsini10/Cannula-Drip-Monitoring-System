// Cannula-Drip-Monitoring-System

#include <SoftwareSerial.h>  
SoftwareSerial gsm(10, 11); // RX, TX pins for GSM module (SIM900/800)

// Pin definitions
const int trigPin = 2;
const int echoPin = 4;
const int green = 7;
const int red = 9;
const int buzz = 3;

// Define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

//For Ultrasonic sensor
long duration;
float distanceCm;
float distanceInch;

// Setup code
void setup() {
  Serial.begin(115200);  // Serial monitor
  gsm.begin(9600);       // GSM module baud rate

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  // GSM init delay
  delay(1000);
  Serial.println("System Initialized...");
  sendSMS("Cannula-Drip-Monitoring-System Started ✅");
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distanceCm = duration * SOUND_VELOCITY / 2;
  distanceInch = distanceCm * CM_TO_INCH;

  if (distanceCm > 10) {
    digitalWrite(buzz, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    delay(1000);
  } 
  else {  
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(buzz, LOW);

    // Send SMS alert when saline is low
    sendSMS("⚠️ ALERT: IV Saline Level is Low! Please check immediately.");
    delay(5000); // Prevent spamming SMS (wait 5s)
  }

  // Print values to Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

  delay(1000);
}

// Function to send SMS via GSM
void sendSMS(String message) {
  gsm.println("AT+CMGF=1");   // Set SMS mode to text
  delay(500);
  gsm.println("AT+CMGS=\"+91XXXXXXXXXX\""); // Replace with nurse/doctor phone number
  delay(500);
  gsm.print(message);
  delay(500);
  gsm.write(26); // Ctrl+Z to send SMS
  delay(1000);
}
