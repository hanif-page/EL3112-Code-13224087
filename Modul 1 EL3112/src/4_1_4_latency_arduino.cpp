// Muhammad Ammar Hanif
// 13224087

#include <Arduino.h>

#define INPUT_1 25
#define OUTPUT_1 21

void setup() {
    pinMode(INPUT_1, INPUT_PULLUP); // later, if a problem happened, then try to change INPUT_PULLUP to INPUT!
    pinMode(OUTPUT_1, OUTPUT);

    Serial.begin(115200);
    Serial.println("ESP32 Started");
}

void loop() {
    int input1;
    input1 = digitalRead(INPUT_1);
    digitalWrite(OUTPUT_1, input1);
}