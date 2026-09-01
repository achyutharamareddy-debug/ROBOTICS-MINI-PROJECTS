#include <AFMotor.h>
#include <NewPing.h>


#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int dis;

void setup() {
  Serial.begin(9600);

  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
}

void loop() {

  delay(50);

  dis = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.print(dis);
  Serial.println(" cm");

  
  if (dis ==0) {
    // Move Forward
    moveForward();
  }
  else if (dis < 6) {
    // Move Backward
    moveBackward();
  }
  else if (dis >= 6 && dis < 10) {
    // Stop
    stopMotors();
  }
  else if(dis>10 && dis<20){
    // 10 cm or above
    moveForward();

}
else{
   stopMotors();
}
}


void moveForward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void moveBackward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}