//Programa : RFID - Controle de Acesso leitor RFID
//Autor : Automatizando

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  lcdDefault();
}
 
void loop() 
{
    Serial.println("Feito um loop");
    Serial.println("Reiniciando Loop");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola, chaveiro !");
    lcd.setCursor(0,1);
    lcd.print("Acesso negado!");
    delay(2000);
    lcdDefault();
}  
 
void lcdDefault()
{
  lcd.clear();
  lcd.print("Aproxime o seu");  
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");  
}
