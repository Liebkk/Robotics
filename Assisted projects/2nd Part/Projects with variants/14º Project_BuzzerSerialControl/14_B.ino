// 14° Projeto (B): Buzzer controlado via Serial (Perfis de Alerta por Faixa de Frequência)
// Gabriel Sassati da Costa

const int pinoBuzzer = 10;
int escolha = 0; // valor digitado no serial
int tempoSom = 300; // duração do tom (ms)
int pausa = 300; // pausa entre acionamentos (ms)

// perfis de frequencia
const int F_GRAVE = 400; // ~alarme grave
const int F_MODERADO = 1000; // ~alerta moderado
const int F_AGUDO = 1800;  // ~sinalização aguda

void setup() {
  Serial.begin(9600);
  Serial.println("=== Projeto B: Perfis de Alerta por frequencia ===");
  Serial.println("Digite: 1 (grave ~400hz), 2 (moderado ~1000hz), 3 (agudo ~1800hz), 0 (desligar).");
}

void loop() {
  if (Serial.available() > 0){
    escolha = Serial.parseInt();
    
    if (escolha == 1) {
      tone(pinoBuzzer, F_GRAVE);
      Serial.println("Perfil: GRAVE (~400 Hz)");
      delay(tempoSom);
      noTone(pinoBuzzer);
      delay(pausa);
      }
    else if (escolha == 2) {
      tone(pinoBuzzer, F_MODERADO);
      Serial.println("Perfil: MODERADO (~1000 Hz)");
      delay(tempoSom);
      noTone(pinoBuzzer);
      delay(pausa);
      }
    else if (escolha == 3) {
      tone(pinoBuzzer, F_AGUDO);
      Serial.println("Perfil: AGUDO (~1800 Hz)");
      delay(tempoSom);
      noTone(pinoBuzzer);
      delay(pausa);
      }
    else if (escolha == 0) {
      noTone(pinoBuzzer);
      Serial.println("Buzzer desligado.");
    }
    else {
      Serial.println("Entrasa invalida. Use 1, 2, 3 ou 0.");
    }
  }  
}