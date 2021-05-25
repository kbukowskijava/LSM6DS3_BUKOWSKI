#ifndef LSM6DS3_BUKOWSKI_h
#define LSM6DS3_BUKOWSKI_h

#include <Arduino.h>
#include <Wire.h>
// do naprawienia klasa
class LSM6DS3_BUKOWSKIClass {
    public:
        LSM6DS3_BUKOWSKIClass();
        int begin(); //uruchomienie i ustawienie odpowiednich rejestrów do poprawnej pracy
        void end(); // zakończenie działania układu
        //obsługa żyroskopu
        int czytaj_G_X(); // odczyt danych żyroskopu w osi X
        int czytaj_G_Y(); // odczyt danych żyroskopu w osi Y
        int czytaj_G_Z(); // odczyt danych żyroskopu w osi Z
        int freq_G();
        int czy_aktywny_G();
        //obsługa akcelerometru
        int czytaj_A_X();
        int czytaj_A_Y();
        int czytaj_A_Z();
        float freq_A();
        int czy_aktywny_A();
    private:
        int czytaj_rejestr(uint8_t address);
        int wpisz_rejestr(uint8_t address, uint8_t dane);
        int czytaj_polaczone_rejestry(unsigned char lsb_registry,unsigned char msb_registry);

    private:
        uint8_t _slave_address;
};

#endif

extern LSM6DS3_BUKOWSKIClass SENSOR;