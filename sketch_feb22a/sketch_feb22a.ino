const int in1 = 7;
const int in2 = 8;
const int in3 = 12;
const int in4 = 13;

const int ir1 = 2;
const int ir2 = 4;

int state = 0;

int mode = 2;

void setup() {

  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void spinLeft() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

}

void spinRight() {

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}

int irLeft_input() {
  return !digitalRead(ir1);

}

int irRight_input() {
  return !digitalRead(ir2);

}

void print_state() {
  Serial.print(state);
}

void loop() {

  if(mode == 1) {
    spinLeft();
    spinRight();

  } else if(mode == 2){

    if(irLeft_input() && !irRight_input() && state != 1) {
      state = 1;
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      print_state();
      spinLeft();

    } else if(irRight_input() && !irLeft_input() && state != 2) {
      state = 2;
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      print_state();
      spinRight
    ();

    } else if(irLeft_input() && irRight_input()) {
      state = 0;
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(2000);
    
    }

    delay(200);
  }
}

bool detect_line() {
  int temp1 = state;
  while(true) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    spinLeft();
    delay(200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    spinRight();
    if(temp1 != state) {
      break;
    }
  }
}
