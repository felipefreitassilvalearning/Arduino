#define pinBotao 2 

int n1;

void setup() {
  Serial.begin(9600);
  pinMode(pinBotao, INPUT_PULLUP);

}

void loop() {
  int n3 = 0;

  for (int n1 = 0; n1 < 50; n1++) { 
    Serial.print(char((n1 %10) + 48)); 
    if (digitalRead(pinBotao) == LOW) { 
      delay(400);
      break;
    }
    delay(50);
  }

Serial.println();

letrasMaiusculas: 
int n2 = 0;
while (n2 < 50) { 
  Serial.print(char((n2 % 65) + 65)); 
  n2 ++;
  if (digitalRead(pinBotao) == LOW) { 
    delay(400);
    continue;
    
  }
  delay(50);
}
Serial.println();

//laço das letras minúsculas 

do { //diferença para o while, é que o do executa o laço pelo menos 1 vez antes da condição
  //determinada pelo while 
  n3 = random(25); 
  Serial.print(char(n3 + 97)); //lembrando que esses dados são para a tabela ASC 
  if (digitalRead(pinBotao) == LOW) { 
    delay(400);
    Serial.println();
    goto letrasMaiusculas; //sempre usar o goto com relação a algum critério 
  }
  delay(50);
} while (n3 != 16); 
Serial. println();
}
