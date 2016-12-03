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
