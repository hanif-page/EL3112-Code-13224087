// Muhammad Ammar Hanif (13224087)

#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    Serial.println("Scanning WiFi...");
}

void loop() {
    // Data Variation: Run this code in 3 different time, which are:
    // 1. Beginning of the Lab Session
    // 2. During the Lab Session
    // 3. End of the Lab Session

    // Tabel 1 Data: SSID (Service Set Identifier), RSSI (Receive Signal Strengh Indicator), Channel, dan Encryption Type.
    
    int n = WiFi.scanNetworks();
    if (n == 0) {
        Serial.println("No Network Found.");
    } else {
        Serial.print(n);
        Serial.println("Network Found:");
        for (int i = 0; i < n; ++i) {
        Serial.printf("%d: %s (%d) Channel:%d Encryption:%d\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.channel(i), WiFi.encryptionType(i));
        delay(10);
        }
        Serial.printf("\n");
    }
    delay(10000); // 10s delay
}