/*
Source code for testing the PIR sensor
*/

int ledPin = 13;    // pin for LED
int inputPin = 2;   // input pin (for PIR sensor)
int pirState = LOW; // default state, no motion detected
int val = 0;        // for reading pin status

void setup() {

  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input

  Serial.begin(9600);

}

void loop() {

  val digitalRead(inputPin);    // read input vlue
  if (val == HIGH) {            // check if input is High
    digitalWrite(ledPin, HIGH); // turn LED on
    if(pirstate == LOW) {
      Serial.println("Motion detected");
      // Change state to high in reponse to motion detected
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED off
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      // Change back to resting state once motion ends
      pirState = LOW;
    }
  }

}
