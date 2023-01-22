#include <LiquidCrystal.h>
#include <NewPing.h>
#include <SoftwareSerial.h>

const int rs = 8, e = 9, db4 = 13, db5 = 11, db6 = 12, db7 = 10;
LiquidCrystal lcd(rs, e, db4, db5, db6, db7);
SoftwareSerial BTMasterHC05(4, 5);

//definindo ultrassonico
#define botaoReset
#define trigger 6    //capta os sons
#define echo 7       //emite os sons
#define distanciaMaxima 1000
NewPing sonar(trigger, echo, distanciaMaxima); //capta as ondas  portas

//definindo variáveis
float valorVolumeInicial;
float areaBaseInicial = 48.0;
float alturaInicial = 9.0;
float volumeInicial = 432;
float valorVolumeFinal;
float valorReducaoAltura;
float porcVolume;

//funções

float reducaoAltura(){
    valorReducaoAltura = sonar.ping_cm();         //pega a largura da onda
    return valorReducaoAltura;
}

float volumeFinal(){
    valorVolumeFinal = (valorVolumeInicial - (valorReducaoAltura * areaBaseInicial));
    return valorVolumeFinal;
}

float funcPorcentVolFinal(){
    porcVolume = valorVolumeFinal*100/volumeInicial;
    return porcVolume;
}

String frasePorc(){
    if (porcVolume >= 75){
        return ("Cheio ");
    };
    if ((porcVolume >= 50) && (porcVolume<75)){
        return ("Ta de boas POVO ");
    };
    if ((porcVolume >= 25) && (porcVolume < 50)){
        return ("Abastece ai ");
    };
    if ((porcVolume >= 0) && (porcVolume < 25)){
        return ("QUEIMO POVO ");
    };
}

void lcdWelcomeSetup(){
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Bem-vindo ao AU2");
    lcd.setCursor(0, 1);
    lcd.print("Como voce esta?");
    delay(4000);
    lcd.clear();
}

void lcdMedidasSetup(){
    lcd.setCursor(0, 0);
    lcd.print("Area base: ");
    lcd.setCursor(11, 0);
    lcd.print(areaBaseInicial);
    lcd.setCursor(0, 1);
    lcd.print("Altura: ");
    lcd.setCursor(9, 1);
    lcd.print(alturaInicial);
    delay(2000);
    lcd.clear();
}

void lcdVolumeSetup(){
    lcd.setCursor(0, 0);
    lcd.print("Volume Rec: ");
    lcd.print(12, 0);
    lcd.print(valorVolumeInicial);
    lcd.setCursor(0, 1);
    lcd.print("Calculando...");
    delay(3000);
}

void lcdSetup(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Volume: ");
    lcd.setCursor(9, 0);
    lcd.print(porcVolume);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print(frasePorc());
}

    //função principal do código que imprime mensagens no lcd
void setup(){
    lcdWelcomeSetup();
    lcdMedidasSetup();
    lcdVolumeSetup();
    lcdSetup();
    Serial.begin(9600);
    BTMasterHC05.begin(9600);
}

void loop(){
    reducaoAltura();
    volumeFinal();
    funcPorcentVolFinal();
    lcd.setCursor(8, 0);
    lcd.print(valorReducaoAltura);
    lcd.setCursor(8, 1);
    lcd.print(valorVolumeFinal);

    delay(1000);
}
