#include <WiFi.h>
#include <WiFiClient.h>
#include "serve_pages.h"


#define WEB_PORT 80
#define LED1 LED_BUILTIN
#define LED2 32
#define LED3 33

void serve(WiFiServer *server);
