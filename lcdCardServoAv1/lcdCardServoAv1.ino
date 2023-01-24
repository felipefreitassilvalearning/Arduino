//Programa : RFID - Controle de Acesso leitor RFID
//Autor : Automatizando

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal.h>

#define SS_PIN 9
#define RST_PIN 10
#define pinServo 8
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

Servo myservo;
 
void setup() 
{
  Serial.begin(115200);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();  
  lcd.begin(16, 2);  
  lcdDefault();
  myservo.attach(pinServo);
  myservo.write(90);
}
 
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  //Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
  //   Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
  //   Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  //Serial.println();
  //Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  if (conteudo.substring(1) == "0B F7 6D 0D") //UID 1 - Chaveiro
  {
    Serial.println("Olá, chaveiro !");
    Serial.println("Acesso negado !");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola, chaveiro !");
    lcd.setCursor(0,1);
    lcd.print("Acesso negado!");
    delay(2000);
    lcdDefault();
  }
 
  if (conteudo.substring(1) == "44 06 68 17") //UID 2 - Cartao
  {
    Serial.println("Olá, cartão !");
    Serial.println("Acesso liberado !");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola, cartao !");
    lcd.setCursor(0,1);
    lcd.print("Acesso liberado !");
    myservo.write(0);
    delay(2000);
    lcdDefault();
    myservo.write(90);
  }
}  
 
void lcdDefault()
{
  lcd.clear();
  lcd.print("Aproxime o seu");  
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");  
}
