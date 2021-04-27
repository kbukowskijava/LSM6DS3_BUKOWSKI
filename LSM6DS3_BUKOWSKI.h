#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

class LSM6DS3_BUKOWSKI{
    private:
        uint8_t _slave_;
        TwoWire* _wire_;
    public:
        LSM6DS3_BUKOWSKI(TwoWire& wire, uint8_t slave);
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
}