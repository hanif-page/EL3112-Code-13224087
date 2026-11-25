// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32_SERVER_Hanif"; // create its own Access Point
const char* password = "123123123";
WebServer server(80);

const int ledPins[4] = {12, 14, 27, 26}; // adjust it later...!

void handleUpdate() {
    Serial.println(server.args());
    Serial.println("handleUpdate Triggered!\n");
    for(int i=0; i<4; i++) {
        String argName = "led" + String(i+1);
        Serial.println(argName);
        if(server.hasArg(argName)) {
            digitalWrite(ledPins[i], server.arg(argName).toInt());
            Serial.println(ledPins[i] + server.arg(argName).toInt());
        }
    }
    server.send(200, "text/plain", "OK");
}

void setup() {
    for(int i=0; i<4; i++) pinMode(ledPins[i], OUTPUT);
    WiFi.softAP(ssid, password);
    server.on("/update", handleUpdate);
    server.begin();
}

void loop() {
  server.handleClient();
}