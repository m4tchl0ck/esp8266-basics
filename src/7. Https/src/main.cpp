#include <Arduino.h>                    // Arduino framework reference
#include <ESP8266WiFi.h>                // WiFi module reference
#include <ESP8266HTTPClient.h>          // HTTP Client module reference

const char* ssid = "";                  // WiFi SSID
const char* password = "";              // WiFi Password

void wifiConnect();                     // Method declaration
String mac;                             // MAC address variable
String getRequest(String endpoint);     // Method declaration

void setup() {
  Serial.begin(9600);                   // setup port COM with bound 9600 bps
  while (!Serial) ;                     // wait for serial port
  wifiConnect();                        // connect to WiFi
}

void loop() {
  getRequest("https://demo4299438.mockable.io/hw");
  delay(30000);
}

String getRequest(String endpoint){
  HTTPClient http;
  String fingerPrint = "7dd702a63ecb9eec2b97a3e581f15e723bea4e95";
  Serial.printf("[HTTP] begin %s\n", endpoint.c_str());
  http.begin(endpoint, fingerPrint);

  Serial.printf("[HTTP] GET %s\n", endpoint.c_str());
  int httpCode = http.GET();
  // httpCode will be negative on error
  if(httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET code: %d\n", httpCode);

    if(httpCode == HTTP_CODE_OK) {
        String content = http.getString();
        Serial.printf("[HTTP] GET content: %s\n", content.c_str());
        return content;
    }

  } else {
      Serial.printf("[HTTP] GET failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
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
