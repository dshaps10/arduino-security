/*
Source code for testing the PIR sensor
*/

const int ledPin = 13;    // pin for LED
const int sensorPin = 2;   // input pin (for PIR sensor)
const int ledBlinkTime = 500; // Blink while calibrating

// wait 60 seconds for sensor to calibrate
const unsigned int calibrationTime = 60000;

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(sensorPin, INPUT); // declare sensor as input

  // loop for calibrating sensor
  for (unsigned int i = 0; i < calibrationTime; i += ledBlinkTime*2) {
    digitalWrite(ledPin, HIGH);
    delay(ledBlinkTime);
    digitalWrite(ledPin, LOW);
    delay(ledBlinkTime);  
  }

}

void loop() {
  // if motion is detected, turn on LED light
  if (digitalRead(sensorPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
    
    // Tell host computer that motion was detected    
    Serial.print(1);
    
    // Sleep for 1 second to prevent overloading the sensor
    delay(1000);
  } else {

    // Turn LED off
    digitalWrite(ledPin, LOW);
  }
}

