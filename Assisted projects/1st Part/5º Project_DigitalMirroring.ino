//5º Projeto: Espelhamento digital com variáveis no Arduino
// Gabriel Sassati

/*
Criamos uma variável chamada pinoLED e atribuímos o valor 13, porque o LED 
está conectado ao pino digital 13 do Arduino. 
Declarar dessa forma torna o código mais organizado, fácil de entender e de 
modificar posteriormente, caso o pino precise ser alterado.
Essa prática também melhora a manutenção e o reaproveitamento do código em outros projetos.
*/

int pinoLED = 13;

/*
Criamos uma variável chamada pinoBotao e atribuímos o valor 7, pois o botão
está conectado ao pino digital 7 do Arduino.
O tipo 'int' (abreviação de "integrar", em inglês) significa que a variável
armazenará um número inteiro, ou seja, sem casas decimais.
No Arduino, utilizamos 'int' para representar pinos digitais, leituras de
estado (HIGH or LOW) e contadores, pois essas informações são expressas em
número inteiros.
Escolhemos o tipo 'int' porque a leitura digital e a definição de pinos
trabalham apenas com os valores 0 ou 1, e o 'int' é apropriado para essa
finalidade.
*/

  int pinoBotao = 7;
  
/*
A variável valorLido servirá para armazenar temporariamente o valor capturado
do botão: 0 (low) ou 1 (HIGH).
Essa estratégia de armazenamento é fundamental para reutilizarmos o valor lido
sem a necessidade de fazer a leitura toda vez que quisermos usá-lo.
Também utilizamos o tipo 'int' para essa variável, pois o valor retornado por uma 
leitura digital é um número inteiro.
Manter o valor em uma variável melhora a organização, facilira o entendimento do 
fluxo do programa e permite realizar verificações ou controles futuros se necessário
*/
  
  int valorLido = 0;

void setup() {
//COnfiguramos o pino do botão entrada, pois lhe irá receber sinais externos (do botão)
  pinMode(pinoBotao, INPUT);
  
/*Configuramos o pino do LED como saída, pois enviaremos sinais elétricos 
para controlar o LED (acender ou apagar)
*/
  pinMode(pinoLED, OUTPUT);

/*
- Leitura de estado do botão (entrada digital):
Utilizamos o comando digitalRead(pinoBotao) para ler o valor atual do pino digital 7.
O Arduino verifica se o botão está sendo pressionado (HIGH) ou não (LOW) e devolve
esse valor.
Armazenamos o resultado na variável valorLido, para reaproveitar o valor em outras 
partes do programa.
Dessa maneira, a variável valorLido sempre refletirá o estado atual do botão.
*/

  valorLido = digitalRead(pinoBotao);

/*
- Escrita do estado no LED (saída digital):
Usamos o comando digitalWrite(pinoLED, valorLido) para enviar o valor armazenado em
valorLido for igual a 1 (HIGH), o LED acenderá. Se valorLido for igual a 0 (LOW), o
LED se apagará.
Essa técnica cria um "espelhamento digital", pois o comportamento do LED é diretamen-
te condicionado ao estado do botão, sem necessidade de estruturas condicionais (como if).
Essa abordagem é muito eficiente em sistemas de Robótica básica, onde sensores e 
atuadores precisam ser sincronizados rapidamente de forma direta.
*/
  
  digitalWrite(pinoLED, valorLido);
}

/*
Explicação: Funcionamento do Botão

No proejto de robótica, o botão é utilizado com um dispositivo de ENTRADA digital.
Isso significa que ele envia um sinal elétrico (0 ou 1) para o Arduino, indicando 
se está sendo pressionado ou não.

Fisicamente, o botão funciona como um interruptor:
- Quando NÃO está pressionado, o circuito está ABERTO (sem passagem de corrente), e 
o Arduino lê um valor de 0 (LOW).
- Quando está pressionado, o circuito é FECHADO (há passagem de corrente), e o Arduino
lê um valor de 1 (HIGH).

Neste projeto, o LED depende diretamente do valor lido no botão. Portanto:
- Enquanto o botão estiver pressionado (circuito fechado), o valor lido será 1 e o
LED será aceso.
- Se o botão for solto (circuito aberto), o valor lido será 0 e o LED será apagado.

IMPORTANTE: usamos ym resistor pull-down no botão. Mas o que isso significa?

Um resistor pull-down (traduzido como "puxar para baixo") é um resistor conectado
entre o pino de entrada do Arduino e o GND (terra).
Sua função é garantir que, quando o botão não estiver pressionado, o pino seja mantido
em nível baixo (LOW = 0).
Sem o resistor pull-down, o pino de entrada poderia "flutuar", ou seja, ficar indefinido
- podendo apresentar leituras aleatórias, causando comportamento instável no programa
(por exemplo, o LED piscando sozinho sem o botão ser pressionado). Assim, o pull-down
atua como uma âncora elétrica, mantendo o sinal estável em 0 quando o botão está solto.

Resumo:
- Botão solto + pull-down = pino recebe 0 (LOW).
- Botão pressionado = pino recebe 1 (HIGH) porque a corrente flui do +5v.
Essa configuração é muito comum em projetos de robótica, pois ajuda a tornar o sistema 
estável, confiável e previsível.
*/