int buzzer = 23;

void setup() {
  //Buzzer é um componente de saída
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Na função tone, enviamos 3 parâmetros:
  //1-> pino do buzzer conectado
  //2-> frequência do tom em Hz (Hertz)
  //3-> duração do tom em milisegundos
  tone(buzzer, 1000, 500);
  // Função noTone desliga o buzzer
  noTone(buzzer);
  delay(1000);  
}



