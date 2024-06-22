#include <WiFi.h>
#include <WebServer.h>


#include "DHT.h"
#include <Adafruit_Sensor.h>
int pinoDHT = 4;
DHT dht(pinoDHT, DHT11);

// Definições de rede
String nome_wifi = "WIFI_DEV_CE025";
String senha = "s3s1s3na1d3v";

const int ledPin = 2;

// Inicialização do servidor web
WebServer server(80);

void setup() {
  Serial.begin(9600);
  
  dht.begin();

  pinMode(ledPin, OUTPUT);

  conectarWiFi();
  
  server.begin();  // Inicia o servidor web
  
}

void loop() {
  // Manipulação das requisições do servidor web
  server.handleClient();
  delay(100);
}

void conectarWiFi() {
  WiFi.begin(nome_wifi, senha);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("WiFi conectado..! IP obtido ");
  Serial.println(WiFi.localIP());

  // Definição das rotas do servidor web
  server.on("/", pgPrincipal);
  server.on("/on", pgLedOn);
  server.on("/off", pgLedOff);
}


// Função para lidar com a página inicial
void pgPrincipal() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  String html = "<!DOCTYPE html><html><head>";
  html += "<title>Controle de LED</title></head><body>";
  
  html += "<h1>Temperatura e Umidade</h1>";
  html += "<p>Umidade: " + String(umidade) + "%</p>";
  html += "<p>Temperatura: " + String(temperatura) + "°C</p>";

  html += "<h1>Controle de LED</h1>";
  html += "<p><a href=\"/on\"><button>Ligar LED</button></a></p>";
  html += "<p><a href=\"/off\"><button>Desligar LED</button></a></p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

// Função para lidar com o comando de ligar o LED
void pgLedOn() {
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

// Função para lidar com o comando de desligar o LED
void pgLedOff() {
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

