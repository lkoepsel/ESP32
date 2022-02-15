# ESP32 - Exploring the ESP32 SoC using the Arduino Framework
## Code
### blink - basic blink program used to test tool chain
### WiFi_AP - a copy of [this example](https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino), i wanted to start with a known, working prototype
### WiFiAP - a modular version of WiFi_AP to help me to understand the various components:
* WiFiAP.ino - main file to setup the example
* serve.h/cpp - server code 
* serve_pages.h/cpp - web pages to be displayed
### [RNT_WebManager](https://randomnerdtutorials.com/esp32-wi-fi-manager-asyncwebserver/) - original to be modified similar to WiFiAP. I like RNT's approach to using files to serve index.html and style.css, and as they note, the main file is a bit large and complicated. I'll create a new version which is modular for easier development and maintenence.
### [Dashboard] - modular approach to RNT_Webmanager.

## Sources
* [arduino-esp32 examples](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples)
* [ESPAsyncWebServer on Github](https://github.com/me-no-dev/ESPAsyncWebServer)
* [Random Nerd Tutorial ESP32 Web Manager](https://randomnerdtutorials.com/esp32-wi-fi-manager-asyncwebserver/)
