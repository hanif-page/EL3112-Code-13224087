// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// UBAH PIN GPIO I2C UNTUK VARIASI 1 DAN 2 (Tabel 1)
#define I2C_SDA 4 
#define I2C_SCL 5 
// Kombinasi alternatif Variasi 2 => SDA = 4 dan SCL = 5

// UBAH FREKUENSI UNTUK PENGUKURAN WAKTU (Tabel 2)
// Opsi: 100000 (100k), 400000 (400k), 1000000 (1M), 3400000 (Maksimum)
uint32_t I2C_FREQ = 5000000; 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Contoh bitmap sederhana untuk tes render gambar
const unsigned char epd_bitmap_test [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  // PROGRAM I2C SCANNER (Cukup dijalankan sekali saat boot)
  Serial.println("Scanning I2C...");
  for(byte address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Perangkat I2C ditemukan pada alamat: 0x");
      Serial.println(address, HEX);
    }
  }

  // Inisialisasi OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Sesuaikan 0x3C dengan hasil scan alamat
    Serial.println(F("OLED gagal diinisialisasi"));
    for(;;);
  }

  // Terapkan frekuensi I2C yang diinginkan setelah display.begin()
  // (Penting karena library Adafruit terkadang mereset clock ke 400kHz saat begin)
  Wire.setClock(I2C_FREQ);
}

void loop() {
  // 1. TAMPILKAN TEKS & UKUR WAKTUNYA
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Nama: Muhammad Ammar Hanif");
  display.println("NIM: 13224087");
  
  uint32_t startTimeText = micros();
  display.display();
  uint32_t endTimeText = micros();
  
  Serial.print("Waktu Tampil Teks (us): ");
  Serial.println(endTimeText - startTimeText);

  delay(5000); // Tahan tampilan teks selama 5 detik

  // 2. TAMPILKAN GAMBAR & UKUR WAKTUNYA
  display.clearDisplay();
  display.drawBitmap(0, 0, epd_bitmap_test, 16, 8, WHITE); // Render bitmap 16x8 piksel
  
  uint32_t startTimeImg = micros();
  display.display();
  uint32_t endTimeImg = micros();
  
  Serial.print("Waktu Tampil Gambar (us): ");
  Serial.println(endTimeImg - startTimeImg);
  Serial.println("---------------------------------");

  delay(5000); // Tahan tampilan gambar selama 5 detik sebelum mengulang
}