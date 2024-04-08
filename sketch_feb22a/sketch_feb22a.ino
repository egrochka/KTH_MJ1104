const int in1 = 7;
const int in2 = 8;
const int in3 = 12;
const int in4 = 13;

const int ir1 = 2;
const int ir2 = 4;

int state = 0;

int mode = false;

void setup() {

  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ir1, INPUT)
  pinMode(ir2, INPUT)

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void loop() {

  if(!mode) {
    spin1();

    //delay(1000);

    //spin2();

  } else {

    if(ir1_input() && state != 1) {
      state = 1;
      spin2();
      print_state()

    } else if(ir_input2() && state != 2) {
      spin1();
      state = 2;

    } else if(!ir_input1() && !ir_input2()) {
      state = 0;
    
    }

    delay(20);
  }
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

int ir1_input() {
  return !digitalRead(ir1);

}

int ir2_input() {
  return !digitalRead(ir2);

}

void print_state() {
  Serial.print(state);
}