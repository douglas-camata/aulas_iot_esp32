int b1 = 23;
int b2 = 22;

void setup() {
  Serial.begin(9600);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(b1) == LOW) {
    Serial.println("Botão 1 pressionado");  
  }  
  if (digitalRead(b2) == LOW) {
    Serial.println("Botão 2 pressionado");  
  }
  delay(100); 
}




