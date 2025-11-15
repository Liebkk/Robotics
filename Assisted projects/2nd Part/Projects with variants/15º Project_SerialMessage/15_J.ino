// 15º Projeto (j): Mensagem via serial
// Gabriel Sassati da Costa

int contadorGlobal = 0; // variável global

void setup() {
  Serial.begin(9600);
}

void loop() {
  int contadorLocal = 0; // variável local
  
  contadorGlobal++;
  contadorLocal++;
  
  Serial.print("Global: ");
  Serial.print(contadorGlobal);
  Serial.print(" | Local: ");
  Serial.println(contadorLocal);
  
  delay(500);
}

