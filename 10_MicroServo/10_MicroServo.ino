#include <ESP32Servo.h>

Servo meuServo;  // Cria um objeto servo

void setup() {
  meuServo.attach(18);  // Define o pino GPIO 18 como o pino de controle do servo
}

void loop() {
  meuServo.write(0);    // Move para a posição 0 graus
  delay(1000);          // Espera por 1 segundo
  meuServo.write(90);   // Move para a posição 90 graus
  delay(1000);          // Espera por 1 segundo
  meuServo.write(180);  // Move para a posição 180 graus
  delay(1000);          // Espera por 1 segundo
}
