#include <Arduino.h>

#define BUTTON 25
#define GREEN 27

bool greenState = false;
bool lastButtonState = LOW;

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(GREEN, OUTPUT);

    digitalWrite(GREEN, LOW);

    Serial.begin(115200);
}

void loop() {
    bool buttonState = digitalRead(BUTTON);

    // Button bosilganda
    if (lastButtonState == LOW && buttonState == HIGH) {

        greenState = !greenState;

        digitalWrite(GREEN, greenState ? HIGH : LOW);

        Serial.print("GREEN=");
        Serial.println(greenState ? 1 : 0);

        delay(50);
    }

    lastButtonState = buttonState;
}