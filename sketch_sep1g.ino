#include <AFMotor.h>

AF_DCMotor motor1(1);   // Front Left
AF_DCMotor motor2(2);   // Rear Left
AF_DCMotor motor3(3);   // Front Right
AF_DCMotor motor4(4);   // Rear Right

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void setup() {
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
}

void loop() {


  // Move Forward

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(5000);

  stopMotors();
  delay(1000);

  // Move Backward
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(5000);

  stopMotors();
  delay(1000);


  // Left Turn
  // Left wheels -> Backward
  // Right wheels -> Forward
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(1500);

  stopMotors();
  delay(1000);


  // Right Turn
  // Left wheels -> Forward
  // Right wheels -> Backward

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(1500);

}