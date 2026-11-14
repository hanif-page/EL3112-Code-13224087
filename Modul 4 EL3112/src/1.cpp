// Muhammad Ammar Hanif
#include <Arduino.h>

// Change this part based on the needed Gambar data variation!
// Baud Rate Variation: 1200 atau 115200
long BAUD_RATE = 1200; 

// Config Variation
// - No Parity 8 Databit   : SERIAL_8N1
// - Even Parity 8 Databit : SERIAL_8E1
// - Odd Parity 8 Databit  : SERIAL_8O1
// - No Parity 7 Databit   : SERIAL_7N1
// - Even Parity 7 Databit : SERIAL_7E1
// - Odd Parity 7 Databit  : SERIAL_7O1
uint32_t UART_CONFIG = SERIAL_8O1; 

#define RX_PIN 16
#define TX_PIN 17

// Store the 3 NIM digits as raw numeric bytes (not ASCII characters)
uint8_t nim[] = {0, 8, 7}; 

void setup() {
  Serial.begin(115200);
  Serial1.begin(BAUD_RATE, UART_CONFIG, RX_PIN, TX_PIN); 
  Serial.println("Starting Raw Binary Serial1 Transmission...!");
}

void loop() {
  // Use .write(buffer, length) to send raw binary values
  Serial1.write(nim, sizeof(nim)); 
  
  delay(10); // delay between bursts
}