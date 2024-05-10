int pinoPot = 15;
int LED = 23;

void setup() {
  Serial.begin(9600);
  pinMode(pinoPot, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int valor = analogRead(pinoPot);
  Serial.println(valor);
  
  digitalWrite(LED, HIGH); 
  delay(valor);
  digitalWrite(LED, LOW); 
  delay(valor);  
}



