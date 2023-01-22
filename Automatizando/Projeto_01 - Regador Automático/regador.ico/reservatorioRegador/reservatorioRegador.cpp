
#include <LiquidCrystal.h>
#include <NewPing.h>

const int rs = 13, e = 12, db4 = 11, db5 = 10, db6 = 9, db7 = 8;
LiquidCrystal lcd(rs, e, db4, db5, db6, db7);

//definindo ultrassonico
#define botaoReset
#define trigger 5
#define echo 4
#define distanciaMaxima 1000

NewPing sonar(trigger, echo, distanciaMaxima);

//definindo variáveis
float valorVolumeInicial;
float areaBaseInicial = 48.0;
float alturaInicial = 9.0;
float valorVolumeFinal;
float valorReducaoAltura;

//funções

float reducaoAltura()
{
    valorReducaoAltura = sonar.ping_cm();
    return valorReducaoAltura;
}

float volumeInicial()
{
    valorVolumeInicial = ((alturaInicial) * (areaBaseInicial));
    return valorVolumeInicial;
}

float volumeFinal()
{
    valorVolumeFinal = (valorVolumeInicial - ((reducaoAltura) * (areaBaseInicial)));
    return valorVolumeFinal;
}

void lcdWelcomeSetup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Bem-vindo ao A2!");
    lcd.setCursor(0, 1);
    lcd.print("Como voce esta?");
    delay(4000);
    lcd.clear();
}

void lcdMedidasSetup()
{
    lcd.setCursor(0, 0);
    lcd.print("Area base: ");
    lcd.setCursor(11, 0);
    lcd.print(areaBaseInicial);
    lcd.setCursor(0, 1);
    lcd.print("Altura: ");
    lcd.setCursor(9, 1);
    lcd.print(alturaInicial);
    delay(4000);
    lcd.clear();
}

void lcdVolumeSetup()
{
    lcd.setCursor(0, 0);
    lcd.print("Volume: ");
    lcd.print(8, 0);
    lcd.print(valorVolumeInicial);
    lcd.setCursor(0, 1);
    lcd.print("Volume final...");
    delay(3000);
}

void lcdSetup()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Altura: ");
    lcd.setCursor(0, 1);
    lcd.print("Volume: ");
}

//função principal do código que imprime mensagens no lcd
void setup()
{
    volumeInicial();

    lcdWelcomeSetup();
    lcdMedidasSetup();
    lcdVolumeSetup();
    lcdSetup();
}

void loop()
{
    volumeInicial();
    reducaoAltura();
    volumeTotal();
    lcd.setCursor(8, 0);
    lcd.print(String(reducaoAltura, 1));
    lcd.setCursor(8, 1);
    lcd.print(String(valorVolumeFinal, 1));
    delay(1000);
}