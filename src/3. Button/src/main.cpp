#include <Arduino.h>                    // Arduino framework reference

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);         // setup led pin as output
  Serial.begin(9600);                   // setup port COM with bound 9600 bps
  while (!Serial) ;                     // wait for serial port
  pinMode(D3, INPUT);                   // setup button pis as input
}

void loop() {
  byte state = digitalRead(D3);         // read state of D3 pin
  if (LOW == state) {
    digitalWrite(BUILTIN_LED, HIGH);    // turn off led
  } else {
    digitalWrite(BUILTIN_LED, LOW);     // turn on led
  }
  Serial.println(state);                // sebd state to COM
}
