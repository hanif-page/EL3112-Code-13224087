#include <Arduino.h>
#include "driver/pcnt.h"

const int inputPin = 26; // GPIO pin connected to signal generator
// context: maybe use 100Hz, 1kHz, 10kHz, 100kHz ?

pcnt_unit_t pcnt_unit = PCNT_UNIT_0;

// const uint32_t SAMPLING_TIME_US = 100;  // 300kHz maks
const uint32_t SAMPLING_TIME_US = 1000000;  // 30kHz maks

void setup() {
    Serial.begin(115200);
    
    // Configure PCNT
    pcnt_config_t pcnt_config = {};
    pcnt_config.pulse_gpio_num = inputPin;
    pcnt_config.ctrl_gpio_num = PCNT_PIN_NOT_USED;
    pcnt_config.channel = PCNT_CHANNEL_0;
    pcnt_config.unit = pcnt_unit;

    // Increment on positive edge
    pcnt_config.pos_mode = PCNT_COUNT_INC; 

    // Ignore on negative edge
    pcnt_config.neg_mode = PCNT_COUNT_DIS;   

    // Keep mode when control signal is Low
    pcnt_config.lctrl_mode = PCNT_MODE_KEEP; 

    // Keep mode when control signal is High
    pcnt_config.hctrl_mode = PCNT_MODE_KEEP; 

    pcnt_config.counter_h_lim = 32767;
    pcnt_config.counter_l_lim = -32768;

    // Initialize the PCNT unit
    pcnt_unit_config(&pcnt_config);
    pcnt_counter_pause(pcnt_unit);
    pcnt_counter_clear(pcnt_unit);
    pcnt_counter_resume(pcnt_unit);
}

void loop() {
    static uint32_t lastMicros = 0;
    uint32_t currentMicros = micros();
    uint32_t elapsedMicros = currentMicros - lastMicros;

    // execution only when microsecond execution correct
    if (elapsedMicros >= SAMPLING_TIME_US) {
        int16_t rawCount = 0;

        pcnt_get_counter_value(pcnt_unit, &rawCount);
        pcnt_counter_clear(pcnt_unit);

        lastMicros = currentMicros;

        if (rawCount < 0) rawCount = 0;

        // Casting 1000000ULL (Unsigned Long Long) to prevent int overflow
        uint32_t frequency = ((uint64_t)rawCount * 1000000ULL) / elapsedMicros;

        Serial.printf("Pulse (%u us): %d | Frequency: %u Hz\n", elapsedMicros, rawCount, frequency);
}
}