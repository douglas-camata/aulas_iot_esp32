//Importando a biblioteca de WiFi que utilizaremos
#include <WiFi.h>;

//Definindo as variáveis com o nome da rede e a senha
String nome_wifi = "Wokwi-GUEST";
String senha = "";

void setup() {
  Serial.begin(9600);

  //Chamando função que criamos para configurar e conectar a WiFi
  conectarWiFi();
}

void loop() {

}

//Função criada com o objetivo de fazer a configuração e conexão com a rede
void conectarWiFi() {
  //Inicia conexão WiFi passando como parâmetro nome da rede e a senha
  WiFi.begin(nome_wifi, senha);
  Serial.print("Conectando à ");
  Serial.println(nome_wifi);

  //While para tentar conectar, enquanto não se conectar ele não continua
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("WiFi conectado..! IP obtido");
  //Exibindo no Monitor Serial o IP do ESP32
  Serial.println(WiFi.localIP());
}

