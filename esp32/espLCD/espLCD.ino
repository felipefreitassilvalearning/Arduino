#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 14, 27, 26, 25);

void setup()
{
    lcd.begin(16, 2);

    defaultDisplay();
}

void loop(){}

void defaultDisplay(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Aproxime o seu");  
    lcd.setCursor(0,1);
    lcd.print("cartao do leitor");  
}
