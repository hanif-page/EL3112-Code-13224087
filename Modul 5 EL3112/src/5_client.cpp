// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ESP32_SERVER_Hanif";
const char* password = "123123123";
const char* serverUrl = "http://192.168.4.1/update"; // Soft Access Point ESP32 Default IP

const int swPins[4] = {4, 5, 18, 19}; 
int lastState[4] = {-1, -1, -1, -1};

void setup() {
    for(int i=0; i<4; i++) pinMode(swPins[i], INPUT_PULLUP);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) { delay(500); }
}

void loop() {
    // Variasi Data (Tabel 9):
    // 1-5. Konfigurasi saklar sesuai tabel.
    // 6. Menyala Semua (ON ON ON ON).
    // 7. Klien Mati -> Matikan daya ESP32 Client, perhatikan kondisi akhir LED di Server.
    
    bool changed = false;
    String url = serverUrl;
    url += "?";
    
    for(int i=0; i<4; i++) {
        int state = !digitalRead(swPins[i]); // Active low
        if(state != lastState[i]) changed = true;
        lastState[i] = state;
        url += "led" + String(i+1) + "=" + String(state);
        if(i < 3) url += "&"; // Only add '&' between arguments, not at the end
    }
    
    if(changed && WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(url);
        http.GET();
        http.end();
    }
    delay(100);
}