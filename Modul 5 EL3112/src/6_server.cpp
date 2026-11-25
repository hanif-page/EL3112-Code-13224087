// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "LATENCY_Hanif";
const char* password = "123123";
WebServer server(80);

const int ledOut = 2; // Ke Osiloskop (Sinyal Keluar)

void handlePulse() {
    // Ambil millis() untuk perbandingan software (Tabel 11)
    long timestamp_client = server.arg("t").toInt();
    long latency_software = millis() - timestamp_client;
    
    digitalWrite(ledOut, HIGH);
    delay(10); // Lebar pulsa
    digitalWrite(ledOut, LOW);
    
    server.send(200, "text/plain", String(latency_software));
}

void setup() {
    pinMode(ledOut, OUTPUT);
    WiFi.softAP(ssid, password);
    server.on("/pulse", handlePulse);
    server.begin();
}

void loop() {
    server.handleClient();
}