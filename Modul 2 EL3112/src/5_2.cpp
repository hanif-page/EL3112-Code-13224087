// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>

#define DAC_PIN 25 // GPIO 25 (DAC1 25, DAC2 26)

void setup() {
    Serial.begin(115200);
    Serial.println("Percobaan 5.2: Mengukur Fungsi Transfer DAC\n");
}

void loop() {
    // Sweeping nilai input 8-bit DAC (0 hingga 255) secara bertahap
    for (int val = 0; val <= 255; val += 25) {
        dacWrite(DAC_PIN, val);
        Serial.print("Input DAC: ");
        Serial.print(val);
        Serial.println(" | Ukur tegangan pin GPIO 25 menggunakan multimeter!");
        delay(6000);
    }

    // just making sure the 255 value is sweeped too
    dacWrite(DAC_PIN, 255);
    Serial.print("Input DAC: 255");
    Serial.println(" | Ukur tegangan pin GPIO 25 menggunakan multimeter!");
}