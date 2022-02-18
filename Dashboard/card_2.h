#ifndef CARD_2
#define CARD_2

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

// setting Slider/PWM properties
#define LED2 33
#define FREQUENCY 5000
#define LEDCHANNEL 0
#define RESOLUTION 8
extern const char* slider_input;
extern String sliderValue;

// Card 1 and Card 2 processor
String proc_c2(const String& var);

void card_2(AsyncWebServer *server);
#endif
