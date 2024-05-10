int pinoLDR = 4;
int pinoLED = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  int valorLDR = analogRead(pinoLDR); // Lê o valor analógico do potenciômetro
  
  int intensidade = map(valorLDR, 0, 4095, 255, 0); // Mapeia o valor lido para o intervalo de 0 a 255
  
  Serial.println(valorLDR);

  analogWrite(pinoLED, intensidade);
  
  delay(200); // Pequeno atraso para evitar oscilações
}
