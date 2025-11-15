//15º Projeto (i): Mensagem via serial
//Gabriel Sassati da Costa

void setup () {
  Serial.begin(9600);
  Serial.println("Gerando valores sequencias");
}

int numero = 2;
void loop() {
  Serial.print("Valor: ");
  Serial.println(numero);
  delay(500);
  numero *= 3;
  if (numero >= 100) { 
    numero = 2;        
  }
}

/*
O que significa declarar int numero = 0; "fora de qualquer função".
Quando declaramos algo fora das chaves {} de uma função, como no projeto, essa variável passa a existir no programa inteiro, ou seja, tanto no setup() 
quanto no loop() - e até em outras funções que você venha a criar depois. Chamamos isso de variável global.

Dentro do setup() ou loop(): Local - Somente dentro dessa função - É apagada quando a função termina.

>>>>Problema: Toda vez que o loop() reinicia (e ele reinicia infinitamente), a variável número é recriada do zero, recebendo novamente o valor 0. Ou seja,
o incremento numero++ não tem efeito acumulativo.
*/
