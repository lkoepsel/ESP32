# ESP32
Exploring the ESP32 SoC using the Arduino Framework, Random Nerd Tutorials and the ESP32 examples from Espressif.
## Code
### blink:
* basic blink program used to test tool chain
### WiFi_AP:
* a copy of [this example](https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino), i wanted to start with a known, working prototype
### WiFiAP:
* a modular version of WiFi_AP to help me to understand the various components:
	* WiFiAP.ino - main file to setup the example
	* serve.h/cpp - server code 
	* serve_pages.h/cpp - web pages to be displayed
### RNT_WebManager:
* [RNT_WebManager](https://randomnerdtutorials.com/esp32-wi-fi-manager-asyncwebserver/), original to be modified similar to WiFiAP. I like RNT's approach to using files to serve index.html and style.css, however the WebManager aspect is overkill for what I need. I'll retain the Data file and re-make the .ino file.
## Webserver:
A new version of WiFiAP, which uses the ESP32 as an access point while using SPIFFS files as the basis of the website. I used SVG icons instead of Fontawesome as I won't have a connection to the Internet and the SVG fonts take a very little space.
## Boards
* [Adafruit Feather ESP32](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/overview)
* [Dev Board from DOIT] - Identifies as a NodeMCU-32S

## Sources
* [arduino-esp32 examples](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples)
* [ESPAsyncWebServer on Github](https://github.com/me-no-dev/ESPAsyncWebServer)
* [Random Nerd Tutorial ESP32 Web Manager](https://randomnerdtutorials.com/esp32-wi-fi-manager-asyncwebserver/)
