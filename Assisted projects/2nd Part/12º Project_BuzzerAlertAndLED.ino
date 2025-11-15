// 12º Projeto: Alerta com Buzzer e Led.
// Gabriel Sassati da Costa

// Define o pino do buzzer
int pinoBuzzer = 10;
// Define o pino do LED
int pinoLED = 9;
// Define o tempo que o som e o LED ficam ligados
int tempoAtivo = 300; // em milissegundos (0,3 segundos)
// Define o tempo de pausa entre os alertas
int tempoPausa = 300; // em milissegundos (0,3 segundos)
// Define a frequência do som em Hertz (Hz)
int frequencia = 2500; // som agudo de 2500 Hz

void setup() {
// Configura o pino do LED como saída
pinMode(pinoLED, OUTPUT);
// O pino do buzzer não precisa de pinMode, pois a função tone() já faz isso
}

void loop() {
// Liga o LED, acendendo a luz
digitalWrite(pinoLED, HIGH);
// Ativa o buzzer com frequência de 2500 Hz
tone(pinoBuzzer, frequencia); // emite o som
// Espera com som e luz ligados
delay(tempoAtivo);
// Desliga o LED
digitalWrite(pinoLED, LOW);
// Desliga o som do buzzer
noTone(pinoBuzzer); // para o som
// Espera a pausa antes de repetir
  delay(tempoPausa);
}