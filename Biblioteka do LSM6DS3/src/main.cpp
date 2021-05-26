#include <Arduino.h>
#include "LSM6DS3_BUKOWSKI.h"
#include <Wire.h>
#include <HardwareSerial.h>

LSM6DS3_BUKOWSKIClass SENSOR;
bool ready_to_rock; // zmienna pomocnicza sprawdzająca poprawność działania układu
int how_slow = 500; // przerwa między odczytami
int acc_czy_gyro = 1; // 0 - akcelerometr , 1 - żyroskop

void setup(){ 
  Wire.begin();
  Serial.begin(9600);
  if(SENSOR.begin() == 1){
    Serial.println("Gotowy!");
    ready_to_rock = true;
  }
  else
  {
    Serial.println("Wystapil problem podczas uruchomienia sensora LSM6DS3");
    ready_to_rock = false;
  }
}

void loop() {
  if(ready_to_rock){
    switch(acc_czy_gyro){
      case 0:
        Serial.print("X = ");
        Serial.print(SENSOR.czytaj_A_X());
        Serial.print(" Y = ");
        Serial.print(SENSOR.czytaj_A_Y());
        Serial.print(" Z = ");
        Serial.println(SENSOR.czytaj_A_Z());
        delay(how_slow);
        break;
      case 1:
        Serial.print("X = ");
        Serial.print(SENSOR.czytaj_G_X());
        Serial.print(" Y = ");
        Serial.print(SENSOR.czytaj_G_Y());
        Serial.print(" Z = ");
        Serial.println(SENSOR.czytaj_G_Z());
        delay(how_slow);
        break;
      default:
        Serial.println("Wybierz opcje zgodnie z instrukcja!");
        delay(500);
    }
          
  }
  else
  {
    Serial.println("Zrestartuj ARDUINO!");
  } 
}