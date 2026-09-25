#include <Arduino.h>

#define BUTTON 25
#define GREEN 27

bool greenState = false;
bool lastButtonState = HIGH;

void setup()
{
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(GREEN, OUTPUT);

    digitalWrite(GREEN, LOW);

    Serial.begin(9600);
}

void loop()
{
    bool buttonState = digitalRead(BUTTON);

    if (lastButtonState == HIGH && buttonState == LOW)
    {
        greenState = !greenState;

        if (greenState)
        {
            digitalWrite(GREEN, HIGH);
            Serial.println("GREEN=1");
        }
        else
        {
            digitalWrite(GREEN, LOW);
            Serial.println("GREEN=0");
        }

        delay(50);
    }

    lastButtonState = buttonState;
}