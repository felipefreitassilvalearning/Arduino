#define pinLedVd 12
#define pinLedVm 11 
#define pinBotao 4 

boolean estadoBotao = true; 
boolean estAntBotao = true;
boolean estadoPisca = false;

unsigned long delay1 = 0; //variável tp o int, só que aceita valores maiores 

void setup() {
  pinMode(pinLedVd, OUTPUT);
  pinMode(pinLedVm, OUTPUT);
  pinMode(pinBotao, INPUT);

  digitalWrite( pinLedVd, HIGH); 
}
  

void loop() {

  estadoBotao = digitalRead(pinBotao);
  if (!estadoBotao && estAntBotao) { //estadoBotao significa que o botao anterior está desligado e estAntBotao significa que o estado atual está ligado
    estadoPisca = !estadoPisca;
  
  }
  estAntBotao = estadoBotao; 
  
  if (estadoPisca) {

  if ((millis() - delay1) >= 500) {  //millis é basicamente uma função que fica contando o tempo em milisegundos desde que o programa foi iniciado e subtrai ou soma o tempo, dentro da sua 
      digitalWrite(pinLedVm, HIGH); // contagem quando o botão é apertado. A partir dai, conforme digitado, o programa executada ou não a ação baseado na diferença do tempo 
  }
  if ((millis() - delay1) < 500) { 
    digitalWrite(pinLedVm, LOW);
  }
  if ((millis() - delay1) >=1000) { 
    delay1  = millis();
  }
  } else {
    digitalWrite(pinLedVm, LOW);
  }
  delay(100);
}
