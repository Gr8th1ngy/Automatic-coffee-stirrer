// LED blinks when servo moves. Everything is activated by a button.

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int buttonPin = 5; // create pin 5 for button

int buttonState = 0; // variable to store button status
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
      // in steps of 10 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      digitalWrite(ledPin,HIGH);       // Turns on LED
      delay(100);                       // waits 100ms for the servo to reach the position
      digitalWrite(ledPin,LOW);        // Turns off LED to create a blinking effect
      delay(100);
    }
    for (pos = 180; pos >= 0; pos -=10) { // same as above but backwards
      myservo.write(pos);
      digitalWrite(ledPin,HIGH);
      delay(100);
      digitalWrite(ledPin,LOW);
      delay(100);
    }
  }
}
