int buzzer = 23;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  
  tone(buzzer, 262, 200); //DO
  delay(200);
  tone(buzzer, 294, 300); //RE
  delay(300);
  tone(buzzer, 330, 300); //MI
  delay(200);
  tone(buzzer, 349, 300); //FA
  delay(600);
  tone(buzzer, 349, 250); //FA
  delay(350);
  tone(buzzer, 349, 250); //FA
  delay(450);

  tone(buzzer, 262, 200); //DO
  delay(200);
  tone(buzzer, 294, 300); //RE
  delay(300);
  tone(buzzer, 262, 200); //DO
  delay(200);
  tone(buzzer, 294, 300); //RE
  delay(600);
  tone(buzzer, 294, 250); //RE
  delay(350);
  tone(buzzer, 294, 250); //RE
  delay(350);

  tone(buzzer, 262, 200); //DO
  delay(200);
  tone(buzzer, 392, 300); //SOL
  delay(300);
  tone(buzzer, 349, 200); //FA
  delay(200);
  tone(buzzer, 330, 300); //MI
  delay(600);
  tone(buzzer, 330, 250); //MI
  delay(350);
  tone(buzzer, 330, 250); //MI
  delay(350);

  tone(buzzer, 262, 200); //DO
  delay(200);
  tone(buzzer, 294, 300); //RE
  delay(300);
  tone(buzzer, 330, 300); //MI
  delay(200);
  tone(buzzer, 349, 300); //FA
  delay(600);
  tone(buzzer, 349, 250); //FA
  delay(350);
  tone(buzzer, 349, 250); //FA
  delay(450);
  
  noTone(buzzer);
  delay(1000);  
}