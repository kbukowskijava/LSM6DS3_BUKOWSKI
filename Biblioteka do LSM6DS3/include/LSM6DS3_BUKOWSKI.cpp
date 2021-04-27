#include "LSM6DS3_BUKOWSKI.h"
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
#define BUKOWSKI_WHO_AM_I_REG 0x0F // tylko odczyt (wartość: 69h) - sprawdzenie działania urządzenia
#define BUKOWSKI_SLAVE_ADDRESS  1101011
//ustawianie parametrów pracy
#define BUKOWSKI_CTRL1_XL     0X10
#define BUKOWSKI_CTRL2_G      0X11
#define BUKOWSKI_STATUS_REG   0X1E
#define BUKOWSKI_CTRL6_C      0X15
#define BUKOWSKI_CTRL7_G      0X16
#define BUKOWSKI_CTRL8_XL     0X17

int LSM6DS3_BUKOWSKI::begin(){
    Wire.begin(BUKOWSKI_SLAVE_ADDRESS);
    if(czytaj_rejestr(BUKOWSKI_WHO_AM_I_REG == 0x69)){
    for (int i=0; i < 10; i++){
        int x = 1000;
        digitalWrite(LED_BUILTIN, HIGH);
        delay(x);
        digitalWrite(LED_BUILTIN, LOW);
        delay(x);
    }}
    else
    {
       for (int i=0; i < 10; i++){
        int x = 100;
        digitalWrite(LED_BUILTIN, HIGH);
        delay(x);
        digitalWrite(LED_BUILTIN, LOW);
        delay(x); 
    }
    }
    //co ma sie dziac jak urzadzenie sie nie komunikuje - zakonczyc polaczenie
    return 1;
}
//odczyt rejestru
int LSM6DS3_BUKOWSKI::czytaj_rejestr(uint8_t address)
{
  uint8_t value;
  
  if (czytaj_rejestry(address, &value, sizeof(value)) != 1) {
    return -1;
  }
  
  return value;
}
//odczyt wyznaczonej serii z rejestrów
int LSM6DS3_BUKOWSKI::czytaj_rejestry(uint8_t address, uint8_t* dane, size_t dlugosc)
{
  
    Wire.beginTransmission(BUKOWSKI_SLAVE_ADDRESS);
    Wire.write(address);

    if (Wire.endTransmission(false) != 0) {
      return -1;
    }

    if (Wire.requestFrom(BUKOWSKI_SLAVE_ADDRESS, dlugosc) != dlugosc) {
      return 0;
    }

    for (size_t i = 0; i < dlugosc; i++) {
      *dane++ = Wire.read();
    }
  
  return 1;
}
//zapisanie wartości do rejestru
int LSM6DS3_BUKOWSKI::wpisz_rejestr(uint8_t address, uint8_t dane)
{
    Wire.beginTransmission(BUKOWSKI_SLAVE_ADDRESS);
    Wire.write(address);
    Wire.write(dane);
    if (Wire.endTransmission() != 0) {
      return 0;
    }
  return 1;
}

