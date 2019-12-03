#include <OrangutanMotors.h>

OrangutanMotors motors; 

void setupmotor() {

int vel;
}

void izquierda(byte vel)                
{

  motors.setSpeeds(-vel, vel);

}
void adelante(byte vel)                
{

  motors.setSpeeds(vel, vel);
}
void atras(byte vel)                

{
  motors.setSpeeds(-vel, -vel);
}

  void derecha(byte vel)
  {
  motors.setSpeeds(vel, -vel);

}

 void freno()
  {
  motors.setSpeeds(0,0);

}
