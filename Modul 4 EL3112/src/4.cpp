// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// DEKLARASI PIN ST7789 (Varian tanpa pin CS)
#define TFT_CS    -1  // Set -1 karena modul tidak memiliki pin CS
#define TFT_RST   17  // Hubungkan ke pin RES
#define TFT_DC    16  // Hubungkan ke pin DC
#define TFT_MOSI  23  // Hubungkan ke pin SDA (MOSI)
#define TFT_SCLK  18  // Hubungkan ke pin SCL (SCK)

// UBAH FREKUENSI SPI DI SINI UNTUK MENGISI TABEL 6
// Variasi: 20000000 (20M), 40000000 (40M), 80000000 (80M), Maksimum
uint32_t SPI_FREQ = 160000000; 

// Gunakan konstruktor Hardware SPI (&SPI) agar lebih cepat dan stabil
Adafruit_ST7789 tft = Adafruit_ST7789(&SPI, TFT_CS, TFT_DC, TFT_RST);

#define IMG_WIDTH  240
#define IMG_HEIGHT 240
uint8_t checkerboard_bitmap[(IMG_WIDTH * IMG_HEIGHT) / 8];

void generateCheckerboard() {
  int bytesPerRow = IMG_WIDTH / 8;
  for (int y = 0; y < IMG_HEIGHT; y++) {
    bool invertRow = (y / 8) % 2 == 1; 
    for (int xByte = 0; xByte < bytesPerRow; xByte++) {
      bool isWhiteBlock = (xByte % 2 == 0) ^ invertRow;
      checkerboard_bitmap[y * bytesPerRow + xByte] = isWhiteBlock ? 0xFF : 0x00;
    }
  }
}

void setup() {
  Serial.begin(115200);
  generateCheckerboard();

  // Inisialisasi Hardware SPI pada pin default VSPI (SCK=18, MISO=-1, MOSI=23, SS=-1)
  SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);

  // WAJIB menggunakan SPI_MODE3 untuk modul ST7789 tanpa pin CS!
  tft.init(240, 240, SPI_MODE3); 
  
  // Set kecepatan clock SPI sesuai variasi pengujian
  tft.setSPISpeed(SPI_FREQ);
  tft.fillScreen(ST77XX_BLACK);

  // 1. PENGUKURAN WAKTU TEKS (Untuk Gambar 16 & Tabel 6)
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  
  uint32_t startTimeText = micros();
  tft.println("Nama: Muhammad Ammar Hanif"); 
  tft.println("NIM: 13224087");  
  uint32_t endTimeText = micros();
  
  Serial.print("Frekuensi (Hz): ");
  Serial.println(SPI_FREQ);
  Serial.print("Waktu Tampil Teks (us): ");
  Serial.println(endTimeText - startTimeText);

  delay(5000); 
  tft.fillScreen(ST77XX_BLACK);

  // 2. PENGUKURAN WAKTU GAMBAR FULL CHECKERBOARD (Untuk Gambar 17 & Tabel 6)
  uint32_t startTimeImg = micros();
  tft.drawBitmap(0, 0, checkerboard_bitmap, IMG_WIDTH, IMG_HEIGHT, ST77XX_WHITE, ST77XX_BLACK); 
  uint32_t endTimeImg = micros();
  
  Serial.print("Waktu Tampil Gambar Full Screen (us): ");
  Serial.println(endTimeImg - startTimeImg);
}

void loop() {
  // 3. GENERASI SINYAL KONTINU (Untuk Gambar 14: Probe di pin SCL=18 dan SDA=23)
  // Tanpa pin CS, cukup gunakan SPI_MODE3 untuk mengirim dummy byte 0xAA
  SPI.beginTransaction(SPISettings(SPI_FREQ, MSBFIRST, SPI_MODE3));
  SPI.transfer(0xAA); 
  SPI.endTransaction();
  
  delay(5);
}