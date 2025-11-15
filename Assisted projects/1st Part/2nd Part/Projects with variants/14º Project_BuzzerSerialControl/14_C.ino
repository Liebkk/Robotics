// 14° Projeto (C): Buzzer controlado via Serial (ajuste de frequência em Hz)
// Gabriel Sassati da Costa

/*
Descrição: Lê valores de frequência digitados no monitor serial e aplica no buzzer do pino 10.
Observação: Digite um número inteiro (em Hz) e pressione Enter. Digite 0 para silenciar.
*/

//Define a constatnte do pino onde o buzzer está conectado (terminal positivo no pino 10; negativo no GND).
const int pinoBuzzer = 10;

//Define a frequência atual aplicada ao buzzer (inicia em 0 = silencioso)
int frequenciaAtual = 0;

//Guarda a última frequência aplicada para evitar chamadas repetidas a tone()/noTone().
int frequenciaAnterior = -1;

//Define limites práticos de operação do buzzer (ajuste conforme seu componente)
const int FREQ_MIN = 50; // Frequência mínima recomendada (evita tons muito graves que pouco vibram no piezo)
const int FREQ_MAX = 5000; // Frequência máxima recomendada (evita tons demasiadamente agudos/desconfortáveis)

//Define a taxa de comunicação serial (bits por segundo). 9600 é padrão confiável para testes
void setup() {
  // Inicia a porta serial para comunicação com o computador
  Serial.begin(9600);
  
  // Ajusta o tempo máximo de espera para leitura de uma linha vinda da serial (em ms).
  Serial.setTimeout(200);
  
  //Informa o usuário sobre como operar o sistema pelo Monitor Serial
  Serial.println("=== Buzzer via Serial (Hz) ===");
  Serial.println("Digite uma frequência em Hz e pressione Enter ");
  Serial.println("Exemplo: 440 | 1000 | 2500");
  Serial.println("Digite 0 para silenciar.");
  Serial.println("------------------------------------------------");
}

void loop() {
  if(Serial.available() > 0){
    String entrada = Serial.readStringUntil('\n');
    entrada.trim();
    
    if(entrada.length() > 0) {
      long valorConvertido = entrada.toInt();
      bool entradaEhZero = (entrada == "0");
      bool entradaValida = (entradaEhZero || (valorConvertido != 0));
      
      if (!entradaValida) {
        Serial.println("Entrada inválida. Digite um numero inteiro em HZ (ex: 440, 100, 2500 ou 0 para silenciar)";
      }
      else {
        int novaFreq = (int)valorConvertido;
        
        if (novaFreq != 0) {
          if (novaFreq < FREQ_MIN) novaFreq = FREQ_MIN;
          if (novaFreq > FREQ_Max) novaFreq = FREQ_MAX;
        }
        
        frequenciaAtual = novaFreq;
    }
  }
}
                       
if (frequenciaAtual != frequenciaAnterior) {
  if (frequenciaAtual == 0) {
    noTone(pinoBuzzer);
    Serial.println("Buzzer: silenciado (0Hz).");
  } else {
    tone(pinoBuzzer, frequenciaAlta);
    Serial.print("Buzzer: ");
    Serial.print(frequenciaAtual);
    Serial.println(" Hz aplicado.");
  }
 
  frequenciaAnterior = frequenciaAtual;
 }
delay(10);
}