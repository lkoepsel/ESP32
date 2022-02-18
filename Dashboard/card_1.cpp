#include "card_1.h"

extern AsyncWebServer server();

// Card 1 processor()
// Replaces placeholder with LED state value 
String proc_c1(const String& var){
    String ledState1;

    Serial.println(var);

    // Card 1 Processing
    if(var == "STATE1"){
        if(digitalRead(LED1)){
          ledState1 = "ON";
        }
        else{
          ledState1 = "OFF";
        }
        Serial.print(ledState1);
        return ledState1;
    }

    return String();
}


void card_1(AsyncWebServer *server) {

    // Route to set GPIO to HIGH
    server->on("/on1", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED1, HIGH);    
    request->send(SPIFFS, "/index.html", String(), false, proc_c1);
    });

    // Route to set GPIO to LOW
    server->on("/off1", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED1, LOW);    
    request->send(SPIFFS, "/index.html", String(), false, proc_c1);
    });

}