// Em C os blocos de comando devem estar entre { }
// No final de toda instrução (linha) devemos finalizar com ;

//Declarando variáveis globais
// Em C, na declaração de toda variável deve ser precedida do tipo
int pinLED = 2;

// esta função é a mesma coisa que o comando em Python
// def setup() :
void setup() {
  // Qualquer código inserido nesta função será executado uma
  // única vez quando o programa for iniciado, assim, esta área
  // é importante para indicarmos as configurações da placa
  // e definição de variáveis

  //A função pinMode define o comportamento um pino(porta)
  //No primeiro parâmetro enviamos o número do pino
  //No segundo parâmetro enviamos o comportamento dele OUTPUT / INPUT
  pinMode(pinLED, OUTPUT);
}

void loop() {
  // É a função onde deverá ficar a maiorio do código, esta função
  // ficará em loop executando o código transferido para a
  // placa e somente será finalizado após ser desligado

  //a função digitalWrite, envia um valor para uma porta digital
  //No primeiro parâmetro enviamos o número do pino
  //No segundo parâmetro enviamos se está ligado desligado (HIGH / LOW)
  digitalWrite(pinLED, HIGH);  //Acendendo o LED interno

  //A função delay tem o objetivo de pausar o nosso loop por um tempo
  //No parâmetro enviamos o valor em milisegundos
  delay(1000);  //1segundo

  digitalWrite(pinLED, LOW); //Apagando o LED Interno

  delay(1000);  //1segundo
}


