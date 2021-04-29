#include <Arduino.h>
#include "LSM6DS3_BUKOWSKI.h"
#include <Wire.h>
#include <HardwareSerial.h>

void setup(){ 
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  if(SENSOR.begin() == 1){
    Serial.print("DZIALA");
  }
  else
  {
    Serial.print("FAIL");
  }
}