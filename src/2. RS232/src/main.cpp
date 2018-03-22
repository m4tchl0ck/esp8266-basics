#include <Arduino.h>                    // Arduino framework reference

void setup() {
  Serial.begin(9600);                   // setup port COM with bound 9600 bps
  while (!Serial) ;                     // wait for serial port
  Serial.print("Setup finished.");      // send text to COM
}

void loop() {
  Serial.printf("Loop begin\n");           // send text to COM
  delay(1000);                          // wait 1 s
  Serial.print("Loop end\n");             // send text to COM
}
