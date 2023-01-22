void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  
  int intervaloPisca1;
  int intervaloPisca2;//mesma coisa que declarar um objeto no python 
  intervaloPisca1 = 200;
  intervaloPisca2 = 1000;
  
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(intervaloPisca1);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW); 
  delay(intervaloPisca2);
}
