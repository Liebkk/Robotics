// 15º Projeto (a): Mensagem via serial
// Gabriel Sassati da Costa

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Numero: ");
  Serial.print(10);
  Serial.print(" - ");
  Serial.println("Fim da linha.");
  delay(1000);
}

/*
Neste projeto, Serial.print é usado para enviar "Número: " e “10” e " - ", todos na mesma linha. Em seguida,
Serial.println é usado para enviar “Fim da linha” e mover o cursor para a próxima linha, preparando o
monitor serial para a próxima série de dados.
*/