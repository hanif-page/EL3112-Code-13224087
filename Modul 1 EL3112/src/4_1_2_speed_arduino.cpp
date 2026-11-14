// Muhammad Ammar Hanif
// 13224087

#include <Arduino.h>

// built in LED pin
#define LED_BUILTIN 22

// the setup function runs once when you press reset or power the board
void setup() {
    // ESP32 CPU Frequency settings
    setCpuFrequencyMhz(240); // 240 MHz
    // Use another variations, which are 160, 80, 40, 26, 20, 13, 10

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
}