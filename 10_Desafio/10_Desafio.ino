#include <ESP32Servo.h>

int pinoMotor = 18;
int PINO_TRIG = 22; 
int PINO_ECHO = 23; 
int pinoBuzzer = 21;
int pinoLED = 5;

Servo meuServo; 

void setup() {
  meuServo.attach(pinoMotor);
  meuServo.write(90);   
  
  pinMode(PINO_TRIG, OUTPUT); 
  pinMode(PINO_ECHO, INPUT); 
  pinMode(pinoBuzzer, OUTPUT);  
  pinMode(pinoLED, OUTPUT);  
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
    meuServo.write(0);
    tone(pinoBuzzer, 1000);
    digitalWrite(pinoLED, HIGH);
    delay(500);
    digitalWrite(pinoLED, LOW);
    tone(pinoBuzzer, 2000);
  } else {
    meuServo.write(90);
    noTone(pinoBuzzer);
  }
  delay(500);  
}

// Função para gerar um sinal PWM manualmente para o buzzer
void playBuzzer(int frequency) {
  int period = 1000000 / frequency; // Período em microsegundos
  int halfPeriod = period / 2; // Metade do período

  for (long i = 0; i < 1000000; i += period) { // Gera o sinal por 1 segundo
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(halfPeriod);
  }
}
