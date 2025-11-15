//16º Projeto: Potenciômetro
//Gabriel Sassati da Costa

/* Define o pino analógico A0 como a entrada onde o potenciômetro está conectado. Esse pino será usado para
ler a tensão variável que o potenciômetro fornece, dependendo da posição do seu eixo. */

int pinoPotenciometro = A0;

/* Cria uma varoável do tipo inteiro chamada 'valorLido'. Essa variável armazenará o valor retornado pela
função analogRead(), que pode variar entre 0 e 1023. */

int valorLido = 0;

void setup(){
/* Inicializa a comunicação serial entre o arduino e o computador, com uma taxa de transmissão de 9600 bits
por segundo (bauds). Isso permite que os dados lidos pelo arduino sejam enviados e visualizados no Monitor
Serial da IDE. */
  Serial.begin(9600);
}

void loop(){
/* Realiza a leitura da tensão no pino analógico A0, onde o potenciômetro está conectado. A função 
analogRead() retorna um valor entre 0 e 1023, proporcional à tensão lida, que pode variar de 0V (mínimo) a 
5V (Máximo), dependendo da rotação do potenciômetro. */
  valorLido = analogRead(pinoPotenciometro);
  
/* Envia uma mensagem para o monitor serial, contendo o texto explicativo e o valor lido do potenciômetro.
O comando Serial.print() escreve o texto, e Serial.println() imprime o valor e pula para a próxima linha. */
  Serial.print("Valor do potenciometro: ");
  Serial.println(valorLido);
  
/* Insere uma pausa de 200ms (0,2s) entre cada leitura. Isso evita que ps valores sejam atualizados rápido
demais, facilitando a visualização das mudanças no Monitor Serial. */
  delay(200);
}

/* 
1. Explicação tecnica sobre o potenciômetro
Um potenciometro é um componente eletrônico do tipo resistor variável. Ele possui 3 terminais:

Dois terminais externos ligados aos extremos de uma resistência fixa.

Um terminal central (o cursor ou "pino do meio") que desliza sobre a resistência.

Quando giramos o eixo do potenciometro, o terminal central se move ao longo da resistência, alterando a 
proporção da tensão entre os terminais. Essa tensão variável pode ser lida pelo arduino como um valor
analógico usando a função analogRead().

O arduino possui um conversor analógico-digital (ADC) de 10 bits, que transforma essa tensão (de 0V a 5V)
em um valor entre 0 e 1023. Isso permite que o arduino entenda a posição atual do potenciometro e usa esse 
varir para controlar outros dipositivos.

2. Explicação simples:

O potenciômetro é um botão giratório que funciona como um volume de rádio. Ele muda a força do sinal (tensão)
conforme você gira.

O arduino consegue "ver" essa mudança usando um fio ligado ao meio do potenciômetro. Quando você gira o botão,
o arduino lê um número que vai de 0 até 1023. Esse número representa o quanto o botão foi girado, e podemos
usar esse número para controlar coisas, como acender ou apagar um LED com mais ou menso brilho. */
