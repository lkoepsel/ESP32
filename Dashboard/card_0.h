#ifndef CARD_0
#define CARD_0

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

// ON0/OFF0 Properties
#define LED0 LED_BUILTIN

// Card 0 processor
String proc_c0(const String& var);

void card_0(AsyncWebServer *server);
#endif
