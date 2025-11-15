//9º Projeto: Controle de LED com Entrada Digital em Configuração Pull-Up Interno
//Gabriel Sassati da Costa

// Declaração das variáveis globais:
const int ledPin = 3; //Define o pino 3 como saída para o LED
const int Botao =  4; //Define o pino 4 como entrada para o botão
int estadoBotao; //Variável para armazenar o estado do botão (HIGH/LOW)


void setup() {
 //Configura os pinos:
  pinMode(ledPin, OUTPUT); //Define o pino do LED como saída
  pinMode(Botao, INPUT); //Define o pino do botão como entrada
}

void loop() {
  // Lê o estado atual do botão e armazena na variável estadoBotao
  
  estadoBotao = digitalRead(Botao);
  
  //Verifica o estado do botão
  if (estadoBotao == HIGH) {
    // Se o botão estiver pressionado (HIGH), acende o LED
    digitalWrite(ledPin, HIGH);
  }
  else {
    // Se o botão NÃO estiver pressionado (LOW), apaga o LED
    digitalWrite(ledPin, LOW);
  }
}