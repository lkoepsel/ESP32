#ifndef CARD_1
#define CARD_1

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

// ON1/OFF1 Properties
#define LED1 32

// Card 1 processor
String proc_c1(const String& var);

void card_1(AsyncWebServer *server);
#endif
