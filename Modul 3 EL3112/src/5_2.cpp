#include <Arduino.h>

// Duty cycle 1%
const uint8_t PIN_PWM_1 = 12;  
// Duty cycle 50%
const uint8_t PIN_PWM_50 = 13; 
// Duty cycle 99%
const uint8_t PIN_PWM_99 = 14; 

const uint32_t FREQ = 10000; // 10 kHz frequency
const uint8_t RESOLUTION = 12; // 12-bit resolution (value range: 0 - 4095)

void setup() {
    ledcSetup(0, FREQ, RESOLUTION);
    ledcSetup(1, FREQ, RESOLUTION);
    ledcSetup(2, FREQ, RESOLUTION);

    ledcAttachPin(PIN_PWM_1, 0);
    ledcAttachPin(PIN_PWM_50, 1);
    ledcAttachPin(PIN_PWM_99, 2);

    // Duty Cycle Calculation (12 bit):
    // 1%  = 4095 * 0.01 = 41
    // 50% = 4095 * 0.50 = 2048
    // 99% = 4095 * 0.99 = 4054

    ledcWrite(0, 41);
    ledcWrite(1, 2048);
    ledcWrite(2, 4054);
}

void loop() {

}