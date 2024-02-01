# Cannula-Drip-Monitoring-System
const int trigPin = 2;
const int echoPin = 4;
const int green = 7;
const int red = 9;
const int buzz=3;
//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
  float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
     pinMode(buzz, OUTPUT); // Sets the echoPin as an Input
     pinMode(7, OUTPUT);
     pinMode(9, OUTPUT);
  
  
    
    

}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  if(distanceCm>10)
  {
      digitalWrite(buzz, HIGH);
      digitalWrite (green,HIGH);
      
      digitalWrite (red,LOW);
      delay(1000);
  }
 
  else(distanceCm<=10)
  {
    digitalWrite (red,HIGH);
    
    digitalWrite (green,LOW);
    delay(1000);
  }
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  
  delay(1000);
}
