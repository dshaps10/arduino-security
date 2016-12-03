/*
Source code for testing the PIR sensor
*/

const int ledPin = 13;    // pin for LED
const int inputPin = 2;   // input pin (for PIR sensor)
const int pirState = LOW; // default state, no motion detected
const int val = 0;
const int ledBlinkTime = 500; // Blink while calibrating

// wait 60 seconds for sensor to calibrate
const unsigned int calibrationTime = 60000;

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input

  // Serial.begin(9600);

  // 
  for (unsigned int = 0; i < calibrationTime; i += ledBlinkTime*2) {
    digitalWrite(ledPin, HIGH);
    delay(ledBlinkTime);
    digitalWrite(ledPin, LOW);
    delay(ledBlinkTime);  
  }

}

void loop() {

  val = digitalRead(inputPin);    // read input vlue
  if (val == HIGH) {            // check if input is High
    digitalWrite(ledPin, HIGH); // turn LED on
    if(pirState == LOW) {
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
