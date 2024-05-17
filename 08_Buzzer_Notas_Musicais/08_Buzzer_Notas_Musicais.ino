int buzzer = 23;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  
  tone(buzzer, 262); //DO
  delay(500);
  tone(buzzer, 294); //RE
  delay(500);
  tone(buzzer, 330); //MI
  delay(500);
  tone(buzzer, 349); //FA
  delay(500);
  tone(buzzer, 392); //SOL
  delay(500);
  tone(buzzer, 440); //LA
  delay(500);
  tone(buzzer, 494); //SI
  delay(500);
  tone(buzzer, 523); //Dó
  delay(500);

  noTone(buzzer);
  delay(1000);  
}



