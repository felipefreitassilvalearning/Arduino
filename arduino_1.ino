int ledVerde = 2;
int ledVermelho = 3;
int botao = 4;
int fase = 1;
int estadoBotao;

void setup(){
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  estadoBotao = digitalRead(botao);
 
  if (estadoBotao = HIGH) {
    if (fase<3) {
      fase = fase + 1;
    } else {
      fase = 1;
    }
  }
 
  if (fase == 1) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  }

  if (fase == 2) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
  
  delay (200);
}
