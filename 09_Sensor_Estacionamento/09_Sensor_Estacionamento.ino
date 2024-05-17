int PINO_TRIG = 18; 
int PINO_ECHO = 19; 
int PINO_LED1 = 21;  
int PINO_LED2 = 22;  
int PINO_LED3 = 23; 
int PINO_BUZZER = 15; 
 
void setup() {
  Serial.begin(9600); 
  pinMode(PINO_TRIG, OUTPUT); 
  pinMode(PINO_ECHO, INPUT);  
  pinMode(PINO_LED1, OUTPUT);
  pinMode(PINO_LED2, OUTPUT);
  pinMode(PINO_LED3, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
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
  noTone(PINO_BUZZER);

  if (distancia < 5) {
    digitalWrite(PINO_LED3, HIGH);
    tone(PINO_BUZZER, 262);
  }  
  else if (distancia < 15) {
    digitalWrite(PINO_LED2, HIGH);
    tone(PINO_BUZZER, 262, 100);
  } 
  else if (distancia < 30) {
    digitalWrite(PINO_LED1, HIGH);
    tone(PINO_BUZZER, 262, 100);
    delay(300);
  }
  
  delay(300);
}



