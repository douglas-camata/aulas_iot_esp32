void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Configurando o ESP32 na função setup");
  Serial.print("O setup é executado");
  Serial.println(" apenas na inicialização");
}

void loop() {
  Serial.println("Executando a função loop");
  delay(500);
}
