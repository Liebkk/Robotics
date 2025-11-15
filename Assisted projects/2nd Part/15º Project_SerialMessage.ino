// 15º Projeto: Mensagem via serial
// Gabriel Sassati da Costa

const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
// Envia uma mensagem para o monitor serial
  Serial.println("LED aceso!");
  delay(1000);
  digitalWrite(led, LOW);
// Envia outra mensagem para o monitor serial
  Serial.println("LED apagado!");
  delay(1000);
}