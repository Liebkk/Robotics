//6º Projeto: Controle de semáforo com LEDs no Arduino (Simples).
//Gabriel Sassati

int ledVerde = 13; // LED Verde conectado ao pino 13
int ledAmarelo = 12; // LED Amarelo conectado ao pino 12
int ledVermelho = 11; // LED Vermelho conectado ao pino 11

// Função setup(): executada uma única vez quando o Arduino é ligado ou reiniciado
void setup() {
  pinMode(ledVerde, OUTPUT); // Define o pino do LED Verde como saída
  pinMode(ledAmarelo, OUTPUT); // Define o pino do LED Amarelo como saída
  pinMode(ledVermelho, OUTPUT); // Define o pino do LED Vermelho como saída
}

// Função loop(): executada continuamente enquanto o Arduino estiver ligado
void loop() {
  // Acende o LED Verde
  digitalWrite(ledVerde, HIGH);
  delay(4000);
  // Espera 4 segundos
  digitalWrite(ledVerde, LOW); // Apaga o LED Verde
  // Acende o LED Amarelo
  digitalWrite(ledAmarelo, HIGH);
  delay(2000);
  // Espera 2 segundos
  digitalWrite(ledAmarelo, LOW); // Apaga o LED Amarelo
  // Acende o LED Vermelho
  digitalWrite(ledVermelho, HIGH);
  delay(4000);
  // Espera 4 segundos
  digitalWrite(ledVermelho, LOW); // Apaga o LED Vermelho
}