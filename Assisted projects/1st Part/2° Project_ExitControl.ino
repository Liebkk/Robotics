// 2° Projeto - Controle de saída digital: Pisca-LED
// Gabriel Sassati da Costa
/*0 conteúdo dentro da função setup() é executado apenas uma vez, 
quando a placa Arduino é alimentada ou quando o botão de reset 
é pressionado. O objetivo principal da função setup() é realizar 
configurações iniciais necessárias para o funcionamento do programa. 
Isso pode incluir a definição de pinos como entrada ou saída, inicialização 
de bibliotecas, entre outras coisas. A assinatura padrão da função 
setup() é void setup(). A palavra-chave void significa que a função 
não retorna nenhum valor. */
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); 
}