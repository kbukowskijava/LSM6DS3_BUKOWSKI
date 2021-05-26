#ifndef LSM6DS3_BUKOWSKI_h
#define LSM6DS3_BUKOWSKI_h

#include <Arduino.h>
#include <Wire.h>

class LSM6DS3_BUKOWSKIClass {
    public:
        LSM6DS3_BUKOWSKIClass();
        int begin(); //uruchomienie i ustawienie odpowiednich rejestrów do poprawnej pracy
        void end(); // zakończenie działania układu
        //obsługa żyroskopu
        int czytaj_G_X(); // odczyt danych żyroskopu w osi X
        int czytaj_G_Y(); // odczyt danych żyroskopu w osi Y
        int czytaj_G_Z(); // odczyt danych żyroskopu w osi Z
        int freq_G(); // odczyt częstotliwości pracy żyroskopu
        int czy_aktywny_G(); //sprawdzenie aktywności żyroskopu (1 - dane są przekazywane, 0 - żyroskop nieaktywny)
        //obsługa akcelerometru
        int czytaj_A_X(); // odczyt danych akcelerometru w osi X 
        int czytaj_A_Y(); // odczyt danych akcelerometru w osi Y
        int czytaj_A_Z(); // odczyt danych akcelerometru w osi Z
        float freq_A(); // odczyt częstotliwości pracy akcelerometru
        int czy_aktywny_A(); //sprawdzenie aktywności akcelerometru (1 - dane są przekazywane, 0 - żyroskop nieaktywny)
    private:
        int czytaj_rejestr(uint8_t address); // funkcja odczytująca zawartość konkretnego adresu rejestru urządzenia
        int wpisz_rejestr(uint8_t address, uint8_t dane); // funkcja edytująca zawartość konkretnego adresu rejestru urządzenia
        int czytaj_polaczone_rejestry(unsigned char lsb_registry,unsigned char msb_registry); // funkcja łącząca dane z dwóch rejestrów 8-bitowych w jedno słowo 16-bitowe

    private:
        uint8_t _slave_address; // adres urządzenia
};

#endif

extern LSM6DS3_BUKOWSKIClass SENSOR;