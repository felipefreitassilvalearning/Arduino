#define pinBotao 2 //fundamentalmente reduz o tamanho do programa 

#define pinA 9
#define pinB 10
#define pinC 6
#define pinD 8
#define pinE 7
#define pinF 12
#define pinG 11
#define pinPD 5 //ponto decimal 

int numero = 10; //variável controlada pelo botão 

boolean botaoAnterior = false;

boolean botaoAtual = false; 


void setup() {
  // put your setup code here, to run once:
  pinMode(pinBotao, INPUT); 

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinPD, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  botaoAtual = digitalRead(pinBotao); 
  if (botaoAtual && !botaoAnterior) { // como os números são diferentes, devemos alterar seus valores, 
    //se fossem iguais, estaria errado
    numero++; //=numero + ele mesmo + 1 
    if (numero > 9) { 
        numero = 0;
  }
  }
  botaoAnterior = botaoAtual;000000
 switch (numero){ // o switch avalia o conteudo da variável número 
    case 0: //o valor que o switch deve verificar, mais ou menos um if composto 
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG, LOW);
      digitalWrite(pinPD, LOW);
      break; 
      case 1:  
      digitalWrite(pinA,LOW);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinPD, LOW);
      break; 
      case 2:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,LOW);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinPD, LOW);
      break;
      case 3:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinPD, LOW);
      break; 
      case 4:  
      digitalWrite(pinA,LOW);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinPD, LOW);
      break;
      case 5:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,LOW);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinPD, LOW);
      break; 
      case 6:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,LOW);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinPD, LOW);
      break; 
      case 7:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinPD, LOW);
      break;
      case 8:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,HIGH);
      digitalWrite(pinE,HIGH);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD, LOW);
      break; 
      case 9:  
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB,HIGH);
      digitalWrite(pinC,HIGH);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinPD, LOW);
      break; 
      default:  
      digitalWrite(pinA,LOW);
      digitalWrite(pinB,LOW);
      digitalWrite(pinC,LOW);
      digitalWrite(pinD,LOW);
      digitalWrite(pinE,LOW);
      digitalWrite(pinF,LOW);
      digitalWrite(pinG,LOW);
      digitalWrite(pinPD, HIGH);
      break;
      
  }


 
}
