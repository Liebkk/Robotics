//16º Projeto(a): Potenciômetro
//Gabriel Sassati da Costa

/* Define o pino analógico A0 como a entrada onde o potenciômetro está conectado. Esse pino será usado
para ler o valor de tensão que o potenciômetro gera. */
int pinoPotenciometro = A0;

/* Define o pino digital 2 como a saída onde o LED está conectado. Esse pino será usado para controlar o
brilho do LED por PWM. */
int pinoLED = 2;

/* Cria uma variável chamada 'luminosidade' que armazenará o valor de brilho do LED, calculado com
base na leitura do potenciômetro. */
int luminosidade;

void setup() {
/* Configura o pino do LED (pino 2) como uma saída. Isso permite enviar sinais PWM para controlar o
brilho. */
pinMode(pinoLED, OUTPUT);
Serial.begin(9600);
}

void loop() {
/* Lê o valor do potenciômetro conectado ao pino A0. A função analogRead() retorna valores de 0 a 1023,
representando tensões de 0V a 5V. */
luminosidade = analogRead(pinoPotenciometro);

  /* Usa a função map() para converter o valor lido (0 a 1023) para o intervalo de 0 a 255, que é o intervalo
aceito pela função analogWrite(). Esse mapeamento é necessário porque PWM funciona com 8 bits (0–
255), enquanto a leitura analógica é de 10 bits (0–1023).
A função map(valor, valorMinEntrada, valorMaxEntrada, valorMinSaída, valorMaxSaída) transforma um
valor de uma faixa para outra proporcionalmente. */
luminosidade = map(luminosidade, 0, 1023, 0, 255);

  /* Envia o valor de brilho calculado (0 a 255) para o pino do LED. Isso faz com que o LED acenda com
brilho proporcional à posição do potenciômetro. */
analogWrite(pinoLED, luminosidade);

  /* Envia o valor da luminosidade para o Monitor Serial. Isso permite acompanhar no computador como o
valor varia quando você gira o potenciômetro. */
Serial.println(luminosidade);

  /* Pequena pausa de 10 milissegundos antes de repetir o processo. Isso ajuda a reduzir a quantidade de
dados no monitor serial e evita leituras muito rápidas. */
delay(10);
}