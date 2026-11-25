// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "LATENCY_Hanif";
const char* password = "123123123";
const char* serverUrl = "http://192.168.4.1/pulse";

const int genSinyalPin = 4; // Terhubung ke Generator Sinyal dan Osiloskop (Sinyal Pembanding)

void IRAM_ATTR onPulse() {
    // Variasi Data (Tabel 10 & 11): 
    // - Tabel 10: Bandingkan sinyal pada pin 4 (Client) dan pin 2 (Server) menggunakan Osiloskop.
    // - Tabel 11: Catat balasan HTTP (nilai milidetik) dari server yang di-print via Serial.
}

void setup() {
    Serial.begin(115200);
    pinMode(genSinyalPin, INPUT_PULLDOWN);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) { delay(500); }
}

void loop() {
    if(digitalRead(genSinyalPin) == HIGH) {
        HTTPClient http;
        String url = String(serverUrl) + "?t=" + String(millis());
        http.begin(url);
        int code = http.GET();
        if(code == 200) {
            String software_latency = http.getString();
            Serial.println("Latensi Software (ms): " + software_latency); // Catat untuk Tabel 11
        }
        http.end();
        while(digitalRead(genSinyalPin) == HIGH) { delay(1); } // Tunggu pulsa selesai
    }
}