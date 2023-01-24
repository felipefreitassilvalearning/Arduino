#include <SPI.h>
#include <MFRC522.h>
 
//definindo ID que vai liberar a entrada (cartão)
#define ID "44 06 68 17"
 
#define SS_PIN 21
#define RST_PIN 22

//configurando pinos de controle do modulo de leitura de cartoes RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  // inicia a comunicacao SPI que sera usada para comunicacao com o mudulo RFID
  SPI.begin();
  //inicia o modulo RFID
  mfrc522.PCD_Init();

  //iniciando comunicação serial
  Serial.begin(115200);
  
  Serial.println("Aproxime seu cartão do leitor.");
  
  //Serial.println("RFID + ESP32");
  //Serial.println("Aguardando tag RFID para verificar o id da mesma.");
}

void loop() {
 
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
     return;                 // se nao tiver um cartao para ser lido recomeça o void loop
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;                  //se nao conseguir ler o cartao recomeça o void loop tambem
  }
 
  String conteudo = "";      // cria uma string para armazenar o ID do cartão
 
  //Serial.print("id da tag :"); //imprime no serial o id do cartao
 
  for (byte i = 0; i < mfrc522.uid.size; i++){       // faz uma verificacao dos bits da memoria do cartao
     //ambos comandos abaixo vão concatenar as informacoes do cartao...
     //porem os 2 primeiros irao mostrar na serial e os 2 ultimos guardarao os valores na string de conteudo para fazer as verificacoes
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  //Serial.println();
  conteudo.toUpperCase();                      // deixa as letras da string todas maiusculas
 
  if (conteudo.substring(1) == ID){ // verifica se o ID do cartao lido tem o mesmo ID do cartao que queremos liberar o acesso
      Serial.println("Access Granted!");
  }else{
      Serial.println("Acess denied!");
  }
  Serial.println();
  Serial.println("Aproxime seu cartão do leitor.");
}
