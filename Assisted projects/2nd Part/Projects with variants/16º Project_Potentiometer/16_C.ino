// 16° Projeto(c): Potenciômetro
// Gabriel Sassati da Costa 


/* Constantes do pino: utilizar 'const int' documenta a função de 
cada pino e evita alterações acidentais durante a execucção do programa. */
const int pinoPot = A0; // Entrada analógica (0..5V -> 0..1023 no ADC de 10 bits)
const int pinoLED = 9; // Saída PWM (resolução padrão de 8 bits: 0..255) para brilho do LED
const int pinoBuzzer = 10; /* Mesmo que as funções tone() e noTone() aceitem diretamnete o numero do 
pino (por exemplo, tone(10, 1000)), ainda é uma boa prática declarar uma constante para representar 
esse pino.*/

/* Variável global de leitura: a variável 'valorPot' armazena a leitura bruta do ADC (10 bits) e é mantida
como global para facilitar seu uso em diferentes partes do código. */
int valorPot = 0;

void setup() {
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoPot, INPUT);
  
  Serial.begin(9600);
  Serial.println("=== Sistema inciado ===");
  Serial.println("Gire o potenciômetro para controlar o brilho do LED");
}

void loop() {
/*
   Leitura analógica (ADC de 10 bits): O comandfo analogRead(pinoPot) realiza a amostragem da tensão presente no 
pino A0 e converte esse valor em número inteiro de 10 bits, dentro do intervalo de 0 a 1023.
   - 0 representa aproximadamente 0V
   - 1023 representa aproximadamente Vref (geralmente 5V ou 3,3V, dependendo da placa utilizada)
   Observação: o intervalo de 0 a 1023 corresponde a 1024 níveis possíveis (resolução de 10 bits = 2^10).
*/
  valorPot = analogRead(pinoPot);
  
  /*
  Reescaça de 10 bits para 8 bits (PWM):
  Por que reescalar?
   - O ADC fornece uma leitura de 10 bits: 0 a 1023 (medida de tensão)
   - O PWM do comando analogWrite() utiliza resolução de 8 bits: 0 a 255 (duty cycle do temporizador)
  Portando, realizamos uma conversão linear da faixa de entrada (0 a 1023) para a faixa de saída (0 a 255).
  
  Fórmula usada pela função map() (conceito):
   out = (in - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
   
  Aplicando aos nossos limites:
   in_min = 0, in_max = 1023, out_min = 0, out_max = 255
   exemplo: in = 512 -> out ~ 128 (metade do brilho)
  
  Detalhes de implementação:
   - A função map() retorna um valor do tipo long; ao armazená-lo em uma variável do tipo int, o valor permance 
   correto dentro da faixa de 0 a 255.
   - O PWM de 8 bits gera 256 níveis de duty cycle (0 a 255), onde:
     0 -> 0% (sempre desligado)
     255 -> 100% (sempre ligado durante o período do PWM)
*/
  int valorLed = map(valorPot, 0, 1023, 0, 255);
  
/*
Escrita PWM (8 bits) no LED: analogWrite(pinoLEDm valorLed) ajustao duty cycle do PWM no pino D9. Isso controla o 
brilho percebido do LED de forma proporcional ao valor 0..255.
*/
  analogWrite(pinoLED, valorLed);
  
  /*
Acionamento do buzzer por FAIXAS de brilho.
  Estrutura e critério:
  - Primeiro, é testada a faixa mais alta (valorLed > 200).
  - Em seguida, a faixa intermediária (valorLed > 100).
  - Por fim, o bloco else cobre os valores de 0 a 100.
  
  A ordem é propositalmente decrescente: ao avaliar primeiro as faixas mais altas, evitamos sobreposição de
condições e garantimos que apenas um bloco seja executado. Assim, o fluxo lógico permanece determinístico (isto é,
com um único resultado possível para cada valor analisado).

Por que usar o operador '>' e faixas em vez de igualdade ('==')?
  - A leitura analógica não é estável; variações elétricas, ruídos e pequenas tolerâncias nos componentes fazem o
valor oscilar constantemente.
  - Comparar um valor exato (por exemplo, valorLed == 200) tornaria o buzzer intermitente, ligando e desligando
rapidamente conforme o valor flutua.
  - Definir intervalos (faixas) cria zonas de operação estáveis, permitindo uma resposta mais previsível e agradável.
Por que a faixa "acima de 200" é considerada alta e "acima de 100" intermediária?
  - O valor máximo possível de PWM é 255 (8 bits).
  - 200 representa cerca de 78% do valor máximo (200 / 255 ~ 0,78), ou seja, um nível de brilho e intensidade
próximos ao limite superior — por isso, é classificado como a faixa "alta".
  - 100 representa cerca de 39% do valor máximo (100 / 255 ~ 0,39), ou seja, um brilho moderado, no meio da
escala — por isso, é a faixa "média".
  - Valores abaixo de 100 (menores que ~40% do brilho máximo) são considerados baixos e, portanto, o buzzer
permanece desligado.
  
  Intervalos resultantes com base nos comparadores usados:
  - Faixa alta: valorLed & [201..255] -> tom agudo (1200 Hz)
  - Faixa média: valorLed & [101..200] -> tom médio (600 Hz)
  - Faixa baixa: valorLed & [0..100] -> buzzer desligado

*Observação: Os limiares de 100 e 200 são referências didáticas, escolhidas para dividir a escala de 0 a 255 em três
zonas bem perceptíveis. Em aplicações práticas, esses limites podem ser ajustados de acordo com o tipo de sensor, a
resposta do atuador ou o conforto auditivo desejado.
*/
  if (valorLed > 200) {
    tone(pinoBuzzer, 1200); // Faixa ALTA: frequência maior (som mais agudo)
} 
  else if (valorLed > 100) {
    tone(pinoBuzzer, 600); // Faixa MEDIA: frequência intermediaria
} 
  else {
    noTone(pinoBuzzer); // Faixa BAIXA: sem emissão sonora
}

  /* Saída no Monitor Serial (diagnóstico coerente com as faixas acima): A impressão textual reflete exatamente a
mesma lógica de faixas utilizada no bloco do buzzer. Mantém-se uma correspondência direta (1:1) entre cada
condição e seu respectivo rótulo, evitando inconsistências entre o som emitido e a mensagem exibida na saída serial.
*/

  Serial.print("Leitura do Potenciometro: ");
  Serial.print(valorPot);
  Serial.print(" | Brilho do LED (0-255): ");
  Serial.print(valorLed);
  Serial.print(" | Som do Buzzer: ");
  if (valorLed > 200) {
    Serial.println("Agudo");
} 
  else if (valorLed > 100) {
    Serial.println("Medio");
} 
  else {
    Serial.println("Desligado");
}

  /* Ritmo de atualização: delay(100) reduz a taxa de impressão e suaviza a observação dos valores. Ajustável
conforme necessidade (p.ex., 50 ms para resposta mais rápida). */
delay(100);
}
