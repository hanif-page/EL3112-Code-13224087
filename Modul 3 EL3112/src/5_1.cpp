#include <Arduino.h>

const uint8_t OUTPUT_PIN = 12;
const uint32_t PIN_MASK = (1UL << OUTPUT_PIN);

volatile uint8_t outputState = 0;
hw_timer_t *timer = NULL;

// Frequency options:
// 100 (100 Hz), 1000000 (1 MHz), 20000000 (20 MHz)
const uint32_t freqHZ = 20000000; 

void IRAM_ATTR onTimer() {
    outputState = !outputState;
    if (outputState) {
        GPIO.out_w1ts = PIN_MASK;
    } else {
        GPIO.out_w1tc = PIN_MASK;
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    pinMode(OUTPUT_PIN, OUTPUT);

    // Prescaler = 2 -> Clock Timer = 80 MHz / 2 = 40 MHz
    timer = timerBegin(0, 2, true);
    timerAttachInterrupt(timer, &onTimer, true);

    // Clock Timer (40.000.000 Hz) / (2 * freqHZ)
    uint32_t timerTicks = 40000000 / (2 * freqHZ);
    
    if (timerTicks < 1) timerTicks = 1; 

    timerAlarmWrite(timer, timerTicks, true);
    timerAlarmEnable(timer);

    Serial.printf("Frequency Target: %u Hz | Ticks Timer: %u\n", freqHZ, timerTicks);
}

void loop() {
  
}