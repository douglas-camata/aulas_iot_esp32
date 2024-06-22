#include "DHT.h"
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

int ledVerde = 4;
int ledVermelho = 5;
int pinoDHT = 15;
int pinoMotor = 21;
int pinoTrigger = 23;
int pinoEcho = 22;
int pinoLDR = 13;
int pinoRele = 12;

bool sistemaNormal = true;

DHT dht(pinoDHT, DHT11);
Servo meuServo;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  dht.begin();

  meuServo.attach(pinoMotor);
  meuServo.write(0);

  pinMode(pinoTrigger, OUTPUT);
  pinMode(pinoEcho, INPUT);

  pinMode(pinoLDR, INPUT);

  pinMode(pinoRele, OUTPUT);
}

void loop() {
  sistemaNormal = true;
  verificarTemperatura();
  verificarReservatorio();
  verificarLuminosidade();
  estadoSistema();
  delay(500);
}

void verificarLuminosidade() {
  int luminosidade = analogRead(pinoLDR);
  
  if (luminosidade < 1500) {
    digitalWrite(pinoRele, HIGH);
  } else {
    digitalWrite(pinoRele, LOW);
  }
  Serial.println(luminosidade);
}

void verificarReservatorio() {
  digitalWrite(pinoTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrigger, LOW);

  long duracao = pulseIn(pinoEcho, HIGH);
  int distancia = (duracao * 0.0343) / 2;
  Serial.println(distancia);

  if ( distancia < 10) {
    meuServo.write(0);
  } else {
    meuServo.write(45);
    sistemaNormal = false;
  }
}

void verificarTemperatura() {
  float umid = dht.readHumidity();
  float temp = dht.readTemperature();
  if (temp > 32 || umid < 30) {
    sistemaNormal = false;
  }
  Serial.println(temp);
}

void estadoSistema() {
  if (sistemaNormal == true) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
}

