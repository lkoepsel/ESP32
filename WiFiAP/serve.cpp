#include "serve.h"

extern WiFiServer server();

void blink3() {
    for (int i=0;i<3;++i) {
        digitalWrite(LED1, HIGH);
        delay(200);
        digitalWrite(LED1, LOW);
        delay(200);
    }
}


void execute_cmd(int cmd) {
    Serial.print("Command is ");
    Serial.println(cmd);
    switch(cmd) {
        case 11:
            digitalWrite(LED1, HIGH);               // GET /H turns the LED on
            break;
        case 21:
            digitalWrite(LED2, HIGH);               // GET /H turns the LED on
            break;
        case 31:
            digitalWrite(LED3, HIGH);               // GET /H turns the LED on
            break;
        case 10:
            digitalWrite(LED1, LOW);               // GET /H turns the LED on
            break;
        case 20:
            digitalWrite(LED2, LOW);               // GET /H turns the LED on
            break;
        case 30:
            digitalWrite(LED3, LOW);               // GET /H turns the LED on
            break;
        default:
            blink3();
    }
} 


void serve(WiFiServer *server) {
  WiFiClient client = server->available();  // listen for incoming clients
  if (client) {                             // if you get a client,
    int cmd_found = 0;
    String cmd;

    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                 // make a String to hold incoming data from the client
    while (client.connected()) {             // loop while the client's connected
        if (client.available()) {            // if there's bytes to read from the client,
            char c = client.read();          // read a byte, then
            // Serial.write(c);                 // print it out the serial monitor
            if (c == '\n') {                 // if the byte is a newline character

                // if the current line is blank, you got two newline characters in a row.
                // that's the end of the client HTTP request, so send a response:
                if (currentLine.length() == 0) {
                    serve_header(&client);
                    serve_home(&client);
                // break out of the while loop:
                break;
            } 
            else {    // if you got a newline, then clear currentLine:
                currentLine = "";
            }
        } 
        else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L"
        // if so, set flag and save command then process once client completes
        if (currentLine.startsWith("GET /")) {
            cmd_found = 1;
            cmd = currentLine;
        }
      }
    }
    // if a command is found ("/nn") then execute based on integer value
    if (cmd_found) {
        String s_cmd = cmd.substring(5, 7);
        int i_cmd = s_cmd.toInt();
        execute_cmd(i_cmd);
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}