#define pinBotao 2 //fundamentalmente reduz o tamanho do programa 

byte portas[] = {10,9,6,8,7,12,11,5,10};//array é basicamente uma lista //8 é o número de posições //tal como o python, começa pelo 0  
int numero = 10; //variável controlada pelo botão 
boolean botaoAnterior = false;
boolean botaoAtual = false; 
byte displayConfig[11][8] = {{1,1,1,1,1,1,0,0}, // 1 e 0 significa ligado e desligado// 8 está basicamente dentro do 11 e informa quais LEDs estão acessos e quais estão apagados 
                            {0,1,1,0,0,0,0,0},
                            {1,1,0,1,1,0,1,0},
                            {1,1,1,1,0,0,1,0},
                            {0,1,1,0,0,1,1,0},
                            {1,0,1,1,0,1,1,0},
                            {1,0,1,1,1,1,1,0},
                            {1,1,1,0,0,0,0,0},
                            {1,1,1,1,1,1,1,0},
                            {1,1,1,1,1,0,1,0},
                            {0,0,0,0,0,0,0,0}};
                            
                            
                        

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBotao, INPUT); 

  for (int nP = 0; nP <= 7; nP++){
  pinMode(portas[nP] , OUTPUT);
  
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
  botaoAnterior = botaoAtual;

  for (int nD = 0; nD <= 7; nD ++) {
    digitalWrite(portas[nD], displayConfig[numero][nD]);
      
  }


 
}
