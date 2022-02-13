#include <WiFi.h>
#include <WiFiClient.h>
#include "serve_pages.h"


#define WEB_PORT 80

void serve(WiFiServer *server);
