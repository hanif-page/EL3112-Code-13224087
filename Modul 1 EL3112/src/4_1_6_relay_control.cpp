// Muhammad Ammar Hanif
// 13224087

#include <Arduino.h>

// PIN Configuration
#define RELAY_CTRL_PIN 22
#define RELAY_SENSE_PIN 25

// additional constants
const unsigned long TIMEOUT_US = 50000; // 50ms timeout
const unsigned long HOLDTIME_MS = 200; // just a pause between measurement

void setup() {
    Serial.begin(115200);

    pinMode(RELAY_CTRL_PIN, OUTPUT);
    pinMode(RELAY_SENSE_PIN, INPUT_PULLDOWN);
    
    digitalWrite(RELAY_CTRL_PIN, LOW);
    delay(200);

    Serial.println("ESP32 Relay Control Measurement Started");
}

void loop() {
    unsigned long startTime;
    unsigned long elapsedMicros; // in microsecond unit! (1000 ms)

    // Rising Edge Measurement
    startTime = micros();
    digitalWrite(RELAY_CTRL_PIN, HIGH); // Signal ON to the relay

    // Wait until the relay contact closes physically (or HIGH)
    while(digitalRead(RELAY_SENSE_PIN) == LOW){
        if(micros() - startTime >= TIMEOUT_US) break;
    }
    elapsedMicros = micros() - startTime;

    float risingEdge_ms = elapsedMicros / 1000.0; // turning it into ms unit
    Serial.printf("[ESP32] Rising Edge Delay (ON): %.3f ms\n", risingEdge_ms);

    delay(HOLDTIME_MS);

    // Falling Edge Measurement
    startTime = micros();
    digitalWrite(RELAY_CTRL_PIN, LOW); // Signal OFF to the relay

    // Wait until the relay contact opens physically (LOW)
    while(digitalRead(RELAY_SENSE_PIN) == HIGH) {
        if(micros() - startTime >= TIMEOUT_US) break;
    }
    elapsedMicros = micros() - startTime;

    float fallingEdge_ms = elapsedMicros / 1000.0;
    Serial.printf("[ESP32] Falling Edge Delay (OFF): %.3f ms\n", fallingEdge_ms);

    // divider
    Serial.println("--------------------------------------------");

    delay(HOLDTIME_MS);
}