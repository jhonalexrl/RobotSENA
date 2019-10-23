#include <AFMotor.h>

AF_DCMotor MotorIzq(1);
AF_DCMotor MotorDer(3);



void setupDireccion(){
MotorIzq.setSpeed(255);
MotorDer.setSpeed(255);
MotorIzq.run(RELEASE);
MotorDer.run(RELEASE);
 }

void adelante(){
    MotorIzq.run(FORWARD); //delante
    MotorDer.run(FORWARD); //delante 
}

void atras(){
    MotorIzq.run(BACKWARD); //delante
    MotorDer.run(BACKWARD); //delante 
}

void izq(){
    MotorIzq.run(FORWARD); //delante
    MotorDer.run(BACKWARD); //atras
}
void der(){
    MotorIzq.run(BACKWARD); //giro derecha
    MotorDer.run(FORWARD);
}

void freno(){
    MotorIzq.run(RELEASE); //delante
    MotorDer.run(RELEASE); //delante 
}
