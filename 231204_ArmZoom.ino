#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup() {
  Braccio.begin();
  Serial.begin(9600);
}

void agree() {
  for (int i = 0; i < 5; i++) {
    Braccio.ServoMovement(10, 90, 90, 85, 80, 90, 73);
    delay(100);
    Braccio.ServoMovement(10, 90, 90, 95, 100, 90, 73);
    delay(100);
  }
}

void disagree() {
  for (int i = 0; i < 5; i++) {
    Braccio.ServoMovement(10, 75, 90, 90, 90, 90, 73);
    delay(50);
    Braccio.ServoMovement(10, 105, 90, 90, 90, 90, 73);
    delay(50);
  }
}

void cantsay() {
  Braccio.ServoMovement(10, 90, 150, 60, 150, 90, 73);
}

void loop() {
  Braccio.ServoMovement(20,         90, 90, 90, 90, 90,  73);  
  if (Serial.available() > 0) {
    char val = Serial.read();
    if (val == 'y') {
      agree();
    } else if (val == 'n') {
      disagree();
    } else if (val == 'c'){
      cantsay();
    }
  }
}
