// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>

// ADC1: GPIO 34 | ADC2: GPIO 4
#define ADC_PIN 4 

// variable Definition
// Resolusi: 9 atau 12 bit
// Attenuation: ADC_0db (0 dB) atau ADC_11db (11 dB)
const int RESOLUTION_BITS = 12; 
const adc_attenuation_t ATTENUATION = ADC_11db; 

void setup() {
    Serial.begin(115200);

    // Resolution and Attenuation configuration
    analogReadResolution(RESOLUTION_BITS);
    analogSetPinAttenuation(ADC_PIN, ATTENUATION);

    Serial.println("Percobaan 5.1: Mengukur Fungsi Transfer ADC\n");

    // commented it if needed!
    delay(1000);
}

void loop() {
    int rawADC = analogRead(ADC_PIN);

    Serial.print("Nilai Output Integer ADC: ");
    Serial.println(rawADC);

    // delay between read
    delay(1000);
}