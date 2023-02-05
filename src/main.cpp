//=========================
//SIMULATION ODAC CI: DA DC
//=========================

#include <Arduino.h>
#include "WiFi.h"
#include "env.h"  //you will change for env1.h env.h is personal
 
const char* ssid     = SSID_WIFI;
const char* password = PASSWORD_WIFI;

//Variables================= 
WiFiServer wifiServer(80);
int relayPin = 5;
float randNumber1=0.0;
float randNumber2=0.0;
char buffer[20];

 //PROCES COMAND===========================
void processReceivedValue(char command){
 
  if(command == '1'){ digitalWrite(relayPin, HIGH); }
  else if(command == '0'){ digitalWrite(relayPin, LOW);}
 
   return;
}

//===========SETUP========================
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
 
//=============LOOP=============================
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {

      //==========For Write in wifi==================
       client.flush(); //2018-11-10 BB: Tr
       buffer[0]='\0';  //Null character - clear buffer
        randNumber1 = 3.0+random(50,500)/500.0;  // Issue not the same div x 500 than 500.0 (if float)
        randNumber2 = 3.0+random(20,600)/600.0;
        sprintf( buffer, "DA%4.3f DC%4.3f%s" ,randNumber1 ,randNumber2 ,"\n\r");  //MAGIC LOL
        //sprintf( buffer, "%s %d %s %s %s", numero, randNumber1, "\t",numero,randNumber2,"\n\r" );
        int lenbuffer=0;
        lenbuffer = sizeof (buffer);
        //lenbuffer = sizeof (buffer) / sizeof (buffer[0]);
        //:write(const uint8_t *buf, size_t size)
        client.write((uint8_t*)buffer, lenbuffer);
        //client.flush(); //2018-11-10 BB: Tr
        delay(10);
        Serial.write(buffer);


        //==========For Read wifi=================
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


