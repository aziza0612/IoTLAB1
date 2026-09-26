#include <Arduino.h>

#define LIGHT 33

#define BLUE 14
#define GREEN 27
#define YELLOW 12
#define RED 26

void setup() {
    Serial.begin(115200);

    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(RED, OUTPUT);

    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
}

void loop() {
    int raw = analogRead(LIGHT);

    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);

    if (raw <= 1023) {
        digitalWrite(BLUE, HIGH);
        Serial.println("band=BLUE");
    }
    else if (raw <= 2047) {
        digitalWrite(GREEN, HIGH);
        Serial.println("band=GREEN");
    }
    else if (raw <= 3071) {
        digitalWrite(YELLOW, HIGH);
        Serial.println("band=YELLOW");
    }
    else {
        digitalWrite(RED, HIGH);
        Serial.println("band=RED");
    }

    delay(500);
}