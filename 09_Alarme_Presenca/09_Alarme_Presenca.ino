int PINO_TRIG = 18; 
int PINO_ECHO = 19; 
int PINO_LED1 = 22;  
int PINO_BUZZER = 15; 
 
void setup() {
  Serial.begin(9600); 
  pinMode(PINO_TRIG, OUTPUT); 
  pinMode(PINO_ECHO, INPUT);  
  pinMode(PINO_LED1, OUTPUT);
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
  
  digitalWrite(PINO_LED1, LOW);
  noTone(PINO_BUZZER);
  
  if (distancia < 150) {
    digitalWrite(PINO_LED1, HIGH);
    tone(PINO_BUZZER, 1000, 500);
    delay(500);
    digitalWrite(PINO_LED1, LOW);
    tone(PINO_BUZZER, 800, 500);
    delay(500);
  }  
}