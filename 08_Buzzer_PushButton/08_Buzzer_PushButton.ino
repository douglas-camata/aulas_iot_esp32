int buzzer = 23;
int botao1 = 22;
int botao2 = 21;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(botao1) == LOW) {
    musica1();
  }else if (digitalRead(botao2) == LOW) {
    tone(buzzer, 3000); 
  } else {
    noTone(buzzer);
  }

  delay(50);
}

void musica1() {
  tone(buzzer, 523, 200); //DO
  delay(200);
  tone(buzzer, 587, 300); //RE
  delay(300);
  tone(buzzer, 659, 300); //MI
  delay(200);
  tone(buzzer, 698, 300); //FA
  delay(600);
  tone(buzzer, 698, 250); //FA
  delay(350);
  tone(buzzer, 698, 250); //FA
  delay(450);

  tone(buzzer, 523, 200); //DO
  delay(200);
  tone(buzzer, 587, 300); //RE
  delay(300);
  tone(buzzer, 523, 200); //DO
  delay(200);
  tone(buzzer, 587, 300); //RE
  delay(600);
  tone(buzzer, 587, 250); //RE
  delay(350);
  tone(buzzer, 587, 250); //RE
  delay(350);

  tone(buzzer, 523, 200); //DO
  delay(200);
  tone(buzzer, 784, 300); //SOL
  delay(300);
  tone(buzzer, 698, 200); //FA
  delay(200);
  tone(buzzer, 659, 300); //MI
  delay(600);
  tone(buzzer, 659, 250); //MI
  delay(350);
  tone(buzzer, 659, 250); //MI
  delay(350);

  tone(buzzer, 523, 200); //DO
  delay(200);
  tone(buzzer, 587, 300); //RE
  delay(300);
  tone(buzzer, 659, 300); //MI
  delay(200);
  tone(buzzer, 698, 300); //FA
  delay(600);
  tone(buzzer, 698, 250); //FA
  delay(350);
  tone(buzzer, 698, 250); //FA
  delay(450);
  
  noTone(buzzer);
}


