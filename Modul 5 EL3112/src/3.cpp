// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Hanif";
const char* password = "wifigratis";

WebServer server(80);
const int potPin = 34; // Pin potensiometer

void handleRoot() {
  server.send(200, "text/html", "<h1>Name: Muhammad Ammar Hanif</h1><h2>NIM: 13224087</h2><a href='/pot'>Read Potensiometer</a>");
}

void handlePot() {
    // Variasi Data (Tabel 7): Putar knob potensiometer 5 kali pada posisi berbeda.
    // Ukur "Tegangan Aktual (V)" dengan multimeter di kaki tengah potensio.
    // Bandingkan dengan "Tegangan yang Terbaca di Web (V)".
    
    int adcValue = analogRead(potPin);
    float voltage = (adcValue / 4095.0) * 3.3; // Asumsi referensi 3.3V
    
    String html = "<h1>Potensiometer Value</h1>";
    html += "<p>Voltage (Web Read): " + String(voltage) + " V</p>";
    html += "<a href='/pot'>Refresh</a> <a href='/'>Return</a>";
    server.send(200, "text/html", html);
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500); Serial.print(".");
    }
    Serial.println("\nIP Address Station: " + WiFi.localIP().toString()); // Ping IP ini untuk Tabel 6
    
    server.on("/", handleRoot);
    server.on("/pot", handlePot);
    server.begin();
}

void loop() {
  server.handleClient();
}