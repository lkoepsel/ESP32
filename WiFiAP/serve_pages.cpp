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
    client->print(" .content {max-width: 400px; margin: auto;}");
    client->print(" .on {font-size: 20px; padding: 10px 22px; color: white; background-color: #33cc33;}");
    client->print(" .off {font-size: 20px; padding: 10px 22px; color: white; background-color: #cc3333;}");
    client->print("</style>");
    client->print("<body>");
    client->print("<div class=\"content\">");
    client->print("<h1>ESP32</h1>");
    client->print("<h2>Feather ESP32</h2>");
    client->print("<a href=\"/11\"><button class=\"on\">1 ON</button></a>");
    client->print("<a href=\"/10\"><button class=\"off\">1 OFF</button></a><br>");
    client->print("<a href=\"/21\"><button class=\"on\">2 ON</button></a>");
    client->print("<a href=\"/20\"><button class=\"off\">2 OFF</button></a><br>");
    client->print("<a href=\"/31\"><button class=\"on\">3 ON</button></a>");
    client->print("<a href=\"/30\"><button class=\"off\">3 OFF</button></a>");
    client->print("</div");
    client->print("</body>");
    client->print("</html>");

    // The HTTP response ends with another blank line:
    client->println();
}