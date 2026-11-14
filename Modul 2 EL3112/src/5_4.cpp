#include <Arduino.h>

#define ADC_PIN 34
// Ubah resolusi ke 9 atau 12 bit sesuai Tabel 3
const int RESOLUTION_BITS = 12; 
const uint32_t TOTAL_SAMPLES = 100000;

// don't forget to click the EN/Reset button! (otherwise the output won't come out after uploaded)
void setup() {
    Serial.begin(115200);
    delay(1000);
    analogReadResolution(RESOLUTION_BITS);

    Serial.println("Percobaan 5.4: Kecepatan Konversi ADC (Software)");
    Serial.print("Resolusi: "); Serial.print(RESOLUTION_BITS); Serial.println(" bit");
    Serial.println(" ");

    volatile int dummyRead = 0; // Mencegah optimasi compiler
    uint32_t startTime = micros();

    for (uint32_t i = 0; i < TOTAL_SAMPLES; i++) {
        dummyRead = analogRead(ADC_PIN);
    }

    uint32_t endTime = micros();
    uint32_t totalTimeUs = endTime - startTime;
    float avgTimeUs = (float)totalTimeUs / TOTAL_SAMPLES;
    float samplingRateHz = 1000000.0 / avgTimeUs;

    Serial.print("Total Waktu: "); Serial.print(totalTimeUs / 1000.0); Serial.println(" ms");
    Serial.print("Avg Waktu per Konversi: "); Serial.print(avgTimeUs, 3); Serial.println(" us");
    Serial.print("Kecepatan Sampling: "); Serial.print(samplingRateHz, 2); Serial.println(" Hz");
}

void loop() {
  // Kosong
}