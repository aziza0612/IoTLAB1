#include <Arduino.h>

#define BUTTON 25
#define LIGHT 33
#define YELLOW 12

bool lastButtonState = LOW;

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(LIGHT, INPUT);
    pinMode(YELLOW, OUTPUT);

    digitalWrite(YELLOW, LOW);

    Serial.begin(115200);
}

void loop() {
    bool buttonState = digitalRead(BUTTON);

    // Button bosilganini aniqlash
    if (lastButtonState == LOW && buttonState == HIGH) {

        // LIGHT sensorni bir marta o'qish
        int raw = analogRead(LIGHT);

        // Serialga chiqarish
        Serial.print("snapshot=");
        Serial.println(raw);

        // Yellow LED 100 ms yonadi
        digitalWrite(YELLOW, HIGH);
        delay(100);
        digitalWrite(YELLOW, LOW);
    }

    lastButtonState = buttonState;
}