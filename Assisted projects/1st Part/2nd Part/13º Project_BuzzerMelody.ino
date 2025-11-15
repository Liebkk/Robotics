//13º Projeto: Melodia com Buzzer no Arduino (simples)
//Gabriel Sassati da Costa

void setup(){
// Define o pino 10 como saída digital para controlar o buzzer
pinMode(10, OUTPUT);
}
void loop(){
/*
Frequência das notas musicais:
Dó - 262 Hz
Ré - 294 Hz
Mi - 330 Hz
Fá - 349 Hz
Sol - 392 Hz
Lá - 440 Hz
Si - 494 Hz
#Dó - 528 Hz
*/
// Aguarda 1 segundo antes de começar a tocar as notas
delay(1000);
// Define a duração base das notas em milissegundos (400ms)
int tempo = 400;
// Toca a nota Lá (440 Hz) por 400ms
tone(10, 440, tempo);
// Espera 400ms
delay(tempo);
// Toca a nota Ré (294 Hz) por 400ms
tone(10, 294, tempo);
// Espera 400ms
delay(tempo);
// Toca a nota Fá (349 Hz) por 200ms
tone(10, 349, tempo / 2);
// Espera 200ms
delay(tempo / 2);
// Toca a nota Sol (392 Hz) por 200ms
tone(10, 392, tempo / 2);
// Espera 200ms
delay(tempo / 2);
// Toca novamente a nota Lá por 400ms
tone(10, 440, tempo);
// Espera 400ms
delay(tempo);
// Toca novamente a nota Ré por 400ms
tone(10, 294, tempo);
// Espera 400ms
delay(tempo);
// Toca novamente a nota Fá por 200ms
tone(10, 349, tempo / 2);
// Espera 200ms
delay(tempo / 2);
// Toca novamente a nota Sol por 200ms
tone(10, 392, tempo / 2);
// Espera 200ms
delay(tempo / 2);
// Toca a nota Mi (330 Hz) por 400ms
tone(10, 330, tempo);
// Espera 400ms
delay(tempo);
}