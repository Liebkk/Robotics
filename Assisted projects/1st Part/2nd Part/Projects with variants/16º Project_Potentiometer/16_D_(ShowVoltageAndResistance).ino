// 16º Projeto (d): Potenciômetro (mostra de tensão e resistência)
// Gabriel Sassati da Costa

const int potPin = A1;

void setup(){
  Serial.begin(9600);
}

void loop() {
  /*
  Lê o valor analógico vindo do pino A1 (onde o potenciômetro está ligado).
  Esse valor varia de 0 a 1023, representando um faixa de tensão entre
  - 0 significa que o potenciômetro está no ponto de menor tensão (0V)
  - 1023 siginifica que está no ponto de maior tensão (5V)
  
  */
  int sensorValue = analogRead(potPin);
  
  /*
  Converte o valor lido (0 a 1023) para o valor real de tensão
  O arduino mede em passos - como se dividisse 5V em 1024 partes iguais
  Multiplicamos o valor lido por 5.0 (a tensão total) e dividimos por 1023.0
  para descobrir quanto isso representa em volts
  Exemplo: se ler 512 -> 512 * (5.0/1023.0) ~ 2,5V
  */
  float voltage = sensorValue * (5.0/1023.0);
  
  /*
  Calcula a resistência equivalente do potenciômetro.
  A fórmula vem da lei de Ohm (V = R * I), rearranjada conforme o circuito
  Aqui consideramos que há um resistor fixo de 10 quilohm no circuito e o 
  potenciômetro está formando um divisor de tensão com ele.
  O cálculo ((5.0 * 10.0) / voltage - 10.0) usa a tensão medida para estimar
  quanto de resistência o potenciômetro está oferecendo naquele ponto.
  Subtrair 10.0 serve para compensar o resistor fixo (o resistor fixo de 10 
  quiloohm é um componente real ligado no circuito) e obter só o valor do 
  potenciômetro
  */
  float resistance = ((5.0 * 10.0) / voltage - 10.0);
  
  Serial.print("Tensao: ");
  Serial.print(voltage, 2);
  Serial.print(" V");
  Serial.print("\t"); // Tabulação horizontal (equivalente a apertar tab)
  Serial.print("Resistencia: ");
  Serial.print(resistance, 2);
  Serial.print(" ohms");
  Serial.println();
  delay(1000);
}

