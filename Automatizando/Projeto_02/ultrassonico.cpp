#include <HCSR04.h>

//PINOS
#define pinTrig 8
#define pinEcho 9
#define pinLed 4

//PARÂMETROS
#define distObstaculo 15    //cm pra detectar
#define tempoLeitura 50     //intervalo entre leitura
#define medidaLeituraDist 5 //media das leituras pra armazendar o dado (ex: em 20 leituras detectou 13: true)

#define DEBUG //tirar depois

//VARIÁVEIS
boolean obstaculo = false;
boolean parar = false;
boolean novaLeitura;
boolean mediaSensor[medidaLeituraDist] //últimos valores pra definir o dado
    byte posicao;
byte contaObstaculo = 0;
unsigned long controleLeitura; //variável para controlar o tempo entre as leituras

//INSTANCIANDO OBJETOS
HCSR04 sensorHCSR04(pinTrig, pinEcho); //sensor HCSR04 trabalhando no pino Trig e Echo

void setup()
{
    pinMode(pinLed, OUTPUT);

    for (byte i = 0; i < medidaLeituraDist; i++)
    { //média da leitura
        mediaSensor i = 0;
    }

    posicao = 0;

    delay(2000);

    void loop()
    {

        if (millis() - controleLeitura > tempoleitura)
        { //leitura da distância
            if (sensorHCSR04.dist <= distObstaculo)
            {
                obstaculo = true;   //encontrou objeto
                novaLeitura = true; //guarda a leitura na memória
            }
            else
            {
                obstaculo = false;
                novaLeitura = true; //guarda a leitura na memória
            }
            controleLeitura = millis();
        }

        if (novaLeitura == true)
        {                                    //sempre que houver uma nova leitura
            mediaSensor[posicao] = obstaculo //guarda se tem ou não obstáculo
                posicao = posicao + 1;       //passa para próxima posição da memória para armazenar todas as leituras

            for (byte i = 0; i < medidaLeituraDist; i++)
            {
                if (mediaSensor[i] == 1)
                    contaObstaculo++;
            }

            if (contaObstaculo >= ((medidaLeituraDist / 2) + 1))
            { //DETECTA OBSTÁCULO
                if (parar == false)
                {
                    parar = true;
                    digitalWrite(pinled, HIGH);
                    //ADD AQUI
                }
            }
            else
            { //DEIXA DE DETECTAR UM OBSTÁCULO
                if (parar == true)
                {
                    parar = false;
                    Serial.println("Caminho Livre");
                    digitalWrite(pinLed, LOW);
                    //ADD AQUI
                }
            }
            contaObstaculo = 0; //CONTROLE DA POSIÇÃO
            if (posicao > medidaDist)
            {
                posicao = 0;
            }
        }

        //LEITURA->GUARDAR A LEITURA EM UMA MEMÓRIA, COM A MEMÓRIA CALCULAR A MÉDIA MÓVEL->MÉIDA MOVEL DIZ SE HÁ(OU NÃO) CARRO