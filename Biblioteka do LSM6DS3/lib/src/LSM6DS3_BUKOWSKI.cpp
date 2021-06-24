/****************************************************************
 * @author: Kacper Bukowski
 * @email:  kacper.bukowski@student.wat.edu.pl
 * @file:   LSM6DS3_BUKOWSKI.cpp
 * @brief:  Biblioteka do obsługi układu LSM6DS3
 * 
****************************************************************/


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
  if (czytaj_rejestr(BUKOWSKI_WHO_AM_I) != 0x69) {
    end();
    return 0;
  }
  else
  {
  wpisz_rejestr(BUKOWSKI_CTRL2_G, 0x4C);

  wpisz_rejestr(BUKOWSKI_CTRL1_XL, 0x4A);

  wpisz_rejestr(BUKOWSKI_CTRL7_G, 0x00);

  wpisz_rejestr(BUKOWSKI_CTRL8_XL, 0x09);

  return 1;
  }
}

void LSM6DS3_BUKOWSKIClass::end(){
    wpisz_rejestr(BUKOWSKI_CTRL2_G, 0x00);
    wpisz_rejestr(BUKOWSKI_CTRL1_XL, 0x00);
    Wire.end();
}

int LSM6DS3_BUKOWSKIClass::czy_aktywny_G()
{
  if (czytaj_rejestr(BUKOWSKI_STATUS_REG) & 0x02) {
    return 1;
  }
  return 0;
}

int LSM6DS3_BUKOWSKIClass::czy_aktywny_A()
{
  if (czytaj_rejestr(BUKOWSKI_STATUS_REG) & 0x01) {
    return 1;
  }
  return 0;
}

int LSM6DS3_BUKOWSKIClass::czytaj_G_X(){
  int value = czytaj_polaczone_rejestry(BUKOWSKI_OUTX_L_G, BUKOWSKI_OUTX_H_G);
  return value;
}

int LSM6DS3_BUKOWSKIClass::czytaj_G_Y(){
  int value = czytaj_polaczone_rejestry(BUKOWSKI_OUTY_L_G, BUKOWSKI_OUTY_H_G);
  return value;
}

int LSM6DS3_BUKOWSKIClass::czytaj_G_Z(){
  int value = czytaj_polaczone_rejestry(BUKOWSKI_OUTZ_L_G, BUKOWSKI_OUTZ_H_G);
  return value;
}

int LSM6DS3_BUKOWSKIClass::czytaj_A_X(){
  int value = czytaj_polaczone_rejestry(BUKOWSKI_OUTX_L_XL, BUKOWSKI_OUTX_H_XL);
  return value;
}

int LSM6DS3_BUKOWSKIClass::czytaj_A_Y(){
  int value = czytaj_polaczone_rejestry(BUKOWSKI_OUTY_L_XL, BUKOWSKI_OUTY_H_XL);
  return value;
}

int LSM6DS3_BUKOWSKIClass::czytaj_A_Z(){
  int value = czytaj_polaczone_rejestry(BUKOWSKI_OUTZ_L_XL, BUKOWSKI_OUTZ_H_XL);
  return value;
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

int LSM6DS3_BUKOWSKIClass::czytaj_polaczone_rejestry(unsigned char lsb_registry,unsigned char msb_registry){

	int value=0;
	signed char readValue;
	readValue=czytaj_rejestr(lsb_registry);
	value=readValue;
	readValue=czytaj_rejestr(msb_registry);
	value=readValue<<8;
	return value;
}