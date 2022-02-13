#include "serve_pages.h"

void serve_header(WiFiClient *client) {
    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
    // and a content-type so the client knows what's coming, then a blank line:
    client->println("HTTP/1.1 200 OK");
    client->println("Content-type:text/html");
    client->println();
}

void serve_home(WiFiClient *client) {
    // the content of the HTTP response follows the header:
    client->print("<!DOCTYPE html>");
    client->print("<html>");
    client->print("<head>");
    client->print("</head>");
    client->print("<style>");
    client->print(" .content {max-width: 200px; margin: auto;}");
    client->print(" .on {line-height: 5; background-color: green;}");
    client->print(" .off {line-height: 5; background-color: red;}");
    client->print("</style>");
    client->print("<body>");
    client->print("<div class=\"content\">");
    client->print("<h1>ESP32</h1>");
    client->print("<h2>Feather ESP32</h2>");
    client->print("<button class=\"on\" type=\"button\"> <a href=\"/H\">ON</a> </button><br>");
    // client->print("Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
    client->print("<button class=\"off\" type=\"button\"> <a href=\"/L\">OFF</a> </button><br>");
    // client->print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");
    client->print("</div");
    client->print("</body>");
    client->print("</html>");

    // The HTTP response ends with another blank line:
    client->println();
}