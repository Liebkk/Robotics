// 14º Projeto(A)_Buzzer controlado via Serial (ajuste de frequência em Hz)
// Gabriel Sassati da Costa

// Objetivo: Permitir que o usuário defina a frequência do buzzer pelo Monitor Serial
// Define o pino do buzzer
const int pinoBuzzer = 10;
// Variável para armazenar a frequência digitada pelo usuário
int frequencia = 0;
void setup() {
// Inicia a comunicação serial com velocidade de 9600 bits por segundo
Serial.begin(9600);
// Mensagem inicial para o usuário
Serial.println("Digite uma frequencia em Hz (ex: 500, 1000, 2000).");
Serial.println("Digite 0 para desligar o buzzer.");
}
void loop() {
// Verifica se existe algum dado disponível na porta serial
if (Serial.available() > 0) {
// Lê o valor inteiro digitado pelo usuário
frequencia = Serial.parseInt();
// Se a frequência for maior que 0, toca o buzzer
if (frequencia > 0) {
tone(pinoBuzzer, frequencia); // Emite o som na frequência digitada
Serial.print("Buzzer tocando em: ");
Serial.print(frequencia);
Serial.println(" Hz");
}
// Se a frequência for 0, desliga o buzzer
else {
noTone(pinoBuzzer);
// Para o som
Serial.println("Buzzer desligado.");
}
}
}