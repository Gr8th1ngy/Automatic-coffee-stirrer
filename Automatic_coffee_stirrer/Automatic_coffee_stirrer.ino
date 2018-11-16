#include <Servo.h>

Servo myservo;

const int SW_pin = 4;
const int X_pin = 0;
const int Y_pin = 1;
const int ledPin = 2;
const int buttonPin = 3;

int pos = 0;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  myservo.attach(5);
}

void stir(int analog) {
  int stirSpeed = analog / 102 + 5;

  for (pos = 0; pos <= 20; pos += 1) {
    myservo.write(pos);
    buttonState = digitalRead(buttonPin);
    delay(stirSpeed);
  }
  for (pos = 20; pos >= 0; pos -= 1) {
    myservo.write(pos);
    buttonState = digitalRead(buttonPin);
    delay(stirSpeed);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState ==  HIGH) {
    delay(500);
    buttonState = digitalRead(buttonPin);
    while (buttonState == LOW) {
      digitalWrite(ledPin, HIGH);
      stir(analogRead(X_pin));
      if (buttonState == HIGH) {
        digitalWrite(ledPin, LOW);
        exit(0);
      }
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}
