// 10° Projeto: Beep com buzzer (piezo)
// Gabriel Sassati da Costa

/*
Constante que representa o pino digital onde o terminal positivo
do buzzer está conectado. O terminal negativo do buzzer está 
conectado ao GND, preferencialmente com um resistor de proteção
*/

const int buzzer = 10;

void setup() {
  //configura o pino do buzzer como saída digital.
  pinMode(buzzer, OUTPUT);
}

void loop() {
/*
Ativa o buzzer gerando um som com frequência de 1500hz. A função tone(pino, frequencia)
envia uma onda quadrada de determinada frequência para o pino especificado.
Essa onda faz com que o buzzer vibre e emita um som audível.
*/
  tone(buzzer, 1500);
    //mantém o som ativado por 500ms
  delay(700);
  
/*
Desativa o buzzer interrompendo a emissão de som. 
A função noTone(pino) desliga o sinal gerado pelo comando tone(), silenciando o pino
indicado.
*/
  noTone(buzzer);
  
//Aguarda 500ms antes de reiniciar o ciclo
  delay(700);
}