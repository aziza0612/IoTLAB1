#include <Arduino.h>

#define BLUE 14

void setup() {
    pinMode(BLUE, OUTPUT);

    // Blue LED boshida o'chirilgan
    digitalWrite(BLUE, LOW);

    Serial.begin(115200);
}

void loop() {

    // Serial orqali belgi kelganini tekshirish
    if (Serial.available() > 0) {

        char command = Serial.read();

        // Katta B -> Blue LED ON
        if (command == 'B') {
            digitalWrite(BLUE, HIGH);
            Serial.println("BLUE=1");
        }

        // Kichik b -> Blue LED OFF
        else if (command == 'b') {
            digitalWrite(BLUE, LOW);
            Serial.println("BLUE=0");
        }
    }
}