//portas 0 e 1, exclusivas para a comunicação serial 
byte valorX;
byte valorY;
byte valorZ; //byte é uma variável de tamanho limitado
void setup() {
  Serial.begin(9600); //mesma velocidade do arduino

  Serial.print("Olá guri."); //enviar informações 

  valorX = 10; 
  valorY = 20; 
  valorZ = valorX + valorY;

  Serial.print("valorX"); //ln é a quebra de linha 
  Serial.println(valorX);

  Serial.print("valorY"); //ln é a quebra de linha 
  Serial.println(valorY);

  Serial.print("valorZ"); //ln é a quebra de linha 
  Serial.println(valorZ, BIN); //bin é a forma de visualização em binário


}

void loop() {
  // put your main code here, to run repeatedly:

}
