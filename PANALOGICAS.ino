int pinos[9] = {13,12,11,10,9,8,7,6,5};
int pinLed; 
char Str[8] = " ";
float minimo = 85;
float maximo = 1023;
float valorLDR; 
float luminosidade; 


void setup() {

for (pinLed = 0; pinLed <= 8; pinLed= pinLed +1){
 pinMode(pinos[pinLed], OUTPUT); 
}
  pinMode(A0,INPUT); 
  Serial.begin(9600); 
}


void loop() {

 valorLDR = analogRead(A0);
 luminosidade = (valorLDR - minimo) / (maximo - minimo) *10; //variar de 0 até 10 
 luminosidade = (luminosidade - 10) * -1 ; //inverter as propriedades da tensão e luminosidade  
 Str[8] = valorLDR; 
 Serial.write(Str[8]);

 for (pinLed = 0; pinLed <= 8; pinLed= pinLed +1){
    if (pinLed < luminosidade) {
        digitalWrite(pinos[pinLed], HIGH);
    } else {
      digitalWrite(pinos[pinLed], LOW);
    }
 }
 delay(500);}
