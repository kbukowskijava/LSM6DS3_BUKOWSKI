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
#define BUKOWSKI_SLAVE_ADDRESS  1101011b
//ustawianie parametrów pracy
#define BUKOWSKI_CTRL1_XL     0X10
#define BUKOWSKI_CTRL2_G      0X11
#define BUKOWSKI_STATUS_REG   0X1E
#define BUKOWSKI_CTRL6_C      0X15
#define BUKOWSKI_CTRL7_G      0X16
#define BUKOWSKI_CTRL8_XL     0X17
//zdefiniowanie trybu pracy I2C, podciągnięcie pinu 12 do poziomu wysokiego

int LSM6DS3_BUKOWSKI::begin(){
    _wire_ -> begin(BUKOWSKI_SLAVE_ADDRESS);
    writeRegister
}

if(readRegister(BUKOWSKI_WHO_AM_I_REG !=0x69)){
    //co ma sie dziac jak urzadzenie sie nie komunikuje - zakonczyc polaczenie
    return 0;
}