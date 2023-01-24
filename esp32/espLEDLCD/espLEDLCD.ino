#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 14, 27, 26, 25);

// LED on GPIO2
int ledPin = 2;

void setup()
{
    
    // Set LED as output
    pinMode(ledPin, OUTPUT);
    
    // Serial monitor setup
    Serial.begin(115200);
    lcd.begin(16, 2);

    defaultDisplay();
}

void loop()
{
    Serial.print("Hello");
    digitalWrite(ledPin, HIGH);
    
    delay(500);
    
    Serial.println(" world!");
    digitalWrite(ledPin, LOW);
    
    delay(500);
}

void defaultDisplay(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Aproxime o seu");  
    lcd.setCursor(0,1);
    lcd.print("cartao do leitor");  
    Serial.println("Aproxime seu cartão do leitor.");
}
