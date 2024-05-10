int pinoLED = 23;
int pinoBotao = 22;
int pinoLED2 = 19;
int pinoBotao2 = 21;

void setup() {
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLED2, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoBotao2, INPUT_PULLUP);
}

void loop() {
  int valorBotao = digitalRead(pinoBotao);
  if (valorBotao == HIGH) {
    digitalWrite(pinoLED, HIGH);
  } else {
    digitalWrite(pinoLED, LOW);
  }
  
  int valorBotao2 = digitalRead(pinoBotao2);
  if (valorBotao2 == HIGH) {
    digitalWrite(pinoLED2, HIGH);
  } else {
    digitalWrite(pinoLED2, LOW);
  }
}


