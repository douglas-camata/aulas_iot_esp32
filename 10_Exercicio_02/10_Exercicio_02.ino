#include <ESP32Servo.h>

int pinoMotor = 18;
int PINO_TRIG = 22; 
int PINO_ECHO = 23; 

Servo meuServo; 

void setup() {
  meuServo.attach(pinoMotor);
  meuServo.write(0);   
  
  pinMode(PINO_TRIG, OUTPUT); 
  pinMode(PINO_ECHO, INPUT); 
}

void loop() {

  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  long duracao = pulseIn(PINO_ECHO, HIGH); 
  int distancia = (duracao * 0.0343) / 2; 

  if ( distancia < 20) {
    meuServo.write(90);
  } else {
    meuServo.write(0);
  }
  delay(500);  
}

