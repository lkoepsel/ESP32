#include "card_2.h"

extern AsyncWebServer server();

// Card 2: setting Slider/PWM properties
const char* slider_input = "value";
String sliderValue = "0";

// Card 2: processor()
// Replaces placeholder and sends slider value to PWM
String proc_c2(const String& var){

    // Card 2 Processing
    if (var == "SLIDERVALUE"){
      return sliderValue;
    }
    return String();
}


void card_2(AsyncWebServer *server) {

    // Send a GET request to /slider?value=<inputMessage>
    server->on("/slider", HTTP_GET, [] (AsyncWebServerRequest *request) {
      String inputMessage;
      // GET input1 value on /slider?value=<inputMessage>
      if (request->hasParam(slider_input)) {
        inputMessage = request->getParam(slider_input)->value();
        sliderValue = inputMessage;
        ledcWrite(LEDCHANNEL, sliderValue.toInt());
      }
      else {
        inputMessage = "No message sent";
      }
      Serial.println(inputMessage);
      request->send(200, "text/plain", "OK");
    });
}