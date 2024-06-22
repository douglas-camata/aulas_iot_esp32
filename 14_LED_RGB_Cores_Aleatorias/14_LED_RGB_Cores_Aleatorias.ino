int pinoR = 13; 
int pinoG = 12; 
int pinoB = 14; 

void setup() {
  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);
}

void loop() {
  int R = random(0, 256); // Gera um valor aleatório entre 0 e 255 para o vermelho
  int G = random(0, 256); // Gera um valor aleatório entre 0 e 255 para o verde
  int B = random(0, 256); // Gera um valor aleatório entre 0 e 255 para o azul

  gerarCor(R, G, B); // Gera a cor com os valores aleatórios
  delay(1000);    
}

void gerarCor(int R, int G, int B) {
  analogWrite(pinoR, R);
  analogWrite(pinoG, G);
  analogWrite(pinoB, B);
}


