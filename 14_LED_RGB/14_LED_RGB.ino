int pinoR = 13; // Declarando a conexão do pino Vermelho
int pinoG = 12; // Declarando a conexão do pino Verde
int pinoB = 14; // Declarando a conexão do pino Azul

void setup() {
  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);
}

void loop() {
  gerarCor(255, 0, 0); // Gerar totamente Vermelho, sem verde e sem azul
  delay(1000);
  gerarCor(0, 255, 0); // Gerar totamente Verde, sem vermelho e sem azul
  delay(1000);
  gerarCor(0, 0, 255); // Gerar totamente Azul, sem verde e sem vermelho
  delay(1000);    
}

// Criando função para gerar a cor conforme a intensidade de cada LED
void gerarCor(int R, int G, int B) {
  analogWrite(pinoR, R);
  analogWrite(pinoG, G);
  analogWrite(pinoB, B);
}

