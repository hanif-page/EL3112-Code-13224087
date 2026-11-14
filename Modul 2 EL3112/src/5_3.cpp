// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>

#define ADC_PIN 34
#define TOGGLE_PIN 18 // Pin output terhubung ke Osiloskop / Frequency Counter

// Ubah resolusi ke 9 atau 12 bit sesuai data
const int RESOLUTION_BITS = 12;

void setup() {
    Serial.begin(115200);
    pinMode(TOGGLE_PIN, OUTPUT);
    analogReadResolution(RESOLUTION_BITS);
    Serial.println("Percobaan 5.3: Kecepatan Konversi ADC (Alat Ukur)");
}

void loop() {
    analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, HIGH);
    analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, LOW);

        analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, HIGH);
    analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, LOW);

        analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, HIGH);
    analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, LOW);

        analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, HIGH);
    analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, LOW);

        analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, HIGH);
    analogRead(ADC_PIN);
    digitalWrite(TOGGLE_PIN, LOW);
}