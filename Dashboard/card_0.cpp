#include "card_0.h"

extern AsyncWebServer server();

// Card 0 processor()
// Replaces placeholder with LED state value 
String proc_c0(const String& var){
    String ledState0;

    Serial.println(var);

    // Card 0 Processing
    if(var == "STATE0"){
        if(digitalRead(LED0)){
          ledState0 = "ON";
        }
        else{
          ledState0 = "OFF";
        }
        Serial.print(ledState0);
        return ledState0;
    }

    return String();
}


void card_0(AsyncWebServer *server) {

    // Route to set GPIO to HIGH
    server->on("/on0", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED0, HIGH);    
    request->send(SPIFFS, "/index.html", String(), false, proc_c0);
    });

    // Route to set GPIO to LOW
    server->on("/off0", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED0, LOW);    
    request->send(SPIFFS, "/index.html", String(), false, proc_c0);
    });

}