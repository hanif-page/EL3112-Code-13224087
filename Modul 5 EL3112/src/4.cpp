// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Hanif";
const char* password = "wifigratis";
const char* serverUrl = "http://172.20.10.3:8000/post"; // ip a (then look for wl and inet) or hostname -I

const int btnPins[4] = {4, 5, 18, 19};
volatile bool btnPressed = false;

void IRAM_ATTR isr_button() {
    btnPressed = true; // flag for Interrupt
}

void setup() {
    Serial.begin(115200);
    for(int i=0; i<4; i++) {
        pinMode(btnPins[i], INPUT_PULLUP);
        attachInterrupt(btnPins[i], isr_button, FALLING);
    }
    
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) { delay(500); }
}

void loop() {
    // Variasi Data (Tabel 8):
    // 1. ON OFF OFF OFF
    // 2. OFF ON OFF OFF
    // 3. OFF OFF ON OFF
    // 4. OFF OFF OFF ON
    // Catat Nilai JSON dan Kode Respons (misal 200 OK) ke dalam tabel.
    
    if (btnPressed) {
        btnPressed = false;
        if (WiFi.status() == WL_CONNECTED) {
            HTTPClient http;
            http.begin(serverUrl);
            http.addHeader("Content-Type", "application/json");
            
            // use ! sign assuming the Button is Active-Low
            String json = "{ \"btn1\": " + String(!digitalRead(btnPins[0])) + 
                            ", \"btn2\": " + String(!digitalRead(btnPins[1])) + 
                            ", \"btn3\": " + String(!digitalRead(btnPins[2])) + 
                            ", \"btn4\": " + String(!digitalRead(btnPins[3])) + " }";
            
            int httpResponseCode = http.POST(json);
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            http.end();
        }
        delay(50); // Debounce sederhana
    }
}