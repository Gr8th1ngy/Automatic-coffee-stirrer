#include <Servo.h>

Servo myservo; //Initialise Servo

const int SW_pin = 4; //Switch pin for joystick
const int X_pin = 0;  //X pin for joystick
const int Y_pin = 1;  //Y pin for joystick
const int ledPin = 2; //LED pin
const int buttonPin = 3; //Button pin. This is the on/off button

int pos = 0; //Variable to store position of servo
int buttonState = 0; //Variable to store state of button

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  myservo.attach(5); // Put servo to pin 5
}

void stir(int analog) {
//   this function moves the servo and the spoon attached to it.
//   [analog] is the value of joystick and ranges from 0 to 1024 with the initial (unmoved) value of 512.
  int stirSpeed = analog / 102 + 5; // stirSpeed is the time taken for servo to move 1 degree and ranges from 5 ms to 20 ms.

  for (pos = 0; pos <= 20; pos += 1) {
    myservo.write(pos); // move servo by 1 degree forward to up 20 degree
    buttonState = digitalRead(buttonPin); // check if button is pressed again
    delay(stirSpeed);
  }
  for (pos = 20; pos >= 0; pos -= 1) {
    myservo.write(pos); // move servo by 1 degree forward to up 20 degree
    buttonState = digitalRead(buttonPin); // check if button is pressed again
    delay(stirSpeed);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin); // check if button is pressed (if the stirrer is turnt on)

  if (buttonState ==  HIGH) {
    delay(500);
    buttonState = digitalRead(buttonPin); // check that the user stops pressing the button
    while (buttonState == LOW) {
      digitalWrite(ledPin, HIGH); // Turn on LED to show that the stirrer is working
      stir(analogRead(X_pin)); // Move servo
      if (buttonState == HIGH) {
        digitalWrite(ledPin, LOW); // Turn off LED and exit program if the button is pressed again (System is turnt off)
        exit(0);
      }
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}
