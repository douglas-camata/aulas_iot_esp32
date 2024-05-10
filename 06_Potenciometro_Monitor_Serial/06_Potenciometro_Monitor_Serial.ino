//Criando a variável com o pino analógico do potenciômetro
int pinoPot = 15;

void setup() {
  Serial.begin(9600);
  Serial.println("Estudando sobre entrada analógica");
  //Definindo o comportamento do pino como ENTRADA
  pinMode(pinoPot, INPUT);
}

void loop() {
  //Lendo o valor da entrada analógica e armazendando na 
  //variável valor
  int valor = analogRead(pinoPot);
  delay(400); 
  //Exibindo o valor do potenciômetro de 0 a 4095
  Serial.println(valor);
}



