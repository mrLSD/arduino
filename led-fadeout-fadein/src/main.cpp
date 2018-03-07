#include <Arduino.h>

uint8_t led_pin = 9;
uint8_t brightness = 1;
int8_t increment = 1;

void setup() {
    pinMode(led_pin, OUTPUT);
}

void loop() {
    if (brightness >= 250 || brightness < 1) {
        increment =  -increment;
    }
    brightness += increment;
    analogWrite(led_pin, brightness);
    delay(20);
}