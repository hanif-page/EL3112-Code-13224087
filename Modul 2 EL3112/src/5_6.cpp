// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>
#include <driver/dac.h>

#define DAC_PIN 25
const uint32_t TOTAL_SAMPLES = 100000;

// don't forget to click the EN/Reset button! (otherwise the output won't come out after uploaded)
void setup() {
    Serial.begin(115200);
    delay(1000);
    dac_output_enable(DAC_CHANNEL_1);

    Serial.println("Percobaan 5.6: Kecepatan Konversi DAC (Software)");

    // 1. Pengujian dacWrite()
    uint32_t startTime = micros();
    for (uint32_t i = 0; i < TOTAL_SAMPLES; i++) {
        dacWrite(DAC_PIN, (i % 2) * 255);
    }
    uint32_t timeDacWrite = micros() - startTime;
    float avgDacWrite = (float)timeDacWrite / TOTAL_SAMPLES;

    // 2. Pengujian dac_output_voltage()
    startTime = micros();
    for (uint32_t i = 0; i < TOTAL_SAMPLES; i++) {
        dac_output_voltage(DAC_CHANNEL_1, (i % 2) * 255);
    }
    uint32_t timeIdf = micros() - startTime;
    float avgIdf = (float)timeIdf / TOTAL_SAMPLES;

    // Menampilkan Perbandingan
    Serial.println("1. Method dacWrite():");
    Serial.print("Avg waktu konversi: "); Serial.print(avgDacWrite, 3); Serial.println(" us");
    Serial.print("Frekuensi: "); Serial.print(1000000.0 / avgDacWrite, 2); Serial.println(" Hz");

    Serial.println("2. Method dac_output_voltage():");
    Serial.print("Avg waktu konversi: "); Serial.print(avgIdf, 3); Serial.println(" us");
    Serial.print("Frekuensi: "); Serial.print(1000000.0 / avgIdf, 2); Serial.println(" Hz");
}

void loop() {
  // Kosong
}