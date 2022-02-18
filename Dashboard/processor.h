#ifndef PROCESSOR
#define PROCESSOR

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "card_0.h"
#include "card_1.h"
#include "card_2.h"

// ON0/OFF0 Properties
// #define LED0 LED_BUILTIN

// Card processor
String processor(const String& var);

#endif
