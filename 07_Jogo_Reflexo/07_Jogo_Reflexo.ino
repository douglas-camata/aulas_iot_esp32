int leds[] = { 2, 19, 22 };
int botoes[] = { 4, 21, 23 };
int ledAceso = -1;
long tempoInicial = 1;
long tempoJogo = 2000;
int botoesCorretos = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT_PULLUP);
  }
  randomSeed(analogRead(15));  // Inicializa o gerador de números aleatórios
  Serial.println("Jogo iniciado");
}

void loop() {
  if (millis() - tempoInicial > tempoJogo) {  // Verifica se o tempo de jogo acabou
    finalizaJogo();
  }

  if (ledAceso == -1) {                  // Se nenhum LED está aceso
    ledAceso = random(0, 3);             // Escolhe um LED aleatório
    digitalWrite(leds[ledAceso], HIGH);  // Acende o LED correspondente
    tempoInicial = millis();             // Inicia a contagem do tempo de reação
  }

  for (int i = 0; i < 3; i++) {
    if (digitalRead(botoes[i]) == LOW && i == ledAceso) {  // Se o botão correto foi pressionado
      digitalWrite(leds[ledAceso], LOW);                   // Apaga o LED
      ledAceso = -1;                                       // Reseta o índice do LED aceso
      botoesCorretos++;                                    // Incrementa o número de botões corretos pressionados
      tempoJogo = tempoJogo - 50;
      delay(200);
      break;
    }
  }
}

void finalizaJogo() {
  Serial.println("Fim do jogo!");
  Serial.print("Número de botões corretos pressionados: ");
  Serial.println(botoesCorretos);
  while (true) {// Loop infinito para manter o programa parado após o fim do jogo
    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[i], HIGH);
    }
  }
}

