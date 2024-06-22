int pinoR = 13; 
int pinoG = 14; 
int pinoB = 27; 

int pinoPotR = 26;
int pinoPotG = 32;
int pinoPotB = 33;

void setup() {
  Serial.begin(9600);

  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);

  pinMode(pinoPotR, INPUT);
  pinMode(pinoPotG, INPUT);
  pinMode(pinoPotB, INPUT);
}

void loop() {
  int valor = analogRead(pinoPotR);
  int R = map(valor, 0, 4095, 0, 255);

  valor = analogRead(pinoPotG);
  int G = map(valor, 0, 4095, 0, 255);

  valor = analogRead(pinoPotB);
  int B = map(valor, 0, 4095, 0, 255);

  Serial.println(String(R) + " - " + String(G) + " - " + String(B));

  gerarCor(R, G, B); // Gera a cor com os valores aleatórios
  delay(100);    
}

void gerarCor(int R, int G, int B) {
  analogWrite(pinoR, R);
  analogWrite(pinoG, G);
  analogWrite(pinoB, B);
}


