// Muhammad Ammar Hanif
// 13224087

#include <Arduino.h>

#define SIGNAL_PIN 22 // Connect to Signal Generator output

// Variable counter used inside ISR must be declared as 'volatile' type
volatile unsigned long pulseCount = 0;

// Interrupt Service Routine (ISR), which will be executed on every RISING edge
void IRAM_ATTR countPulse() {
    pulseCount++;
}

unsigned long previousMillis = 0;
const unsigned long interval = 1000; // Gate time: 1000 ms (1 second)

void setup() {
    Serial.begin(115200);

    // Configure input pin
    pinMode(SIGNAL_PIN, INPUT);

    // Attach external interrupt to trigger on RISING edge
    attachInterrupt(digitalPinToInterrupt(SIGNAL_PIN), countPulse, RISING);

    Serial.println("ESP32 Frequency Counter Started");
    Serial.println("Measuring input signal frequency on GPIO 25...");
}

void loop() {
    unsigned long currentMillis = millis();

    // Check if 1 second gate time has elapsed
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        // read and reset pulse counter
        noInterrupts();
        unsigned long frequency = pulseCount;
        pulseCount = 0;
        interrupts();

        // Output frequency to Serial Monitor (pulses per second = Hz)
        Serial.printf("Measured Frequency: %lu Hz\n", frequency);
    }
}