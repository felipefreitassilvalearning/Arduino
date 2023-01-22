int pinVermelho = 10; 
int pinAmarelo = 9;
int pinVerde = 8;
int pinBotao = 7;
int pinPedestreVermelho = 3;
int pinPedestreVerde = 2;
int estadoBotao;
int faseSemaforo;
int estadoAnteriorBotao; //serve para controlar o botão 
int tempoPisca; 
int estadoPisca; 

void setup() {
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotao, INPUT);
  pinMode(pinPedestreVermelho, OUTPUT);
  pinMode(pinPedestreVerde, OUTPUT);

  faseSemaforo = 1;

  tempoPisca = 0;

  estadoPisca = HIGH; 

  estadoAnteriorBotao = digitalRead(pinBotao);
  
}

void loop() {
  
  estadoBotao = digitalRead(pinBotao);
  
  if ((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)){
    
    if (faseSemaforo < 4) { 
      faseSemaforo = faseSemaforo + 1;       //se o botao for apertado 
    } else {
    faseSemaforo = 1;
  }
  }
  estadoAnteriorBotao = estadoBotao;
  if (faseSemaforo == 1) { //Semaforo aberto
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);  

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
  }
  if (faseSemaforo == 2) { //Semaforo amarelo 
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW); 

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
}

  if (faseSemaforo == 3) { //Semaforo fechado 
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH); 

    digitalWrite(pinPedestreVerde, HIGH);
    digitalWrite(pinPedestreVermelho, LOW);
  }

    if (faseSemaforo == 4) { //Semaforo pedestre piscando 
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);  

    tempoPisca = tempoPisca + 1 ;
    if (tempoPisca = 400) { 
      estadoPisca = estadoPisca; 
      tempoPisca = 0;
      
    }

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, estadoPisca );

    }
  delay(1);}

  
