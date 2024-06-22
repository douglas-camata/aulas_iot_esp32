//Importação para WS do App
#include <WiFi.h>;
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

#include <ESP32Servo.h>

int LedVermVia1 = 15;
int LedAmarVia1 = 2;
int LedVerdeVia1 = 4;
int LedVermVia1P = 5;
int LedVerdeVia1P = 18;

int LedVermVia2 = 13;
int LedAmarVia2 = 12;
int LedVerdeVia2 = 14;
int LedVermVia2P = 27;
int LedVerdeVia2P = 26;

int ledsIluminacao = 19;
int LDR = 35;

//Variaveis de controle de tempo
int TempoLedVerm = 5000;
int TempoLedAmar = 1000;
int TempoLedVerde = 4000;

bool amareloPiscante = false;

bool iluminacao_ligada = false;

int pinoMotor = 21;
int PINO_TRIG = 22;
int PINO_ECHO = 23;

Servo meuServo;

//Credenciais da rede
const char* ssid = "WIFI_DEV_CONVIDADO";
const char* password = "semaforo";

void setup() {
  Serial.begin(9600);

  pinMode(LedVermVia1, OUTPUT);
  pinMode(LedAmarVia1, OUTPUT);
  pinMode(LedVerdeVia1, OUTPUT);
  pinMode(LedVermVia1P, OUTPUT);
  pinMode(LedVerdeVia1P, OUTPUT);
  pinMode(LedVermVia2, OUTPUT);
  pinMode(LedAmarVia2, OUTPUT);
  pinMode(LedVerdeVia2, OUTPUT);
  pinMode(LedVermVia2P, OUTPUT);
  pinMode(LedVerdeVia2P, OUTPUT);

  pinMode(ledsIluminacao, OUTPUT);

  pinMode(LDR, INPUT);

  meuServo.attach(pinoMotor);
  meuServo.write(0);

  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);

  // Cria a tarefa que verifica a luminosidade
  xTaskCreate(
    loopLuminosidade,        // Função que implementa a tarefa
    "TaskLoopLuminosidade",  // Nome da tarefa
    10000,                   // Tamanho da pilha em bytes
    NULL,                    // Parâmetro para a função
    1,                       // Prioridade da tarefa
    NULL                     // Handle da tarefa
  );


  ConectarWiFi();

  //Cria a tarefa que verifica os dados do WS
  xTaskCreate(
    BuscarDadosWS,  // Função que implementa a tarefa
    "TaskLoopWS",   // Nome da tarefa
    10000,          // Tamanho da pilha em bytes
    NULL,           // Parâmetro para a função
    1,              // Prioridade da tarefa
    NULL            // Handle da tarefa
  );

  //Cria a tarefa que verifica a distância e fecha a cancela do trem
  xTaskCreate(
    CancelaTrem,     // Função que implementa a tarefa
    "TaskLoopTrem",  // Nome da tarefa
    10000,           // Tamanho da pilha em bytes
    NULL,            // Parâmetro para a função
    1,               // Prioridade da tarefa
    NULL             // Handle da tarefa
  );
}

void loop() {
  if (amareloPiscante == true)
    LigarAmareloPiscante();
  else
    SemaforoNormal();
}

//Loop de luminosidade para verificar o LDR
void loopLuminosidade(void* parameter) {
  while (true) {

    int luminosidade = analogRead(LDR);

    if (luminosidade < 2000 or iluminacao_ligada) {
      digitalWrite(ledsIluminacao, HIGH);
    } else {
      digitalWrite(ledsIluminacao, LOW);
    }
    Serial.println("lum.: " + String(luminosidade));

    //Delay para esperar quando será executada novamente a tarefa
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void ConectarWiFi() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Conectado");
  Serial.println(WiFi.localIP());
}

//Loop para Buscar dados do WS
void BuscarDadosWS(void* parameter) {
  while (true) {

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient client;
      client.begin("https://api1sem2024.azurewebsites.net/obterDados");
      int httpCode = client.GET();

      if (httpCode > 0) {
        String payload = client.getString();
        // Serial.println(payload);

        // Processar o JSON recebido
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, payload);

        if (!error) {
          // Atualizar as variáveis de tempo com os valores recebidos
          TempoLedVerde = doc["tempo_verde_via_1"];
          TempoLedVerm = doc["tempo_vermelho_via_1"];
          amareloPiscante = doc["amarelo_piscante_via_1"];
          iluminacao_ligada = doc["iluminacao_ligada"];
        } else {
          Serial.print("Erro ao analisar JSON: ");
          Serial.println(error.c_str());
        }
        Serial.println("Tempos VD " + String(TempoLedVerde) + " VM " + String(TempoLedVerm) + " Pisc. " + String(amareloPiscante));
      } else {
        Serial.print("Erro ao conectar: ");
        Serial.println(httpCode);
      }
      client.end();
    } else {
      Serial.println("Sem conexão");
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void CancelaTrem(void* parameter) {
  while (true) {
    digitalWrite(PINO_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PINO_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PINO_TRIG, LOW);

    long duracao = pulseIn(PINO_ECHO, HIGH);
    int distancia = (duracao * 0.0343) / 2;
    if (distancia < 20) {
      meuServo.write(90);
    } else {
      meuServo.write(0);
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void LigarAmareloPiscante() {
  apagarLeds();
  delay(1000);
  digitalWrite(LedAmarVia1, HIGH);
  digitalWrite(LedAmarVia2, HIGH);
  delay(1000);
}

void SemaforoNormal() {
  apagarLeds();
  digitalWrite(LedVerdeVia1, HIGH);
  digitalWrite(LedVermVia1P, HIGH);
  digitalWrite(LedVermVia2, HIGH);
  digitalWrite(LedVerdeVia2P, HIGH);
  delay(TempoLedVerde);

  digitalWrite(LedVerdeVia1, LOW);
  digitalWrite(LedAmarVia1, HIGH);
  delay(TempoLedAmar);

  apagarLeds();
  digitalWrite(LedVermVia1, HIGH);
  digitalWrite(LedVerdeVia1P, HIGH);
  digitalWrite(LedVerdeVia2, HIGH);
  digitalWrite(LedVermVia2P, HIGH);
  delay(TempoLedVerm);

  digitalWrite(LedVerdeVia2, LOW);
  digitalWrite(LedAmarVia2, HIGH);
  delay(TempoLedAmar);
}

void apagarLeds() {
  digitalWrite(LedVermVia1, LOW);
  digitalWrite(LedAmarVia1, LOW);
  digitalWrite(LedVerdeVia1, LOW);
  digitalWrite(LedVermVia1P, LOW);
  digitalWrite(LedVerdeVia1P, LOW);
  digitalWrite(LedVermVia2, LOW);
  digitalWrite(LedAmarVia2, LOW);
  digitalWrite(LedVerdeVia2, LOW);
  digitalWrite(LedVermVia2P, LOW);
  digitalWrite(LedVerdeVia2P, LOW);
}
