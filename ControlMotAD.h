#include <AFMotor.h>

AF_DCMotor motorI(3);
AF_DCMotor motorD(1);


void setupmotor() {
  motorI.setSpeed(0);
  motorI.run(RELEASE);
  motorD.setSpeed(0);
  motorD.run(RELEASE);
}

void atras(byte vel) {

  motorI.setSpeed(vel);
  motorI.run(BACKWARD);
  motorD.setSpeed(vel);
  motorD.run(BACKWARD);
}

void adelante(byte vel)  //  adelante (byte vel)
{
  motorI.setSpeed(vel);  
  motorI.run(FORWARD);
  motorD.setSpeed(vel);  
  motorD.run(FORWARD);
}

void izquierda(byte vel) {

  motorI.setSpeed(vel);
  motorI.run(BACKWARD);
  motorD.setSpeed(vel);
  motorD.run(FORWARD);
}

void derecha(byte vel)  //  adelante (byte vel)
{
  motorI.setSpeed(vel);  
  motorI.run(FORWARD);
  motorD.setSpeed(vel);  
  motorD.run(BACKWARD);
}
