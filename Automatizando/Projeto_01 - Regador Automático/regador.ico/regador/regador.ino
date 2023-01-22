/*
################################################
    Projeto#01 - Regador Automático
    Autor: Equipe Automatizando
    Data: 01/04/2021
################################################
*/

//definindo portas do lcd
#include <LiquidCrystal.h>
const int rs = 13, e = 12, db4 = 11, db5 = 10, db6 = 9, db7 = 8;
LiquidCrystal lcd(rs, e, db4, db5, db6, db7);

//definindo portas analógicas
#define pinUmidade A0
#define pinLuminosidade A1

//definindo portas digitais
#define pinLedSeco 3
#define pinLedUmido 4
#define pinLedLuminosidade 5
#define pinLedSemLuminosidade 6
#define pinSolenoide 7

//definindo variáveis
int intervaloLeitura = 1000;

int valorUmidade;
float leituraUmidade;
float padraoSeco = 60;

int valorLuminosidade;
float leituraLuminosidade;
float limiarEscuro = 40;

//configurando o monitor lcd (mensagem de bem-vindo)
void lcdSetup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Bem-vindo ao A1!");
  lcd.setCursor(0, 1);
  lcd.print("Como voce esta?");
  delay(4000);
  lcd.clear();
}

//função que converte o valor lido no sensor de umidade para porcentagem
float converteUmidade()
{
  leituraUmidade = analogRead(pinUmidade);
  valorUmidade = 140 - (leituraUmidade / 1010)* 100;
  return valorUmidade;
}

//função que analisa a umidade, imprime no lcd e -de acordo- liga um LED e abre a solenoide
void condicionalUmidade()
{
  converteUmidade();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.setCursor(11, 0);
  lcd.print(valorUmidade);
  lcd.print("%");

  if (valorUmidade <= padraoSeco)
  {
    digitalWrite(pinLedSeco, HIGH);
    digitalWrite(pinLedUmido, LOW);
    digitalWrite(pinSolenoide, LOW);
  }
  else
  {
    digitalWrite(pinLedSeco, LOW);
    digitalWrite(pinLedUmido, HIGH);
    digitalWrite(pinSolenoide, HIGH);
  }
}

//função que converte o valor lido no sensor de luminosidade para porcentagem
float converteLuminosidade()
{
  leituraLuminosidade = analogRead(pinLuminosidade);
  valorLuminosidade = ((leituraLuminosidade / 901) * 100) - 3;
  return valorLuminosidade;
}

//função que analisa a umidade, imprime no lcd e -de acordo- liga um LED
void condicionalLuminosidade()
{
  converteLuminosidade();

  lcd.setCursor(0, 1);
  lcd.print("Luz: ");
  lcd.setCursor(11, 1);
  lcd.print(valorLuminosidade);
  lcd.print("%");

  if (valorLuminosidade <= limiarEscuro)
  {
    digitalWrite(pinLedLuminosidade, LOW);
    digitalWrite(pinLedSemLuminosidade, HIGH);
  }
  else
  {
    digitalWrite(pinLedLuminosidade, HIGH);
    digitalWrite(pinLedSemLuminosidade, LOW);
  }
}

//função principal do código que indica a função de cada componente
void setup()
{
  pinMode(pinSolenoide, OUTPUT);

  pinMode(pinLedSeco, OUTPUT);
  pinMode(pinLedUmido, OUTPUT);

  pinMode(pinLedLuminosidade, OUTPUT);
  pinMode(pinLedSemLuminosidade, OUTPUT);

  lcdSetup();
}

//função que se repete a cada intervalo - no caso, a cada 4s
void loop()
{
  condicionalUmidade();
  condicionalLuminosidade();  
  delay(intervaloLeitura);
}
