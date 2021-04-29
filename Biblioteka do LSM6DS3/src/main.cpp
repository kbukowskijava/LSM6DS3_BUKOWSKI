#include <Arduino.h>
#include "LSM6DS3_BUKOWSKI.h"
#include <Wire.h>
#include <HardwareSerial.h>

LSM6DS3_BUKOWSKIClass SENSOR;
void setup(){ 
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  SENSOR.begin();
  Serial.print (SENSOR.czy_aktywny_G());
  SENSOR.end();
}