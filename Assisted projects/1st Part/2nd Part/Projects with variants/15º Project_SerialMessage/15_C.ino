// 15º Projeto (c): Mensagem via serial
// Gabriel Sassati da Costa

void setup(){
Serial.begin(9600);
}

/*
A função Serial.available() é usada para verificar se há dados disponíveis para leitura na porta serial do
Arduino. Aqui está o que acontece nesta linha de código:
Serial: É um objeto que representa a porta serial do Arduino. Através dele, podemos enviar e receber
dados via comunicação serial.
.available(): Este é um método do objeto Serial. Quando chamado, ele retorna o número de bytes
(caracteres) disponíveis para leitura na porta serial.
>0: Este é um operador de comparação. Estamos verificando se o valor retornado por Serial.available() é
maior que zero.
Quando colocamos tudo isso dentro de uma instrução if, estamos dizendo ao Arduino para executar o
código dentro das chaves {} somente se houver pelo menos um byte de dados disponível para leitura. Em
outras palavras, se um dispositivo conectado ao Arduino enviou dados pela porta serial, e esses dados
chegaram e estão esperando na fila de entrada serial para serem lidos, então o número retornado por
Serial.available() será maior que zero, e o código dentro do if será executado.
char recebeuChar = Serial.read();
Serial.read(): Esta função lê o próximo byte de dados disponível na porta serial. No contexto do Arduino, a
comunicação serial é frequentemente usada para trocar dados entre o Arduino e um computador ou outro
dispositivo. Cada byte de dados é geralmente interpretado como um caractere no padrão ASCII.
O Arduino executa os seguintes passos:
Verifica a fila de entrada serial: O Arduino olha para a fila de entrada serial para ver se há algum byte de
dados que foi recebido e está esperando para ser processado.
Lê o próximo byte: Se houver dados na fila, Serial.read() lê o próximo byte disponível.
Armazena o byte na variável: O byte lido é então convertido para um caractere e armazenado na variável
recebeuChar do tipo char.
Agora, se a fila de entrada serial estiver vazia, ou seja, não houver dados para ler, a função Serial.read()
retornará -1. Isso é importante porque -1 não é um valor válido para um caractere ASCII, então é usado
para indicar uma condição de “não há dados”.
char recebeuChar: Aqui, estamos declarando uma variável chamada recebeuChar do tipo char, que é
usada para armazenar caracteres. Quando Serial.read() é chamada, ela retorna o próximo caractere que
foi enviado para o Arduino através da porta serial.
Portanto, a instrução completa char recebeuChar = Serial.read(); lê o próximo caractere da fila de entrada
serial e armazena esse caractere na variável recebeuChar. Se não houver dados disponíveis para serem
lidos, Serial.read() retornará -1.
É importante notar que Serial.read() deve ser chamada apenas quando você sabe que há dados
disponíveis para leitura. Essa função é não-bloqueante, o que significa que ela não vai parar a execução
do programa enquanto espera por dados para chegar na porta serial. Ela simplesmente verifica se há
algum dado disponível para ler e, se não houver, retorna -1.
*/

void loop ()
  {
// Há dados disponíveis para ler
  if(Serial.available()>0) {
// Lê o próximo caractere disponível
  char recebeuChar = Serial.read();
  Serial.print("Voce digitou: ");
// Exibe o caractere recebido
   Serial.println(recebeuChar);
} 
  else
{
/*
Não há dados disponíveis para ler. O Arduino pode fazer outra coisa ou simplesmente não fazer nada.
Neste projeto, a instrução else captura a situação onde Serial.available() é 0, o que significa que não há
bytes para ler e, portanto, Serial.read() retornaria -1.
*/
}
}