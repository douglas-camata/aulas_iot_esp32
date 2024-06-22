// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

//Referenciando as bibliotecas externas que serão utilizadas
#include "DHT.h"
#include <Adafruit_Sensor.h>

//Pino do sensor analógico
int pinoDHT = 4;

//Para utilizamos o DHT22 no wokwi pois não tem o DHT11
//Quando passar para o Arduino IDE, alterar para o DHT11
DHT dht(pinoDHT, DHT22);

void setup() {
  Serial.begin(9600);

  //Iniciando a leitura do sensor
  dht.begin();
}

void loop() {
  // Tempo de espera para o sensor fazer a primeira leitura
  delay(2000);

  //Lendo a umidade em % e armazenando em uma variável float
  float h = dht.readHumidity();
  //Lendo a temperatura m ºC e armazenando em uma variável float
  float t = dht.readTemperature();
  
  Serial.print("Temp.: ");
  Serial.print(t);
  Serial.print("ºC, umidade: ");
  Serial.print(h);
  Serial.println("% ");
}

