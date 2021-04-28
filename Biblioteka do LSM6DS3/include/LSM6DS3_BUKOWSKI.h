#ifndef LSM6DS3_BUKOWSKI
#define LSM6DS3_BUKOWSKI

#include <Arduino.h>
#include <Wire.h>
// do naprawienia klasa
class LSM6DS3_BUKOWSKI{
    private:
        uint8_t _slave;
        TwoWire* _wire;
        int czytaj_rejestr(uint8_t address);
        int czytaj_rejestry(uint8_t address, uint8_t* dane, size_t dlugosc);
        int wpisz_rejestr(uint8_t address, uint8_t dane);
        
    public:
        LSM6DS3_BUKOWSKI(uint8_t address);
        int begin();
        int end();
        //obsługa żyroskopu
        int czytaj_G(float& x, float& y, float& z);
        int freq_G();
        int czy_aktywny_G();
        //obsługa akcelerometru
        int czytaj_A(float& x, float& y, float& z);
        float freq_A();
        int czy_aktywny_A();
};
#endif