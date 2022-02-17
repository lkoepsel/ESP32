/*
  Dashboard.ino creates a WiFi access point and starts the Asynch Server
*/

#include <WiFi.h>
#include <WiFiAP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "arduino_secrets.h"
#include "serve.h"

// Set these to your desired credentials.
const char *ssid = SECRET_AP;
const char *password = SECRET_PASS;

//**** WiFiServer server(WEB_PORT);
// Create AsyncWebServer object
AsyncWebServer server(WEB_PORT);

void setup() {
    // Serial port for debugging purposes
    Serial.begin(SERIAL_BAUD);

    // Initialize SPIFFS
    if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
    }
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    Serial.begin(921600);
    Serial.println();
    Serial.println("Configuring access point...");

    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    Serial.println("Server started");
    serve(&server);
    server.begin();

}

void loop() {

}