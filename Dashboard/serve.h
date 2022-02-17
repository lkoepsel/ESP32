#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>


#define WEB_PORT 80
#define SERIAL_BAUD 921600
#define LED1 LED_BUILTIN
#define LED2 32
#define LED3 33

String processor(const String& var);

void serve(AsyncWebServer *server);
