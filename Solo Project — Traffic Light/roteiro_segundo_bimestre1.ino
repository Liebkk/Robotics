// Roteiro - 1ª Etapa: Projeto semáforo com botão de pedestre
// Gabriel Sassati da Costa

// Definindo pinos
// Semáforo dos carros
const int ledVerdeCar = 11;
const int ledAmareloCar = 12;
const int ledVermelhoCar = 8; 

// Semáforo dos pedestres
const int ledVerdePed = 9;
const int ledVermelhoPed = 10;

// Botão
const int botao = 6;

// Variáveis de controle
int etapa = 0;               // Etapa do ciclo do semáforo
int botaoAnterior = LOW;     // Estado anterior do botão

void setup() {
  // Definindo os pinos como saída ou entrada
  pinMode(ledVerdeCar, OUTPUT);
  pinMode(ledAmareloCar, OUTPUT);
  pinMode(ledVermelhoCar, OUTPUT);
  pinMode(ledVerdePed, OUTPUT);
  pinMode(ledVermelhoPed, OUTPUT);
  pinMode(botao, INPUT);

  // Estado inicial: carros no verde, pedestres no vermelho
  digitalWrite(ledVerdeCar, HIGH);
  digitalWrite(ledVermelhoPed, HIGH);
}

void loop() {
  // Leitura do botão
  int leituraBotao = digitalRead(botao);

  if (leituraBotao == HIGH && botaoAnterior == LOW && etapa == 0) {
    etapa = 1;  // Inicia o ciclo ao pressionar o botão
  }
  botaoAnterior = leituraBotao;

  // Etapa 1: Amarelo para os carros
  if (etapa == 1) {
    digitalWrite(ledVerdeCar, LOW);      // Apaga verde
    digitalWrite(ledAmareloCar, HIGH);   // Acende amarelo
    delay(1000);                         // Espera 1 segundo
    digitalWrite(ledAmareloCar, LOW);    // Apaga amarelo
    etapa = 2;
  }

  // Etapa 2: Vermelho para os carros
  if (etapa == 2) {
    digitalWrite(ledVermelhoCar, HIGH);  // Acende vermelho dos carros
    delay(500);                          // Pequena pausa
    etapa = 3;
  }

  // Etapa 3: Verde para pedestre
  if (etapa == 3) {
    digitalWrite(ledVermelhoPed, LOW);   // Apaga vermelho dos pedestres
    digitalWrite(ledVerdePed, HIGH);     // Acende verde do pedestre
    delay(3000);                         // Tempo para atravessar
    etapa = 4;
  }

  // Etapa 4: Piscar verde do pedestre
  if (etapa == 4) {
    digitalWrite(ledVerdePed, LOW); delay(300);
    digitalWrite(ledVerdePed, HIGH); delay(300);
    digitalWrite(ledVerdePed, LOW); delay(300);
    digitalWrite(ledVerdePed, HIGH); delay(300);
    digitalWrite(ledVerdePed, LOW); delay(300);
    etapa = 5;
  }

  // Etapa 5: Resetar para o estado inicial
  if (etapa == 5) {
    // Pedestre: vermelho
    digitalWrite(ledVerdePed, LOW);
    digitalWrite(ledVermelhoPed, HIGH);

    // Carros: verde
    digitalWrite(ledVermelhoCar, LOW);
    digitalWrite(ledVerdeCar, HIGH);

    etapa = 0;  // Reinicia o ciclo
  }
}
