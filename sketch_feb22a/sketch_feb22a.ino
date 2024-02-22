// Motor 1
int in1 = 7;
int in2 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  spin();

}

void spin() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  delay(2000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

}
