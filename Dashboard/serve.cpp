#include "serve.h"

extern AsyncWebServer server();

// Replaces placeholder with LED state value
String processor(const String& var){
    String ledState;

    Serial.println(var);
    if(var == "STATE"){
    if(digitalRead(LED2)){
      ledState = "ON";
    }
    else{
      ledState = "OFF";
    }
    Serial.print(ledState);
    return ledState;
    }
    return String();
}


void serve(AsyncWebServer *server) {
    // Route for root / web page
    server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    // Route to load style.css file
    server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
    });

    // Route to load lightbulb.svg file
    server->on("/lightbulb.svg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/lightbulb.svg", "image/svg+xml");
    });

    // Route to load switch-closed.svg file
    server->on("/switch-closed.svg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/switch-closed.svg", "image/svg+xml");
    });

    // Route to load switch-open.svg file
    server->on("/switch-open.svg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/switch-open.svg", "image/svg+xml");
    });

    // Route to set GPIO to HIGH
    server->on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED2, HIGH);    
    request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    // Route to set GPIO to LOW
    server->on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED2, LOW);    
    request->send(SPIFFS, "/index.html", String(), false, processor);
    });
}