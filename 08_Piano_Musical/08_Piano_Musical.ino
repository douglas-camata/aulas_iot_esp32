int buzzer = 23;
int C = 15;
int D = 4;
int E = 5;
int F = 18;
int G = 19;
int A = 21;
int B = 22;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(C, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  pinMode(F, INPUT_PULLUP);
  pinMode(G, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
}

void loop() {
  noTone(buzzer);
  if (digitalRead(C) == LOW) {
    tone(buzzer, 262); 
  }else if (digitalRead(D) == LOW) {
    tone(buzzer, 294); 
  }else if (digitalRead(E) == LOW) {
    tone(buzzer, 330); 
  }else if (digitalRead(F) == LOW) {
    tone(buzzer, 349); 
  }else if (digitalRead(G) == LOW) {
    tone(buzzer, 392); 
  }else if (digitalRead(A) == LOW) {
    tone(buzzer, 440); 
  }else if (digitalRead(B) == LOW) {
    tone(buzzer, 494); 
  } else {
    noTone(buzzer);
  }
  delay(50);
}