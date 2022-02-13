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
    client->print("<body>");
    client->print("<h1>ESP32</h1>");
    client->print("<button type=\"button\"> <a href=\"/H\">ON</a> </button>");
    client->print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");
    client->print("</body>");
    client->print("</html>");

    // The HTTP response ends with another blank line:
    client->println();
}