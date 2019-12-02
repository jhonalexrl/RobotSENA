#include <OrangutanMotors.h>

#define ECHO PD0 //El terminal PD0 Esta conectado a ECHO.
#define TRIGER PD1 //El terminal PD1 Esta conectado a TRIGER.
#define BUTTONPIN 13 //el terminal RESET esta conectado al pin 13

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

void freno(byte vel)
  {
  motors.setSpeeds(0,0);

}
