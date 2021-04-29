#include "LSM6DS3_BUKOWSKI.h"
#include <Wire.h>
// zdefiniowanie rejestrów wyjścia żyroskopu
#define BUKOWSKI_OUTX_L_G 0x22
#define BUKOWSKI_OUTX_H_G 0x23
#define BUKOWSKI_OUTY_L_G 0x24
#define BUKOWSKI_OUTY_H_G 0x25
#define BUKOWSKI_OUTZ_L_G 0x26
#define BUKOWSKI_OUTZ_H_G 0x27

// zdefiniowanie rejestrów wyjścia akcelerometru
#define BUKOWSKI_OUTX_L_XL 0x28
#define BUKOWSKI_OUTX_H_XL 0x29
#define BUKOWSKI_OUTY_L_XL 0x2A
#define BUKOWSKI_OUTY_H_XL 0x2B
#define BUKOWSKI_OUTZ_L_XL 0x2C
#define BUKOWSKI_OUTZ_H_XL 0x2D

//zdefiniowanie rejestrów potrzebnych do poprawnej konfiguracji i identyfikacji
#define BUKOWSKI_WHO_AM_I 0x0F // tylko odczyt (wartość: 69h) - sprawdzenie działania urządzenia
#define BUKOWSKI_SLAVE_ADDRESS  0x6A
//ustawianie parametrów pracy
#define BUKOWSKI_CTRL1_XL     0X10
#define BUKOWSKI_CTRL2_G      0X11
#define BUKOWSKI_STATUS_REG   0X1E
#define BUKOWSKI_CTRL6_C      0X15
#define BUKOWSKI_CTRL7_G      0X16
#define BUKOWSKI_CTRL8_XL     0X17

LSM6DS3_BUKOWSKIClass::LSM6DS3_BUKOWSKIClass(){
}

int LSM6DS3_BUKOWSKIClass::begin(){
  Wire.begin();
  if (czytaj_rejestr(BUKOWSKI_WHO_AM_I) != 0x69) {
    return 0;
  }
}
int LSM6DS3_BUKOWSKIClass::czytaj_rejestr(uint8_t address){
  int value;
  Wire.beginTransmission(BUKOWSKI_SLAVE_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(BUKOWSKI_SLAVE_ADDRESS,2);
  if(Wire.available()<=2){
    value = Wire.read();
  }
  return value;
}

int LSM6DS3_BUKOWSKIClass::wpisz_rejestr(uint8_t address, uint8_t dane)
{
    Wire.beginTransmission(BUKOWSKI_SLAVE_ADDRESS);
    Wire.write(address);
    Wire.write(dane);
    if (Wire.endTransmission() != 0) {
      return 0;
    }
  return 1;
}