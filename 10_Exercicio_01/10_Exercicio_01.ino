#include "DHT.h"
#include <Adafruit_Sensor.h>

int pinoDHT = 4;
DHT dht(pinoDHT, DHT11);

int pinoLEDVermelho = 21;
int pinoLEDVerde = 19;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(pinoLEDVermelho, OUTPUT);
  pinMode(pinoLEDVerde, OUTPUT);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Serial.print("Temp.: ");
  Serial.print(t);
  Serial.print("ºC, umidade: ");
  Serial.print(h);
  Serial.println("% ");

  if (t > 30 || h < 35) {
    digitalWrite(pinoLEDVermelho, HIGH);
    digitalWrite(pinoLEDVerde, LOW);
  } else {
    digitalWrite(pinoLEDVermelho, LOW);
    digitalWrite(pinoLEDVerde, HIGH);
  }
}

