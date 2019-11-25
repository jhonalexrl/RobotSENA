//Nombre del Autor: IMEEI - Luis Alejandro Montilla - Guido Roberto Portillo
//Fecha Modificación: 25/11/2019
//Uso del programa: Controla los movimientos de los motores a travez de los parametros creados en
//VOID ATRAS(BYTE VEL) Y VOID ADELANTE(BYTE VEL) aqui se controla la
//velocidad de los motores 1 y 3 los cuales renombramos como D e I.

//motorI_setSpeed:Es a la velocidad que queremos que el motor de la izquierda se mueva.
//motorD_setSpeed:Es a la velocidad que queremos que el motor de la derecha se mueva.

//motorI.run_RELEASE:Es la variable de LANZAMIENTO o desde un lado o punto inicial al
//que se lo quiere iniciar el motor para que llegue a otro lado o punto hacia el lado izquierdo.

//motorD.run_RELEASE:Es la variable de LANZAMIENTO o desde un lado o punto inicial al
//que se lo quiere iniciar el motor para que llegue a otro lado o punto hacia el lado derecho.


//Funcionamiento del programa: aqui esta la programacion sobre los motores de la shield Adafruit
//la cual controla los movimientos de los motores hacia adelante, atras, derecha e izquierda.

//Doy fe que este ejercicio es de mi autoría, en caso de encontrar plagio la nota de todo mi
//trabajo debe ser de NO APROBADO además de las respectivas sanciones a que haya lugar

#include <AFMotor.h>
AF_DCMotor motorI(3);   //motor de la izquierda (3)
AF_DCMotor motorD(1);   //motor de la derecha (1)


void setupmotor() {
  motorI.setSpeed(0);    //velocidad del motor
  motorI.run(RELEASE);   //el motor de la izquierda
  motorD.setSpeed(0);    //velocidad del motor de la derecha
  motorD.run(RELEASE);   //el motor de la derecha
}

void atras(byte vel) {    //atras (byte vel)

  motorI.setSpeed(vel);   //velocidad del motor de la izquierda hacia atras
  motorI.run(BACKWARD);   //el motor de la izquierda se dirige hacia atras
  motorD.setSpeed(vel);   //velocidad del motor de la derecha hacia atras
  motorD.run(BACKWARD);   //el motor de la derecha se dirige hacia atras
}

void adelante(byte vel)   //adelante (byte vel)
{
  motorI.setSpeed(vel);   //velocidad del motor de la izquierda hacia adelante
  motorI.run(FORWARD);    //el motor de la izquierda se dirige hacia adelante
  motorD.setSpeed(vel);   //velocidad del motor de la derecha hacia adelante
  motorD.run(FORWARD);    //el motor de la derecha se dirige hacia adelante
}

void izquierda(byte vel) { //izquierda (byte vel)

  motorI.setSpeed(vel);   //velocidad del motor de la izquierda
  motorI.run(BACKWARD);   //motor de la izquierda hacia atras
  motorD.setSpeed(vel);   //velocidad del motor de la derecha
  motorD.run(FORWARD);    //motor de la derecha hacia adelante
}

void derecha(byte vel)    //derecha (byte vel)
{
  motorI.setSpeed(vel);   //velocidad del motor de la izquierda
  motorI.run(FORWARD);    //motor de la izquierda hacia atras adelante
  motorD.setSpeed(vel);   //velocidad del motor de la derecha
  motorD.run(BACKWARD);   //motor de la derecha hacia atras
}
void freno(byte vel)     //freno (byte vel)
{
  motorI.setSpeed(0);    //velocidad del motor cero
  motorI.run(RELEASE);   //motor de la izquierda frena
  motorD.setSpeed(0);    //velocidad del motor es cero
  motorD.run(RELEASE);  //motor de la derecha frena
}
