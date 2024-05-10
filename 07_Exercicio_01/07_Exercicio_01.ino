int pinoPot = 15;
int LED1 = 23;
int LED2 = 22;
int LED3 = 21;

void setup() {
  Serial.begin(9600);
  pinMode(pinoPot, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop () {
  int valor = analogRead(pinoPot);
  Serial.println(valor);

  apagarLEDS();

  if (valor > 1200) {
    digitalWrite(LED1, HIGH);
  }
  if (valor > 2400) {
    digitalWrite(LED2, HIGH);
  }
  if (valor > 3600) {
    digitalWrite(LED3, HIGH);
  }
}

void apagarLEDS() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}