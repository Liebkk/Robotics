//15º Projeto (e): Mensagem via serial.
//Gabriel Sassati da Costa
void setup(){
  Serial.begin(9600);
  String frase1 = "Primeiro texto e";
  String frase2 = "Segundo texto.";
  Serial.println(frase1 + " " + frase2);
}

void loop() {
  }
/*
String frase1 = "Primeiro texto e";: Declara uma variável do tipo String chamada frase1 e atribui a ela o
texto “Primeiro texto e”.
String frase2 = "Segundo texto.";: Declara outra variável do tipo String chamada frase2 e atribui a ela o
texto “Segundo texto.”.
Serial.println(frase1 + " " + frase2);:
- Imprime as duas strings frase1 e frase2 na saída serial, separadas por um espaço.
- Essa linha utiliza o operador '+' para realizar a concatenação de strings, que significa a junção de dois ou
mais textos em uma única string.
- Neste caso, primeiro a string " " (espaço em branco) é concatenada com `frase1`, e depois o resultado é
concatenado com `frase2`.
- O resultado é a string: “Primeiro texto e Segundo texto.”, que será exibida no monitor serial quando o
código for executado.
*/