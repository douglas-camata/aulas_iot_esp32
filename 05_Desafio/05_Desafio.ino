int led1 = 21;
int led2 = 22;
int led3 = 23;
int botao1 = 15; 
int botao2 = 2; 
int ledsAcesos = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(botao1) == LOW ) {
    ledsAcesos = ledsAcesos - 1;
    delay(300);
  }
  if (digitalRead(botao2) == LOW ) {
    ledsAcesos = ledsAcesos + 1;
    delay(300);
  }

  if (ledsAcesos == 0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (ledsAcesos == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (ledsAcesos == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if (ledsAcesos == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}
