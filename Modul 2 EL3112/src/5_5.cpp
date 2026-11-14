// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>
#include <driver/dac.h>

#define DAC_PIN 25 // GPIO 25

// Pilih Metode Library berdasarkan pengambilan data:
// 1: dacWrite()
// 2: dac_output_voltage()
#define METHOD 2

void setup() {
    Serial.begin(115200);
    if (METHOD == 2) {
        dac_output_enable(DAC_CHANNEL_1);
    }
    Serial.println("Percobaan 5.5: Kecepatan Konversi DAC (Alat Ukur)");
}

void loop() {
#if METHOD == 1
    // Pengujian menggunakan dacWrite()
    dacWrite(DAC_PIN, 0);
    dacWrite(DAC_PIN, 255);
#elif METHOD == 2
    // Pengujian menggunakan dac_output_voltage()
    dac_output_voltage(DAC_CHANNEL_1, 0);
    dac_output_voltage(DAC_CHANNEL_1, 255);
#endif
}

// #include <Arduino.h>
// #include <driver/dac.h>
// const long jumlahLoop = 50000;

// void setup() {
//   Serial.begin(115200);
//   dac_output_enable(DAC_CHANNEL_1); //pin 25
//   delay(1000);
// }

// void loop() {
//   unsigned long waktuMulai = micros();
  
//   for(long i = 0; i < jumlahLoop; i++) {
//     dac_output_voltage(DAC_CHANNEL_1, 255);
//     dac_output_voltage(DAC_CHANNEL_1, 0);
//   }
  
//   unsigned long waktuSelesai = micros();
  
//   float periode_T = (float)(waktuSelesai - waktuMulai) / jumlahLoop;
//   float waktuKonversi = periode_T / 2.0;
  
//   Serial.print("Periode Sinyal (T): ");
//   Serial.print(periode_T, 2);
//   Serial.println(" us");
//   Serial.print("Waktu Konversi (T/2): ");
//   Serial.print(waktuKonversi, 2);
//   Serial.println(" us\n");
  
//   delay(100);
// }