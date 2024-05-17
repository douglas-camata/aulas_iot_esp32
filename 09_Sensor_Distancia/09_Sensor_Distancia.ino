int PINO_TRIG = 18; // conectado ao TRIG do HC-SR04
int PINO_ECHO = 19; // conectado ao ECHO do HC-SR04

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(PINO_TRIG, OUTPUT); // Configura o pino TRIG como saída
  pinMode(PINO_ECHO, INPUT);  // Configura o pino ECHO como entrada
}

void loop() {
  // Pino trigger com um pulso baixo LOW (desligado) 
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);

  // Pino trigger com pulso HIGH (ligado) 
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  // Pino trigger com um pulso baixo LOW (desligado) novamente 
  digitalWrite(PINO_TRIG, LOW);
  
  // Mede o tempo de resposta do ECHO
  long duracao = pulseIn(PINO_ECHO, HIGH); 
  // Calcula a distância usando a velocidade do som (aproximadamente 343 m/s)
  float distancia = (duracao * 0.0343) / 2; 
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500); // Aguarda 1 segundo antes de fazer a próxima leitura
}
