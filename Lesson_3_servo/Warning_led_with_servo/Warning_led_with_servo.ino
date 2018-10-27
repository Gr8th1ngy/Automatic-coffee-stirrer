#include <Servo.h>

Servo myservo;  // create servo object to control a servo
const int buttonPin = 5;
int buttonState = 0;

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    
    for (pos = 0; pos <= 180; pos += 10) {
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      digitalWrite(ledPin,HIGH);
      delay(100);                       // waits 15ms for the servo to reach the position
      digitalWrite(ledPin,LOW);
      delay(100);
    }
    for (pos = 180; pos >= 0; pos -=10) {
      myservo.write(pos);
      digitalWrite(ledPin,HIGH);
      delay(100);
      digitalWrite(ledPin,LOW);
      delay(100);
    }
  }
}
