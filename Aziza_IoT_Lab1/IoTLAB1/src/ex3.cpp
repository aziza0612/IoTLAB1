#include <Arduino.h>

const int LIGHT_PIN = 33;      // Yorug'lik sensori ulangan pin (ESP32 GPIO33)
const long INTERVAL = 500;     // O'qish oralig'i (millisekundlarda)

unsigned long previousMillis = 0;  // Oxirgi o'qish vaqtini saqlash uchun

void setup() {
  Serial.begin(115200);        // Serial aloqani boshlash
  pinMode(LIGHT_PIN, INPUT);   // Pinni kirish sifatida belgilash
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;

    int raw = analogRead(LIGHT_PIN);  // Sensordan xom (raw) qiymatni o'qish

    Serial.print("raw=");
    Serial.println(raw);
  }
}