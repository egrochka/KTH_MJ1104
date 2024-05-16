// Reserve pins 7 and for left motor, 12 and 13 for right motor
const int in1 = 7;
const int in2 = 8;
const int in3 = 12;
const int in4 = 13;

// Reserve pin 2 for left sensor, 4 for right sensor
const int ir1 = 2;
const int ir2 = 4;

// Primary state of the vehicle (0 to disable all motors)
int state = 0;

// Debug mode (off by default)
const bool debug = false;

// Constants
const int delayInput = 20;
const int delayRotation = 50;
const int delayCharge = 26*1000;

class Motor {
  // A motor object with two corresponding output pins

public:
  int pin1;
  int pin2;

  void direction(int dir) {
    //Changes the direction of the motor

    if (dir == 1) {
      // Forward

      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);

    } else if (dir == -1) {
      // Backwards

      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);

    } else {
      // Off

      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
  }
};

class Sensor {
  // An ir sensor object with a corresponding input pin

public:
  int inputPin;

  bool getSignal() {
    // Returns the !output of a sensor (TRUE if detected, FALSE otherwise)

    return !digitalRead(inputPin);
  }
};

// Create two global motor and sensor objects
Motor motorLeft;
Motor motorRight;
Sensor sensorLeft;
Sensor sensorRight;

void setup() {

  Serial.begin(9600);

  // Set motor pins to output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set sensor pins for input
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);

  // Assign pins to motor objects
  motorLeft.pin1 = in1;
  motorLeft.pin2 = in2;
  motorRight.pin1 = in3;
  motorRight.pin2 = in4;

  // Assign pins to all sensor objects
  sensorLeft.inputPin = ir1;
  sensorRight.inputPin = ir2;

  // Disable all motors by default
  motorLeft.direction(0);
  motorRight.direction(0);

  //Charge time
  delay(delayCharge);
  motorLeft.direction(1);
}

void loop() {
  // Main program

  int irLeft = sensorLeft.getSignal();
  int irRight = sensorRight.getSignal();
  print_serial(irLeft, irRight);

  if (irLeft && !irRight && state != 1) {
    // If right sensor looses signal (black line detected) spin left motor

    state = 1;
    delay(delayInput);
    motorLeft.direction(0);
    motorRight.direction(1);

  } else if (irRight && !irLeft && state != 2) {
    // If left sensor looses signal (black line detected) spin right motor

    state = 2;
    delay(delayInput);
    motorLeft.direction(1);
    motorRight.direction(0);

    //} else if(!irLeft && !irRight && state != 0) {
    //  // If both motors lose signal disable motors

    //  motorLeft.direction(0);
    //  motorRight.direction(0);

    //} else if(irLeft && irRight) {
    // If both sensor detect a line (happens only on a corner) retract and continue
    //
    //  if(state == 1) {
    //
    //    motorLeft.direction(-1);
    //    motorRight.direction(0);
    //    delay(delayRotation);
    //   motorLeft.direction(0);
    //   motorRight.direction(1);
    // }
    // if(state == 2) {
    //
    //    motorLeft.direction(0);
    //  motorRight.direction(-1);
    //delay(delayRotation);
    // motorLeft.direction(1);
    // motorRight.direction(0);
    //}
  }
}

void print_serial(int left, int right) {
  // Prints out the values of sensorLeft, sensorRight and state

  Serial.print("Left:");
  Serial.print(left);
  Serial.print(",");
  Serial.print("Right:");
  Serial.print(right);
  Serial.print(",");
  Serial.print("State:");
  Serial.print(state);
  Serial.print("\n");
}