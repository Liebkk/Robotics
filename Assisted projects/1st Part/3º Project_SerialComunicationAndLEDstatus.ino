//3º Projeto: Comunicação Serial com Monitoramento do Estado do LED
//Gabriel Sassati

// A função setup () é executado uma vez quando o Arduino é ligado ou reiniciado
void setup ()
{
  //Configura o pino digital 13 como saída. Geralmente é onde o led embutido está conectado
  pinMode(13, OUTPUT);
  
  /*
   O que é "Serial"?
   
   No arduino, Serial é um objeto da biblioteca HardwareSerial, que já está incluída
automaticamente nas placas que suportam comunicação UART, como o Arduino Uno.
  
   Esse objeto representa a porta serial física do microcontrolador.
   Apesar da conexão entre o arduino e o computador ser via USB, essa comunicação emula uma 
conexão UART - um protocolo serial muito antigo, confiável e amplamente utilizado em sistemas
embarcados.

   A comunicação UART (Universal Asvnchronous Receiver Transmitter) é baseada no envio de bits em
   sequência, sem a necessidade de um relógio de sincronização externo.
   
   --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
   O que significa Serial.begin(9600)?
   
   - begin() é o método usado para iniciar a comunicação serial.
   - O número 9600 é chamado de baud rate, ou taxa de transmissão de dados, medida em bits por 
   segundo (bps).
   Então, 9600 baud significa que o arduino está configurado para enviar/receber até 9600 bits
   por segundo.
   
   IMPORTANTE:
   O computador também deve estar configurado para a mesma taxa de transmissão (no Monitor
   Serial de IDE do arduino). Caso contrário, os dados enviadis parecerão "corroídos" ou
   ilegíveis.
   
   ---------------------------------------------------------------------------------------------------------------------------
   
   Analogia para entender melhor:
   
   Imagine que arduino e computador são duas pessoas conversando:
   
   Serial.begin(9600); é como combinar: "Vamos conversar, mas falando 9600 palavras por segundo."
   
   Se um falar mais rápido ou mais devagar, a outra parte não vai entender. Por isso é essencial
   que os dois usem a mesma velocidade de comunicação.
   
   -------------------------------------------------------------------------------------------------------------
   
   O que acontece se esquecer Serial.begin()?
   
   Nenhum comando como Serial.print() ou Serial.println() vai funcionar. É como tentar falar 
com alguém sem antes abrir a boca.
   
   Dica para depuração (debug):
   Se o Monitor Serial não monstra nada, a primeira coisa a conferir é se Serial.begin() foi
incluído dentro do setup().

   */
  
  Serial.begin(9600); //Inicia a comunicação serial a 9600 bps
}

//A função loop() é executasa repetidamente em um loop infinito
void loop()
{
  //Liga o LED embutido no pino 13
  digitalWrite(13, HIGH);
  
  /*
    Envia uma mensagem pela porta serial para o computador.
    
    Serial,println("LED: Ligado");
    
  - Essa linha envia o texto "LED: Ligado" como uma string pela comunicação serial.
  - A função println() adiciona automaticamente um caractere se nova linha (\n) ao final.
  - Isso significa que cada mensagen aparece em uma linha separada no Monitor Serial.
  
  O computador, usando a IDE do arduino, interpreta os bits recebidos e mostra a mensagem
  como texto legível na tela.
  
  Essa linha é extremamente útil para debg e monitoramneto do estado do programa.
  
 */
  
  Serial.println("LED: Ligado");
  
  //Espera 1 segundo com LED aceso.
  delay(1000);
  
  //Desliga o LED
  digitalWrite(13, LOW);
  
  /*
    Envia outra mensagem pela porta Serial indicando que o LED foi desligado.
    Novamente, usamo Serial.println(), que envia o texto e pula para uma nova linha.
    Isso ajuda a acompanhar o funcionamento do código diretamente do computador, mesmo 
 que você não esteja vendo fisicamente o LED.
 */
  
  Serial.println("LED: Desligado");
 
  //Espera 1 segundo com o LED apagado
  delay(1000);
}