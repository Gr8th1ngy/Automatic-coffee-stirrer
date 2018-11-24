// Runs two alternatively blinking LEDs.

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT); // Set pin 7 as a LED pin
  pinMode(10 , OUTPUT); // Set pin 10 as a LED pin
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, HIGH);   // turn the LED on
  delay(100);                       // wait for 0.1 second
  digitalWrite(7, LOW);    // turn the LED off
  delay(100);                       // wait for 0.1 second
  digitalWrite(10, HIGH);   // turn the second LED on
  delay(100);                       // wait for 0.1 second
  digitalWrite(10, LOW);    // turn the second LED off
  delay(100);                       // wait for 0.1 second
}
