#include <Arduino.h>

const uint8_t INPUT_PIN = 26;
// context: maybe use 100Hz, 1kHz, 10kHz, 100kHz ?

volatile uint32_t pulseCount = 0;
volatile uint32_t lastPulseCount = 0;
volatile uint32_t measuredFrequency = 0;
volatile uint8_t isReadyForDisplay = 0;
hw_timer_t *timer = NULL;
const uint32_t SAMPLING_TIME_US = 1000000; // 1.000.000 us = 1 detik

void IRAM_ATTR gpioISR() {
    pulseCount++;
}

void IRAM_ATTR timerISR() {
    lastPulseCount = pulseCount;
    pulseCount = 0;
    measuredFrequency = (uint64_t)lastPulseCount * 1000000 / SAMPLING_TIME_US;
    isReadyForDisplay = 1;
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    pinMode(INPUT_PIN, INPUT_PULLDOWN);
    attachInterrupt(digitalPinToInterrupt(INPUT_PIN), gpioISR, RISING);

    // Timer Initialization (1 MHz -> 1 tick = 1 us)
    timer = timerBegin(0, 80, true); 
    timerAttachInterrupt(timer, &timerISR, true);

    // Set alarm interval timer based on SAMPLING_TIME_MS variable
    timerAlarmWrite(timer, SAMPLING_TIME_US, true);
    timerAlarmEnable(timer);

    Serial.println("Frequency Counter\n");
}

void loop() {
    if (isReadyForDisplay) {
        isReadyForDisplay = 0;

        noInterrupts();
        uint32_t pulse = lastPulseCount;
        uint32_t freq = measuredFrequency;
        interrupts();

        Serial.printf("Pulse Count: %u | Measured Frequency: %u Hz\r\n", pulse, freq);
    }
}