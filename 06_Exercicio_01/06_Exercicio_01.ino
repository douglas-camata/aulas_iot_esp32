int contador = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Contando");
}

void loop() {
  contador = contador + 1;
  Serial.print(contador);
  Serial.println("ª vez");
  delay(500); 
}
