// 11º Projeto: S.O.S Sonoro com Buzzer.
// Gabriel Sassati da Costa

/*
S = . . . (três bips curtos)
O = – – – (três bips longos)
S = . . . (três bips curtos)
*/

// Define o pino do buzzer
int pinoBuzzer = 10;
// Define os tempos em milissegundos
int bipCurto = 200;
// Duração do bip curto (ponto)
int bipLongo = 600; // Duração do bip longo (traço)
int pausaCurta = 200; // Pausa entre sinais

int pausaLetra = 600; // Pausa entre letras (S e O)
int pausaFinal = 2000; // Pausa final antes de repetir

// Define a frequência do som em Hertz
int frequencia = 1500; // Frequência de 1500 Hz
void setup() {
/* O setup fica vazio neste projeto:
Em projetos com pinMode(...), usamos o setup() para configurar os pinos como OUTPUT, INPUT, etc.
Mas quando usamos a função tone(...), o Arduino não precisa que o pino seja configurado como saída com
pinMode(...). A função tone() já cuida disso internamente.
*/
}

void loop() {

  // Letra S
// Primeiro bip curto
tone(pinoBuzzer, frequencia); // Emite som de 1500 Hz
delay(bipCurto);
// Mantém o som por um tempo curto
noTone(pinoBuzzer); // Para o som
delay(pausaCurta);
// Pequena pausa

  // Segundo bip curto
tone(pinoBuzzer, frequencia);
delay(bipCurto);
noTone(pinoBuzzer);
delay(pausaCurta);

  // Terceiro bip curto
tone(pinoBuzzer, frequencia);
delay(bipCurto);
noTone(pinoBuzzer);
delay(pausaLetra);
// Pausa maior entre letras
  

  // Letra O
// Primeiro bip longo
tone(pinoBuzzer, frequencia);
delay(bipLongo);
noTone(pinoBuzzer);
delay(pausaCurta);

  // Segundo bip longo
tone(pinoBuzzer, frequencia);
delay(bipLongo);
noTone(pinoBuzzer);
delay(pausaCurta);

  // Terceiro bip longo
tone(pinoBuzzer, frequencia);
delay(bipLongo);
noTone(pinoBuzzer);
delay(pausaLetra);
  
  
  // Letra S
// Primeiro bip curto
tone(pinoBuzzer, frequencia);
delay(bipCurto);
noTone(pinoBuzzer);
delay(pausaCurta);

  // Segundo bip curto
tone(pinoBuzzer, frequencia);
delay(bipCurto);
noTone(pinoBuzzer);
delay(pausaCurta);
  
  // Terceiro bip curto
tone(pinoBuzzer, frequencia);
delay(bipCurto);
noTone(pinoBuzzer);
delay(pausaFinal);
// Pausa final antes de repetir o SOS
}