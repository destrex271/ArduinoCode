#include <AFMotor.h>
AF_DCMotor bottom(1); // create motor #2
AF_DCMotor left(3); //left
//AF_DCMotor right(4); //right
AF_DCMotor clip(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  bottom.setSpeed(200);     // set the speed to 200/255
  left.setSpeed(255);
  //rightMotor.setSpeed(255);
  clip.setSpeed(200);
}

int stopTime = 1950;
int i = 0;

void moveDown(){
    left.run(FORWARD);
    delay(stopTime);
    left.run(RELEASE);
    delay(1000);
}

void moveUp(){
    left.run(BACKWARD);
    delay(stopTime);
    left.run(RELEASE);
    delay(1000);
}

void clipOpen(){
    clip.run(BACKWARD);
    delay(1000);
    clip.run(RELEASE);
    delay(1000);
}

void leftMove(){
  bottom.run(FORWARD);
    delay(stopTime);
    bottom.run(RELEASE);
    delay(1000);
}

void rightMove(){
  bottom.run(BACKWARD);
    delay(stopTime);
    bottom.run(RELEASE);
    delay(1000);
}

void closeClip(){
  clip.run(FORWARD);
    delay(1000);
    clip.run(RELEASE);
    delay(1000);
}

void loop() {
  if(i <= 0){
    moveDown();
    clipOpen();
    closeClip();
    moveUp();
    leftMove();
    clipOpen();
    closeClip();
    rightMove();
    i++;
  }
    
}



/*
 * LEFT MOTOR
 * //bottomMotor.run(FORWARD);
  leftMotor.setSpeed(200);// turn it on going forward
  leftMotor.run(FORWARD);
  //rightMotor.run(FORWARD);
  delay(stopTime);
  Serial.print("tack");
  //bottomMotor.run(RELEASE);
//  leftMotor.run(RELEASE);
  //rightMotor.run(RELEASE);
  // stopped
//  delay(1000);
  Serial.print("tock");
  //bottomMotor.run(BACKWARD);     // the other way
  //rightMotor.run(BACKWARD);
  //delay(100);
  leftMotor.setSpeed(255);
  leftMotor.run(BACKWARD);
  delay(stopTime+1000);
  Serial.print("tack");
  //bottomMotor.run(RELEASE);      // stopped
  leftMotor.run(RELEASE);
  //rightMotor.run(RELEASE);
  delay(1000);
*/
