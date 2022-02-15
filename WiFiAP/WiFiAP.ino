/*
  WiFiAP.ino creates a WiFi access point.
*/

#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include "arduino_secrets.h"
#include "serve.h"

// Set these to your desired credentials.
const char *ssid = SECRET_AP;
const char *password = SECRET_PASS;

WiFiServer server(WEB_PORT);

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(921600);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void loop() {
  serve(&server);
}