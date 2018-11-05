#include <Servo.h>

// defines pins numbers
const int trigPin = 10;
const int echoPin = 9;
const int ledPin = 2;

Servo myservo;  // create servo object to control a servo

// defines variables
long duration;
int distance;
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT); // Sets ledPin as an Output
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // Starts the serial communication
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
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(3);                       // waits 1ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(3);                       // waits 1ms for the servo to reach the position
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
