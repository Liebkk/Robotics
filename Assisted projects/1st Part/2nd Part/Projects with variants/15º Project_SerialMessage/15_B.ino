//15º Projeto (b): Mensagem via serial.
//Gabriel Sassati da Costa

/*
A instrução while é uma estrutura de controle de fluxo que cria um loop, ou seja, um ciclo que repete um
bloco de código enquanto uma condição específica é verdadeira. No caso do código while (!Serial){,
estamos lidando com um loop que continuará a executar enquanto a condição !Serial for verdadeira.
Para entender melhor a condição !Serial:
Serial: É um objeto que representa a porta serial no Arduino. A comunicação serial é uma forma de
transmissão de dados onde os bits são enviados um após o outro ao longo de um único fio (em série). No
Arduino, a comunicação serial é frequentemente usada para enviar dados para o computador ou receber
dados dele.
!: É o operador lógico NOT em C++. Quando usado antes de uma condição, ele inverte o valor booleano
da condição. Se a condição original for verdadeira, o NOT a torna falsa, e vice-versa. Portanto, !Serial
verifica se o objeto Serial não está pronto para a comunicação. Em outras palavras, ele verifica se a ]
comunicação serial não foi estabelecida. Se Serial for falso (o que significa que a comunicação serial não
está pronta), a condição !Serial se torna verdadeira, e o loop while continua.
*/

void setup (){
  Serial.begin(9600);
  while (!Serial){
//Aguarda o estabelecimento da conexão
}

Serial.print("Hello World!!!");
}

void loop (){
}

/*
Quando o Arduino é ligado ou reiniciado, a função setup() é chamada. Dentro dela, Serial.begin(9600);
inicia a comunicação serial com uma taxa de transmissão de 9600 bauds. No entanto, em algumas placas
Arduino, como o Arduino Leonardo ou o Arduino Micro, a conexão serial com o computador pode levar
algum tempo para ser estabelecida. Durante esse tempo, se tentarmos enviar dados pela porta serial
usando Serial.print(), esses dados podem ser perdidos porque a conexão ainda não está pronta.
O loop while (!Serial){} é uma forma de garantir que o código aguarde até que a comunicação serial esteja
pronta antes de prosseguir. Ele faz o programa ficar “preso” nesse loop até que a conexão serial esteja
estabelecida. Assim que a conexão estiver pronta, a condição !Serial se tornará falsa, o loop será
interrompido, e o programa prosseguirá para a próxima linha, que é Serial.print("Hello World!!!");, enviando
a mensagem “Hello World!!!” pela porta serial.
*/