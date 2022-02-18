#ifndef SERVE
#define SERVE

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "home.h"
#include "card_1.h"
#include "card_0.h"
#include "card_2.h"

void serve(AsyncWebServer *server);
#endif