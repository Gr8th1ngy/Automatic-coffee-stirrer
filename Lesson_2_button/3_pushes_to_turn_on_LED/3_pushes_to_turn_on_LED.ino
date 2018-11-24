// The user has to push button 3 times in 1 sec intervals to turn on LED.

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int pushCount = 0;           // counts the number of pushes

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); //Allows printing count values
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if (millis() < 4000) { // time limit is 4 seconds for 3 pushes
    if (buttonState == HIGH) {
      pushCount++; // if the button is push adds 1 to the count
      delay (500); // waits for user to stop pressing the button
      Serial.println(pushCount); // prints the number of pushes
      if (pushCount == 3) {
        // if count is 3 then turn LED on:
        digitalWrite(ledPin, HIGH);
      }
    }
  }
}
