const int pinoLDR = 4;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
}

void loop() {
  // Lê o valor analógico do LDR
  int valorLDR = analogRead(pinoLDR); 
  
  Serial.println(valorLDR);
  delay(200); // Pequeno atraso para evitar oscilações
}
