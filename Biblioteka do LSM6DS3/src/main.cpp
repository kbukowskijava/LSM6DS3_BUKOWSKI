#include <Arduino.h>
#include "LSM6DS3_BUKOWSKI.h"
#include <Wire.h>
#include <HardwareSerial.h>

void setup() 
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  if (LSM6DS3_BUKOWSKI.begin())
}