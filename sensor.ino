#define pino_sinal_analogico A1
#define pino_led_vermelho 12
#define pino_led_amarelo 13
 
int valor_analogico;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
}
 
void loop()
{
  valor_analogico = analogRead(pino_sinal_analogico);
 
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  if (valor_analogico > 0 && valor_analogico <= 512)
  {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(pino_led_amarelo, HIGH);
  }
 
  if (valor_analogico > 512 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(pino_led_vermelho, HIGH);
  }
  delay(100);
}
 
void apagaleds()
{
  digitalWrite(pino_led_vermelho, LOW);
  digitalWrite(pino_led_amarelo, LOW);
}
