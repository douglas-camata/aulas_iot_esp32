int PINO_TRIG = 18; 
int PINO_ECHO = 19; 
int PINO_LED = 23;  
 
void setup() {
  Serial.begin(9600); 
  pinMode(PINO_TRIG, OUTPUT); 
  pinMode(PINO_ECHO, INPUT);  
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);
  
  long duracao = pulseIn(PINO_ECHO, HIGH); 
  int distancia = (duracao * 0.0343) / 2; 
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 20) {
    digitalWrite(PINO_LED, HIGH);
  } else {
    digitalWrite(PINO_LED, LOW);
  }
  
  delay(500);
}

