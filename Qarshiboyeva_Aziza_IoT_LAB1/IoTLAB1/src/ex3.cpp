#include <Arduino.h>

#define LIGHT 33

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int raw = analogRead(LIGHT);

    Serial.print("raw=");
    Serial.println(raw);

    delay(500);
}