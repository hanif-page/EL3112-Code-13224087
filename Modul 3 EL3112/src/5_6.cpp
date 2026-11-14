#include <Arduino.h>
#include "driver/pcnt.h"

const uint8_t INPUT_PIN = 26;
// context: maybe use 100Hz, 1kHz, 10kHz, 100kHz ?

const pcnt_unit_t PCNT_UNIT = PCNT_UNIT_0;
const uint32_t SAMPLING_TIME_US = 10000;

// Pulse Accumulator
volatile uint32_t lastPulseCount = 0;

// Pulse result in 1 second
volatile uint32_t totalPulseCount = 0; 

// Frequency Result
volatile uint32_t measuredFrequency = 0;

// a boolean marker for display readiness
volatile uint8_t isReadyForDisplay = 0;

hw_timer_t *timer = NULL;

const uint32_t total_loop = 1000000 / SAMPLING_TIME_US; // 100 loop = 1 detik
volatile uint32_t curr_total_loop = 0;

void initPCNT() {
    pcnt_config_t pcnt_config = {
        .pulse_gpio_num = INPUT_PIN,
        .ctrl_gpio_num = PCNT_PIN_NOT_USED,
        .lctrl_mode = PCNT_MODE_KEEP,
        .hctrl_mode = PCNT_MODE_KEEP,
        .pos_mode = PCNT_COUNT_INC,
        .neg_mode = PCNT_COUNT_DIS,
        .counter_h_lim = 32767,
        .counter_l_lim = -32768,
        .unit = PCNT_UNIT,
        .channel = PCNT_CHANNEL_0,
    };

    pcnt_unit_config(&pcnt_config);
    pcnt_filter_disable(PCNT_UNIT); 

    pcnt_counter_pause(PCNT_UNIT);
    pcnt_counter_clear(PCNT_UNIT);
    pcnt_counter_resume(PCNT_UNIT);
}

void IRAM_ATTR timerISR() {
    int16_t count = 0;
    
    pcnt_get_counter_value(PCNT_UNIT, &count);
    pcnt_counter_clear(PCNT_UNIT);

    if (count < 0) count = 0;

    lastPulseCount += (uint32_t)count;
    curr_total_loop++;

    if (curr_total_loop >= total_loop) {
        totalPulseCount = lastPulseCount;
        measuredFrequency = lastPulseCount;
        
        curr_total_loop = 0;
        lastPulseCount = 0;

        isReadyForDisplay = 1;
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    initPCNT();

    // Setup Hardware Timer (1 MHz -> 1 tick = 1 us)
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &timerISR, true);
    timerAlarmWrite(timer, SAMPLING_TIME_US, true);
    timerAlarmEnable(timer);

    Serial.println("Frequency Measurement (PCNT + Multi-Sampling Timer)\n");
}

void loop() {
  if (isReadyForDisplay) {
    isReadyForDisplay = 0;

    noInterrupts();
    uint32_t pulseCopy = totalPulseCount;
    uint32_t freqCopy = measuredFrequency;
    interrupts();
    
    Serial.printf("Pulse Count (1s): %u | Measured Frequency: %u Hz\r\n", pulseCopy, freqCopy);
  }
}