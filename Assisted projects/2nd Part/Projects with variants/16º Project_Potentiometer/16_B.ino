//16º Projeto(b): Potenciômetro
//Gabriel Sassati da Costa

/* Define o pino analógico A0 como a entrada onde o potenciômetro está conectado. Esse pino será usado
para ler a posição (valor) do potenciômetro.*/
int pinoPotenciometro = A0;

/* Define o pino digital 2 como a saída onde o LED está conectado. Esse pino será usado para controlar o
brilho do LED. */
int pinoLED = 2;

/* Cria uma variável que armazenará o valor lido do potenciômetro. Esse valor varia entre 0 e 1023,
conforme a rotação do eixo do potenciômetro. */
int valorPotenciometro;

void setup() {
/* Configura o pino do LED (pino 2) como uma saída. Isso é necessário para que possamos enviar sinais
(valores de PWM) para ele. */
pinMode(pinoLED, OUTPUT);

/* Inicia a comunicação serial com o computador com uma taxa de 9600 bits por segundo. Isso permite
visualizar no Monitor Serial o valor lido do potenciômetro. */
Serial.begin(9600);
}

void loop() {
/* Lê o valor analógico do potenciômetro conectado ao pino A0. A função analogRead() retorna um valor
entre 0 e 1023, onde 0 representa 0V e 1023 representa 5V (ou 3.3V, dependendo da placa). */
valorPotenciometro = analogRead(pinoPotenciometro);

  /* Envia o valor lido do potenciômetro para o Monitor Serial. Isso é útil para o usuário acompanhar como o
valor muda conforme gira o botão. */
Serial.println(valorPotenciometro);

  /* Converte o valor lido (0 a 1023) para um intervalo entre 0 e 255, que é o intervalo aceito pela função
analogWrite() para PWM (modulação por largura de pulso). Isso controla o brilho do LED de forma
proporcional ao valor do potenciômetro. Dividimos por 4 porque 1023 / 4 = 255,75. */
analogWrite(pinoLED, valorPotenciometro / 4);

  /* Aguarda 100 milissegundos antes de repetir o processo. Isso reduz a velocidade do loop e evita
atualizações muito rápidas que podem tornar os dados no monitor serial difíceis de acompanhar. */
delay(100);
}