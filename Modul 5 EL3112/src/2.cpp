// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "13224087"; 
const char* password = "123123123";

WebServer server(80);
const int ledPin = 21; // Internal ESP32 LED

void handleRoot() {
    server.send(200, "text/html", "<h1>Name: Muhammad Ammar Hanif</h1><h2>NIM: 13224087</h2><a href='/led'>Kontrol LED</a>");
}

void handleLED() {
    // Variasi Data (Tabel 5): Uji coba form HTML sebanyak 3 siklus.
    // 1. Klik ON -> Catat URL (biasanya /led?state=on), amati LED.
    // 2. Klik OFF -> Catat URL (/led?state=off), amati LED.
    // Masukkan hasilnya ke Tabel 5. Lakukan PING ke IP AP untuk Tabel 4.
    
    if (server.hasArg("state")) {
        String state = server.arg("state");
        if (state == "on") {
            Serial.println("ON\n");
            digitalWrite(ledPin, HIGH);
        }
        else if (state == "off") {
            Serial.println("OFF\n");
            digitalWrite(ledPin, LOW);
        }
    }
    
    String html = "<h1>Kontrol LED</h1>";
    html += "<form action='/led' method='GET'>";
    html += "<button name='state' value='on'>ON</button>";
    html += "<button name='state' value='off'>OFF</button>";
    html += "</form><br><a href='/'>Kembali</a>";
    server.send(200, "text/html", html);
}

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    
    WiFi.softAP(ssid, password);
    Serial.print("IP Address Access Point: ");
    Serial.println(WiFi.softAPIP()); // Gunakan IP ini untuk di-ping pada Tabel 4
    
    server.on("/", handleRoot);
    server.on("/led", handleLED);
    server.begin();
}

void loop() {
    server.handleClient();
}