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

