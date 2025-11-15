//4º Projeto: Intercalação entre LEDs Verde e Vermelho
//Gabriel Sassati

void setup() {

  // Configura os pinos 12 e 13 como saída
  pinMode(12, OUTPUT); // LED Verde
  pinMode(13, OUTPUT); // LED Vermelho
  // Inicia a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Liga o LED Verde (pino 12) e desliga o LED Vermelho (pino 13)
  digitalWrite(12, HIGH); // Verde ligado
  digitalWrite(13, LOW); // Vermelho desligado
  Serial.println("Verde ligado e vermelho desligado");
  delay(1000); // Espera 1 segundo
  
  // Liga o LED Vermelho (pino 13) e desliga o LED Verde (pino 12)
  digitalWrite(12, LOW); // Verde desligado
  digitalWrite(13, HIGH); // Vermelho ligado
  Serial.println("Vermelho ligado e verde desligado");
  delay(1000); // Espera 1 segundo
}