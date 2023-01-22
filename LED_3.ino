void setup() {
  // a porta 7 do botão está ligada ao terra para identificar que ele não está 
  //recebendo corrente elétrica 
  //já se o botão for apertado, isso vai indicar que ele está recebendo a corrente
  //de 5 volts e irá mandar a informação para a porta 7
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT_PULLUP); //entrada de corrente elétrica
  // pullup é uma éspecie de resistor interno do arduino que puxa a corrente de uma
  // porta para cima ou para baixo 
  // quando é só o input, por não ter um resistor do arduíno, o led fica 
  // ligado de maneira constante 

}

void loop() {
  int estadoBotao;
  estadoBotao = digitalRead(7);//verifica o estado da porta
  digitalWrite(10,estadoBotao ); //manda o estado da porta // ligada caso o botão esteja ligado
  digitalWrite(11,!estadoBotao); //manda a informação inversa devido a ! 
  

}
