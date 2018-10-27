#include <Servo.h>

Servo myservo;  // create servo object to control a servo
const int buttonPin = 5;
int buttonState = 0;

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(buttonPin,INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    
    Serial.println(buttonState);
    for (pos = 0; pos <= 180; pos += 1) {
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(1);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -=1) {
      myservo.write(pos);
      delay(1);
    }
  }
}
