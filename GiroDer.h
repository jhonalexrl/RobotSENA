// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor(3);

void setupGiroDer() {
  Serial.begin(115200);        
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
 
  motor.run(RELEASE);
}

void GiroDer() {
  uint8_t i;
  
  Serial.print("tick");
  
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
 }
  
  Serial.print("tock");

  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);    
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
 }
  

  Serial.print("tech");
  motor.run(RELEASE);
}
