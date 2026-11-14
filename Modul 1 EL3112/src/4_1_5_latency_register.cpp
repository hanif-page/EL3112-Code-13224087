// Muhammad Ammar Hanif
// 13224087

#include <Arduino.h>
#include "soc/gpio_reg.h"
#include "driver/gpio.h"

#define INPUT_1 25
#define OUTPUT_1 21

void setup() {
    pinMode(INPUT_1, INPUT_PULLUP); // later, if a problem happened, then try to change INPUT_PULLUP to INPUT!
    pinMode(OUTPUT_1, OUTPUT);

    Serial.begin(115200);
    Serial.println("ESP32 Started");
}

void loop() {
    // Read the state of INPUT_1 from GPIO_IN_REG
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
    if (REG_READ(GPIO_IN_REG) & (1ULL << INPUT_1)) { // 1ULL means number 1 as unsigned long long int
        // Set OUTPUT_1 HIGH using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
    } else {
        // Set OUTPUT_1 LOW using REG_WRITE
        REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
    }
}