
/*
################################################
		Projeto#02 - ???
		Autor: Equipe Automatizando
		Data: 00/00/2021
################################################
*/

#include <Servo.h>

#define pinBotao 5

Servo myservo;

int fechado = 92.2;
int aberto = 0;

bool botaoAtual;
bool botaoAnterior;
int contagemBotao = 0;

void lcdSetup()
{
	myservo.attach(9);

	Serial.begin(9600);
}

void condicionalBotao()
{
	if (botaoAtual && !botaoAnterior)
	{
		if (contagemBotao % 2 == 0)
		{
			myservo.write(fechado);
			Serial.write("Fechado");
		}
		else
		{
			myservo.write(aberto);
			Serial.write("Aberto");
		}

		contagemBotao++;
	}
	botaoAnterior = botaoAtual;
}

void setup()
{
	pinMode(pinBotao, INPUT);
	lcdSetup();
}

void loop()
{
	botaoAtual = digitalRead(pinBotao);
	condicionalBotao();
}