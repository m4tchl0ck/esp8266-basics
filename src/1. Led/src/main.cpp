#include <Arduino.h>                    // Arduino framework reference

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);         // setup led pin as output
}

void loop() {
  digitalWrite(BUILTIN_LED, HIGH);      // turn on led
  delay(1000);                          // wait 1 s
  digitalWrite(BUILTIN_LED, LOW);       // turn off led
  delay(1000);                          // wait 1 s
}
