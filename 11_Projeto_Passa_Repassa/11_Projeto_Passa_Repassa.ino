// Definição dos pinos
const int pinoLED = 5;
const int pinoBotao = 23;
const int pinoLED2 = 12;
const int pinoBotao2 = 32;
const int buzzer = 13;

// Função para tocar o padrão de som e piscar o LED
void tocarSomEPiscarLED(int pinoLED) {
  for (int i = 0; i < 5; i++) {
    
    digitalWrite(pinoLED, HIGH);
    if (pinoLED == 5) 
      tone(buzzer, 1000);  
    else     
      tone(buzzer, 2000);  
    delay(500);
    digitalWrite(pinoLED, LOW);
    if (pinoLED == 5) 
      tone(buzzer, 1500);  
    else     
      tone(buzzer, 2500);  
    delay(500);
  }
}

void setup() {
  // Configuração dos pinos
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoBotao2, INPUT_PULLUP);
}

void loop() {
  // Desliga os LEDs inicialmente
  digitalWrite(pinoLED, LOW);
  digitalWrite(pinoLED2, LOW);
  noTone(buzzer);

  // Verifica o estado do primeiro botão
  int valorBotao = digitalRead(pinoBotao);
  if (valorBotao == LOW) {
    tocarSomEPiscarLED(pinoLED);
  }  

  // Verifica o estado do segundo botão
  int valorBotao2 = digitalRead(pinoBotao2);
  if (valorBotao2 == LOW) {
    tocarSomEPiscarLED(pinoLED2);
  }
}
