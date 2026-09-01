#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

// Motors
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;
int speed = 200;   // default speed

void setup()
{
  bluetoothSerial.begin(9600);
  
  Stop();
}

void loop()
{
  if (bluetoothSerial.available())
  {
    command = bluetoothSerial.read();

    // Movement Commands
    if (command == 'F') {
      forward();
    } 
    else if (command == 'B') {
      back();
    } 
    else if (command == 'L') {
      left();
    } 
    else if (command == 'R') {
      right();
    } 
    else if (command == 'S') {
      Stop();
    }
    // Diagonal Commands
    else if (command == 'G') {
      forwardLeft();
    } 
    else if (command == 'I') {
      forwardRight();
    } 
    else if (command == 'H') {
      backLeft();
    } 
    else if (command == 'J') {
      backRight();
    }
    // Speed Control Commands
    else if (command == '0') {
      speed = 0;
    } 
    else if (command == '1') {
      speed = 80;
    } 
    else if (command == '2') {
      speed = 120;
    } 
    else if (command == '3') {
      speed = 160;
    } 
    else if (command == '4') {
      speed = 200;
    } 
    else if (command == '5') {
      speed = 255;
    }
  }
}

// --- Keep your existing movement functions (forward, back, etc.) below ---

void setSpeedAll() {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}

void forward() {
  setSpeedAll();
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void back() {
  setSpeedAll();
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void left() {
  setSpeedAll();
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void right() {
  setSpeedAll();
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void forwardLeft() {
  setSpeedAll();
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
}

void forwardRight() {
  setSpeedAll();
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
}

void backLeft() {
  setSpeedAll();
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);
}

void backRight() {
  setSpeedAll();
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}