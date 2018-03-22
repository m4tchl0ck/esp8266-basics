#include <Arduino.h>                    // Arduino framework reference
#include <ESP8266WiFi.h>                // WiFi module reference

const char* ssid = "";                  // WiFi SSID
const char* password = "";              // WiFi Password

void wifiConnect();                     // Method declaration
String mac;                             // MAC address variable

void setup() {
  Serial.begin(9600);                   // setup port COM with bound 9600 bps
  while (!Serial) ;                     // wait for serial port
  wifiConnect();                        // connect to WiFi
}

void loop() {
  Serial.print("MAC: ");
  Serial.println(mac);                  // send MAC address to COM
  delay(1000);                          // wait 1 s
}

void wifiConnect(){
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.disconnect();                    // ensure that WiFi is disconected
  WiFi.mode(WIFI_STA);                  // set WiFi mode as client
  WiFi.begin(ssid, password);           // begin connection process

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }                                     // wait until WiFi is connected

  mac = WiFi.macAddress();              // read device MAC address

  Serial.println("Connected!");
}
