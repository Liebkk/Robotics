// 15º Projeto (d): Mensagem via serial.
// Gabriel Sassati da Costa

void setup (){
  Serial.begin(9600);
}

void loop (){
  if(Serial.available()>0){
  char c;
  c = Serial.read();
  if(c != '\n'){
  Serial.print ("Escreveu: ");
  Serial.println(c);
 }
    delay(150);
}
}
/*
if(c != '\n')
É uma condição que verifica se o caractere lido da porta serial não é uma quebra de linha. Aqui está o que
essa linha faz:
c: É a variável que armazena o caractere lido da porta serial.
'\n': Representa o caractere de quebra de linha, que é usado para indicar o final de uma linha de texto.
!=: É um operador de comparação que significa “diferente de”.
Quando você envia dados para o Arduino através da porta serial, cada vez que você pressiona “Enter”,
uma quebra de linha (\n) é enviada junto com seus dados. A condição if(c != '\n') verifica se o caractere
recebido é diferente de uma quebra de linha. Se for diferente, o código dentro do bloco if será executado,
que neste caso, imprime o caractere no Serial Monitor com a mensagem "Escreveu: ".
Imagine que você está trabalhando em um projeto de jardinagem inteligente com o Arduino, onde você
deseja monitorar a umidade do solo através de um sensor. Você tem um dispositivo que envia comandos
para o Arduino para controlar a irrigação automaticamente. Vamos usar a condição if(c != '\n') para
entender como ela funciona neste contexto.
Exemplo Prático: Imagine que você está usando um terminal para enviar texto ao seu Arduino, que está
rodando o código acima, como o código funcionaria:
Você digita “Olá” no terminal e pressiona “Enter”.
O terminal envia “Olá\n” para o Arduino, onde “\n” representa o caractere de nova linha.
O Arduino começa a executar o loop() e lê os caracteres um por um.
Primeiro, lê ‘O’, depois ‘l’, ‘á’, e finalmente lê o caractere de nova linha ‘\n’.
Para cada caractere que não é uma nova linha, ele executa o seguinte:
Imprime "Escreveu: " no terminal.
Imprime o caractere que acabou de ler (por exemplo, ‘O’).
Move para a próxima linha no terminal.Quando o Arduino lê o caractere de nova linha ‘\n’, ele não imprime "Escreveu: " nem o caractere. Ele
simplesmente ignora e espera pelo próximo caractere.
A saída no terminal seria algo assim:
Escreveu: O
Escreveu: l
Escreveu: á
Nenhuma mensagem é impressa após o caractere de nova linha porque o código foi projetado para
ignorar e não responder a esse caractere específico. Isso ajuda a evitar saídas desnecessárias e mantém
a comunicação clara e organizada.
*/
