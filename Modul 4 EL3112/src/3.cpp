// Muhammad Ammar Hanif (13224087)

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

#define I2C_SDA 21
#define I2C_SCL 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA, I2C_SCL);

    // I2C Scanner terintegrasi (Tabel 3)
    for(byte address = 1; address < 127; address++ ) {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0) {
        Serial.print("Alamat ditemukan: 0x");
        Serial.println(address, HEX);
        }
    }

    // Common address value:
    // OLED : 0x3C
    // MPU-6050 : 0x68 or 0x69

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    mpu.begin();
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Print ke Serial untuk pencatatan Tabel 4
  Serial.printf("Accel X:%.2f Y:%.2f Z:%.2f | Gyro X:%.2f Y:%.2f Z:%.2f\n", 
                a.acceleration.x, a.acceleration.y, a.acceleration.z, 
                g.gyro.x, g.gyro.y, g.gyro.z);

  // Tampilan OLED (Gambar 13)
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.println("Data MPU6050");
  display.printf("aX:%.1f aY:%.1f aZ:%.1f\n", a.acceleration.x, a.acceleration.y, a.acceleration.z);
  display.printf("gX:%.1f gY:%.1f gZ:%.1f\n", g.gyro.x, g.gyro.y, g.gyro.z);
  display.display();

  delay(500); // Jeda baca data
}