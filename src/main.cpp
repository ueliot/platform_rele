

#include <Arduino.h>

#include "WiFi.h"
 
const char* ssid     = "xxx";
const char* password = "xxx";
 
WiFiServer wifiServer(80);
 
int relayPin = 5;
 
void processReceivedValue(char command){
 
  if(command == '1'){ digitalWrite(relayPin, HIGH); }
  else if(command == '0'){ digitalWrite(relayPin, LOW);}
 
   return;
}
 
void setup() {
 
  Serial.begin(115200);
 
  delay(1000);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
 
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}
 
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        processReceivedValue(c);
        Serial.write(c);
      }
 
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }
}
