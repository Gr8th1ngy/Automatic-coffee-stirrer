#include <Servo.h>

Servo myservo;  // create servo object to control a servo
const int buttonPin = 5; // create pin for button

int buttonState = 0; // create variable to store button
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(buttonPin,INPUT); // set buttonPin as an input
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  buttonState = digitalRead(buttonPin); // reads whether the button is pressed or not

  if (buttonState == HIGH) {
    // if the button is pressed, move the servo
    for (pos = 0; pos <= 180; pos += 1) { // move from 0 to 180 degrees
      // in steps of 1 degree forward
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -=1) { // same as above but moves backwards
      // steps of 1 degree backward
      myservo.write(pos);
      delay(1);
    }
  }
}
