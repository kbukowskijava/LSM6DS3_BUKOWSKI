# Biblioteka do obsługi układu LSM6DS3

Autor: Kacper Bukowski
Grupa: WEL18EC1S1
Nr_albumu: 71968
Rozpoczęcie pracy nad projektem: 27.04.2021r.
Zakończenie pracy nad projektem: 25.05.2021r.

## Dokumentacja biblioteki

### Opis biblioteki 
Biblioteka jest przeznaczona tylko i wyłącznie dla płytki Arduino NANO 33 IoT. Przystosowana jest do połączeń poprzez interfejs komunikacyjny I2C. Z racji tego, iż piny wymagane do komunikacji poprzez interfejs SPI zostały fizycznie podłączone do masy, biblioteka nie posiada obsługi tego standardu. 

### Jak dołączyć bibliotekę do projektu :question:

###### Dla Arduino IDE:
Wystarczy umieścić pliki LSM6DS3.h oraz LSM6DS3.cpp w katalogu bibliotek. Dodatkowe informacje można znaleźć pod linkiem: https://www.arduino.cc/en/hacking/libraries

###### Dla dodatku PlatformIO do programu Visual Studio Code:
- należy umieścić pliki LSM6DS3.h oraz LSM6DS3.cpp w katalogu /lib/src projektu
- wymagana jest modyfikacja pliku platformio.ini

Przykładowy plik platformio.ini:
```
[env:nano_33_iot]
platform = atmelsam
board = nano_33_iot
framework = arduino

lib_deps = D:\LSM6DS3_BUKOWSKI\Biblioteka do LSM6DS3\lib\src
```

Najważniejsze, poza dodaniem odpowiednich parametrów konfiguracji, jest umieszczenie stosownej ścieżki do plików LSM6DS3.h oraz LSM6DS3.cpp. Dopiero wtedy dodatek PlatformIO nie będzie zgłaszał błędu dostępu do pliku nagłówkowego.

W pliku main.cpp należy dołączyć bibliotekę poprzez umieszczenie w kodzie linijki:
```
#include <BUKOWSKI_LSM6DS3.h>
```

### Przykład zastosowania biblioteki:
Przykład jest dostępny w pliku main.cpp tego repozytorium. 

```
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
    Serial.println("Ready!");
    ready_to_rock = true;
  }
  else
  {
    Serial.println("Failed to initialize LSM6DS3 sensor");
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
```