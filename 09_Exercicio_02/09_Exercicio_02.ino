int PINO_TRIG = 18; 
int PINO_ECHO = 19; 
int PINO_LED1 = 21;  
int PINO_LED2 = 22;  
int PINO_LED3 = 23;  
 
void setup() {
  Serial.begin(9600); 
  pinMode(PINO_TRIG, OUTPUT); 
  pinMode(PINO_ECHO, INPUT);  
  pinMode(PINO_LED1, OUTPUT);
  pinMode(PINO_LED2, OUTPUT);
  pinMode(PINO_LED3, OUTPUT);
}

void loop() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);
  
  long duracao = pulseIn(PINO_ECHO, HIGH); 
  int distancia = (duracao * 0.0343) / 2; 
  Serial.print(distancia);
  Serial.println(" cm");

  digitalWrite(PINO_LED1, LOW);
  digitalWrite(PINO_LED2, LOW);
  digitalWrite(PINO_LED3, LOW);

  if (distancia < 10) {
    delay(500);
    digitalWrite(PINO_LED1, HIGH);
    digitalWrite(PINO_LED2, HIGH);
    digitalWrite(PINO_LED3, HIGH);
  }  
  if (distancia < 20) {
    digitalWrite(PINO_LED1, HIGH);
    digitalWrite(PINO_LED2, HIGH);
    digitalWrite(PINO_LED3, HIGH);
  } 
  if (distancia < 30) {
    digitalWrite(PINO_LED1, HIGH);
    digitalWrite(PINO_LED2, HIGH);
  }
  if (distancia < 40) {
    digitalWrite(PINO_LED1, HIGH);
  }
  
  delay(500);
}



