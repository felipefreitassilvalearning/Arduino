float valor1; 
float valor2; 
float resultadoSoma, resultadoSub, resultadoDiv, resultadoMult, resultadoMod;
float resultadoFinal;




void setup() {
  // put your setup code here, to run once:
  valor1 = 250;
  valor2 = 7.8;

  resultadoSoma = valor1 + valor2; 
  resultadoSub = valor1 - valor2; 
  resultadoDiv= valor1 / valor2;
  resultadoMult = valor1 * valor2;
  resultadoMod = int(valor1) % int(valor2); //divisão inteira não aceita valores quebrados

  Serial.begin(9600);
  Serial.print("Valor1: ");
  Serial.println(valor1);

  Serial.print("Valor2: ");
  Serial.println(valor2); 

  Serial.print("Soma: ");
  Serial.println(resultadoSoma);

  Serial.print("Subtração: ");
  Serial.println(resultadoSub);
  
  Serial.print("Divisão: ");
  Serial.println(resultadoDiv);

  Serial.print("Multiplicação: ");
  Serial.println(resultadoMult);

  Serial.print("Resto da divisão: ");
  Serial.println(resultadoMod);
}

void loop() {
  // put your main code here, to run repeatedly:

}
