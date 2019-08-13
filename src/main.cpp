#include <Arduino.h> //? Main Arduino Lib Framework
#include <WiFi.h>    //? Connect WiFi

//* Prototype Function
void wifiSetup();

//* Params
#define WiFi_STA_USERNAME "DrZin"       //? WiFi UserName
#define WiFi_STA_PASSWORD "0985626152a" //? WiFi Password
#define Intervals 100                   //? Global Interval Time

unsigned long long previousMillis_WiFi = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  wifiSetup();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

void wifiSetup()
{
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WiFi_STA_USERNAME);

  //* WiFi Connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(WiFi_STA_USERNAME, WiFi_STA_PASSWORD);

  Serial.print("Status: [");
  while (WiFi.status() != WL_CONNECTED)
  {
    //* Time Loop Uss Millis
    unsigned long currentMillis = millis(); //? Store Current time
    if (currentMillis - previousMillis_WiFi > Intervals)
    {
      previousMillis_WiFi = currentMillis; //? Save Current time
      Serial.print("=");
    }
  }
  Serial.println("] 100%");

  Serial.println("--- WiFi Connected ---");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}