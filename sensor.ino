#define pinSensorA A0
#define pinSensorD 8

#define ledAzul 7
#define ledVerde 6
#define ledVermelho 5


void setup() {
  pinMode(pinSensorD, INPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Digital:");
  
  if (digitalRead(pinSensorD)) {
     Serial.print("SEM UMIDADE ");
  } else {
     Serial.print("COM UMIDADE ");
  }

  Serial.print("  Analogico:");
  Serial.print(analogRead(pinSensorA)); 
  Serial.print("  ");

  Serial.print("  Atuador:");

  int umidade = analogRead(pinSensorA);
  
  if (umidade < 650) {
     Serial.println("Molhado, liga led azul");
     digitalWrite(ledVermelho, LOW);
     digitalWrite(ledAzul, HIGH);
     digitalWrite(ledVerde, LOW);
  } else if(umidade >= 650 && umidade < 900) {
     Serial.println("Ideal, liga led verde");
     digitalWrite(ledVermelho, LOW);
     digitalWrite(ledAzul, LOW);
     digitalWrite(ledVerde, HIGH);
  } else {
     Serial.println("Seco, liga led vermelho");
     digitalWrite(ledVermelho, HIGH);
     digitalWrite(ledAzul, LOW);
     digitalWrite(ledVerde, LOW);
    }
  
}
