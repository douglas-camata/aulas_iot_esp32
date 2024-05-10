void setup() {
  //Definindo o pino 22 que será de saída
  pinMode(22, OUTPUT);
}

// Função que ficará em loop infinito
void loop() {
  //Escrevendo no pino digital 22, o valor HIGH
  //para acender o LED
  digitalWrite(22, HIGH); 
  delay(500);  // Esta função cria uma pausa de 500ms
  //Escrevendo no pino digital 22, o valor HIGH
  //para acender o LED
  digitalWrite(22, LOW);
  delay(500);  // Esta função cria uma pausa de 500ms
}


