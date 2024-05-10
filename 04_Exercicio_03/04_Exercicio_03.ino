int pinoLed1 = 23;
int pinoLed2 = 22;
int pinoLed3 = 21;

void setup() {
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed3, OUTPUT);
}

void loop() {
  digitalWrite(pinoLed1, HIGH);
  digitalWrite(pinoLed2, LOW);
  digitalWrite(pinoLed3, HIGH);
  delay(500);
  digitalWrite(pinoLed1, LOW);
  digitalWrite(pinoLed2, HIGH);
  digitalWrite(pinoLed3, LOW);
  delay(1000);
}

