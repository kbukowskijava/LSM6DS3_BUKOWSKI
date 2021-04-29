#ifndef LSM6DS3_BUKOWSKI
#define LSM6DS3_BUKOWSKI

#include <Arduino.h>
#include <Wire.h>
// do naprawienia klasa
class LSM6DS3_BUKOWSKI{
    public:
        LSM6DS3_BUKOWSKI();
        int begin();
        // void end();
        // //obsługa żyroskopu
        // int czytaj_G(float& x, float& y, float& z);
        // int freq_G();
        // int czy_aktywny_G();
        // //obsługa akcelerometru
        // int czytaj_A(float& x, float& y, float& z);
        // float freq_A();
        // int czy_aktywny_A();
    private:
        int czytaj_rejestr(uint8_t address);
        int wpisz_rejestr(uint8_t address, uint8_t dane);
};
#endif