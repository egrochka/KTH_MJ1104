int in1 = 7;
int in2 = 8;
int in3 = 12;
int in4 = 13;

void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void loop() {

  //spin1();

  //delay(1000);

  spin2();

}

void spin1() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  delay(2000);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

}

void spin2() {

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(2000);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}


