#include <Arduino.h>                    // Arduino framework reference
#include <Switch.h>                     // Switch reference

Switch button = Switch(D3, INPUT_PULLUP, LOW, 50, 3000);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);         // setup led pin as output
  Serial.begin(9600);                   // setup port COM with bound 9600 bps
  while (!Serial) ;                     // wait for serial port
}

void loop() {
   button.poll();
   if (button.longPress()) {
     Serial.println("LongPress");       // send state to COM
     digitalWrite(BUILTIN_LED, HIGH);   // turn off led
   }
   if (button.doubleClick()) {
     Serial.println("DoubleClick");     // send state to COM
     digitalWrite(BUILTIN_LED, LOW);    // turn on led
   }
}
