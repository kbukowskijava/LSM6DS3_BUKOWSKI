#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int x = 100;
  digitalWrite(LED_BUILTIN, HIGH);
  delay(x);
  digitalWrite(LED_BUILTIN, LOW);
  delay(x);
  }