//Criando as variáveis de cada componente
int pinoLED = 23;
int pinoBotao = 22;

void setup() {
  pinMode(pinoLED, OUTPUT);
  //Definindo que o botão será do tipo ENTRADA
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  //Verificando o valor do componente pressionado HIGH ou LOW
  int valorBotao = digitalRead(pinoBotao);
  
  if (valorBotao == HIGH) {
    digitalWrite(pinoLED, HIGH);
  } else {
    digitalWrite(pinoLED, LOW);
  }
  
}


