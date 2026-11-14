#include <Arduino.h>

const uint8_t pwmPin = 12;
const uint32_t freq = 40000000; // 40 MHz maximum frequency, use 10k for normal freq.  

const uint8_t resolution = 1; // 1-bit resolution fixes the duty cycle at 50% 

void setup() {
  ledcSetup(0, freq, resolution);
  ledcAttachPin(pwmPin, 0);
  
  ledcWrite(0, 1); 
  // for the duty cycle, set the resolution to 12 bit, and then set Dmax = 4054 and Dmin = 1
}

void loop() {
  // Measure the output on pwmPin using an oscilloscope!
}