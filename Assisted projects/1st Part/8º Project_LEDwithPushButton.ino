//8º Projeto: LED com push button (pressionado)
//Gabriel Sassati

/*Estamos declarando uma constante chamada led e atribuindo o valor 2 a ela. Essa constante será usada
para representar o número do pino ao qual o LED está conectado, */
const int led = 2;

/*Estamos declarando uma constante chamada botão e atribuido o valor 4 a ela. Essa constante representa
o número do pino ao qual o botão está conectado.*/
const int botao = 4;
  
/*Estamos declarando uma variável chamada EstadoBotao do tipo inteiro e inicializando-a com o valor 0. Essa
variável será usada para armazenar o estado do botão (se está pressionado ou não).*/
int estadoBotao = 0;
  
void setup() {
    pinMode(led, OUTPUT);
    pinMode(botao, INPUT);
}

void loop() {
  estadoBotao =digitalRead(botao);
  
  /*Nesta parte, estamos usando uma estrutura condiconal (if e else) para verificar o estado armazenado 
em estadoBotao. Se estadoBotao for igual a HIGH, significa que o botão está pressionado. Nesse caso,
utilizamos digitalWrite(led, HIGH) para acender o LED (configurando o pino referente ao LED como HIGH).
Se estadoBotao for igual a LOW, significa que o botão não está pressionado, então utilizamos digitalWrite
(led, LOW) para apagar o LED (configurando o pino referente ao LED como LOW)*/
  
  if (estadoBotao == HIGH) {
    digitalWrite(led, HIGH);
    //Botão pressionado liga o LED
  } else {
    digitalWrite(led, LOW);
    //Botão não pressionado, apaga o LED
  }
}