//7º Projeto: Semáforo de pedestre com botão (sem estruturas condicionais)
//Gabriel Sassati

int ledVerdePedestre = 13;
int ledVermelhoPedestre = 12;
int botao = 7;
int estadoBotao = 0;

void setup () {
  pinMode(ledVerdePedestre, OUTPUT);
  pinMode(ledVermelhoPedestre, OUTPUT);
  pinMode(botao, INPUT);
  
/*
Essas duas linhas definem o estado inicial do semáforo de pedestre assim que o 
arduino é ligado.
 Explicação:
  - Antes de qualquer ação do botão, o pedestre deve estar "parado".
  -Por isso, o LED verde (andar) começa apagado, e o LED vermelho (pare) começa aceso.
  -Isso garante segurança: o sistema inicia bloqueando a travessia até que o botão 
seja pressionado.
  -Colocamos isso dentro do setup() porque essa configuração só precisa acontecer uma
vez, na hora em que o arduino é ligado ou reiniciado.
*/
  digitalWrite(ledVerdePedestre, LOW);
  digitalWrite(ledVermelhoPedestre, HIGH);
}

void loop() {
  estadoBotao = digitalRead(botao); //Lê o botão uma vez por ciclo
  
  //Fase de travessia do pedestre - só acontece se o botão foi pressionado
  digitalWrite(ledVerdePedestre, estadoBotao);
  digitalWrite(ledVermelhoPedestre, !estadoBotao);
  delay(estadoBotao * 4000); //Se botão = 1, espera 4s, se 0, espera 0s

  //Fase de retorno: sempre volta para o vermlho
  digitalWrite(ledVerdePedestre, LOW);
  digitalWrite(ledVermelhoPedestre, HIGH);
  delay(1000); //Espera antes de aceitar novo clique
}

/*
Estas duas linhas controlam o LED vermelho do pedestre e o tempo da travessia.

1. digitalWrite(ledVermelhoPedestre, !estadoBotao);

 -O símbolo de exclamação (!) é o operador de negação lógica.
 -Ele inverte o valor da variável:
   -Se 'estadoBotao' for 1 (botão pressionado), '!estadoBotao' será 1.
 -O LED vermelho será aceso.
 -Isso faz com que o LED vermelho faça sempre o oposto do verde, mantendo o
controle visual do semáforo.

2. delay(estadoBotao * 4000);

-Esta linha faz uma multiplicação direta:
 -Se 'estadoBotao' for 1 (botão pressionado), o delay será `1 * 4000` = 4000 
milissegundos (4 segundos).
 -SE 'estadoBotao' for 0 (botão não pressionado), o delay será `0 * 4000 =
0 milissegundos - ou seja, o código segue imediatamente.
-Isso simula uma decisão condicional sem usar if: o Arduino só "espera" se o botão
tiver sido pressionado.
-Durante esses 4 segundos, o LED verde permanece aceso, permitido a travessia do
pedestre.

Essa lógica é ideal para ensinar como usar operações matemáticas simples (como
multiplicação e negação) para simular condições básicas no arduino.
*/
