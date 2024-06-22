#include <WiFi.h>;
#include <WebServer.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>

String nome_wifi = "WIFI_DEV_CE025;
String senha = "s3s1s3na1d3v";

int pinoDHT = 4;
DHT dht(pinoDHT, DHT11);

// Inicialização do servidor web
WebServer server(80);

void setup() {
  Serial.begin(9600);

  dht.begin();

  conectarWiFi();

  server.on("/", paginaPrincipal); // Definição das rotas do servidor web
  server.begin(); // Inicia o servidor web  
}

void loop() {
  // Manipulação das requisições do servidor web
  server.handleClient();

  // Aguarda um intervalo antes de fazer a próxima leitura
  delay(2000);
}

// Função para lidar com a requisição da página inicial
void paginaPrincipal() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  String html = "<!DOCTYPE html><html><head><title>Temperatura e Umidade</title></head><body>";
  html += "<h1>Temperatura e Umidade</h1>";
  html += "<p>Umidade: " + String(umidade) + "%</p>";
  html += "<p>Temperatura: " + String(temperatura) + "°C</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void conectarWiFi() {
  WiFi.begin(nome_wifi, senha);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("WiFi conectado..! IP obtido ");
  Serial.println(WiFi.localIP());
}

