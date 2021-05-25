# Biblioteka do obsługi układu LSM6DS3

Autor: Kacper Bukowski
Grupa: WEL18EC1S1
Nr_albumu: 71968
Rozpoczęcie pracy nad projektem: 27.04.2021r.
Zakończenie pracy nad projektem: 25.05.2021r.

##Dokumentacja biblioteki

###Opis biblioteki 
Biblioteka jest przeznaczona tylko i wyłącznie dla płytki Arduino NANO 33 IoT. Przystosowana jest do połączeń poprzez interfejs komunikacyjny I2C. Z racji tego, iż piny wymagane do komunikacji poprzez interfejs SPI zostały fizycznie podłączone do masy, biblioteka nie posiada obsługi tego standardu. 

###Jak dołączyć bibliotekę do projektu :question:

Dla Arduino IDE:

Dla dodatku PlatformIO do programu Visual Studio Code:
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