/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Import required libraries
#include <WiFi.h>
#include <WiFiAP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "arduino_secrets.h"

#define WEB_PORT 80
#define SERIAL_BAUD 921600
#define LED1 LED_BUILTIN
#define LED2 32
#define LED3 33

// Set these to your desired credentials.
const char *ssid = SECRET_AP;
const char *password = SECRET_PASS;

// Set LED GPIO
const int ledPin = LED2;
// Stores LED state
String ledState;

// Create AsyncWebServer object on port 80
AsyncWebServer server(WEB_PORT);

// Replaces placeholder with LED state value
String processor(const String& var){
  Serial.println(var);
  if(var == "STATE"){
    if(digitalRead(ledPin)){
      ledState = "ON";
    }
    else{
      ledState = "OFF";
    }
    Serial.print(ledState);
    return ledState;
  }
  return String();
}
 
void setup(){
  // Serial port for debugging purposes
  Serial.begin(SERIAL_BAUD);
  pinMode(ledPin, OUTPUT);

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  // Route to load lightbulb.svg file
  server.on("/lightbulb.svg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/lightbulb.svg", "image/svg+xml");
  });

  // Route to load switch-closed.svg file
  server.on("/switch-closed.svg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/switch-closed.svg", "image/svg+xml");
  });

  // Route to load switch-open.svg file
  server.on("/switch-open.svg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/switch-open.svg", "image/svg+xml");
  });

  // Route to set GPIO to HIGH
  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, HIGH);    
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to set GPIO to LOW
  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, LOW);    
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}
