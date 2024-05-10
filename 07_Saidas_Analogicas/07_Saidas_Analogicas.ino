int pinoPot = 15;
int led = 23;

void setup() {
  Serial.begin(9600);
  pinMode(pinoPot, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // Lê o valor analógico do potenciômetro
  int valor = analogRead(pinoPot);
  Serial.println(valor);
  // Mapeia o valor lido para o intervalo de 0 a 255
  int luminosidade = map(valor, 0, 4095, 0, 255);
  Serial.print("Potenciômetro: ");
  Serial.print(valor);
  Serial.print(" Luminosidade: ");
  Serial.println(luminosidade);
  
  //Define a luminosidade do LED
  analogWrite(led, luminosidade);
  delay(100);
}
