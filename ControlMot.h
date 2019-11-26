/******************************************************************************
  TestRun.ino
  TB6612FNG H-Bridge Motor Driver Example code
  Michelle @ SparkFun Electronics
  8/20/16
  https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library

  Uses 2 motors to show examples of the functions in the library.  This causes
  a robot to do a little 'jig'.  Each movement has an equal and opposite movement
  so assuming your motors are balanced the bot should end up at the same place it
  started.

  Resources:
  TB6612 SparkFun Library

  Development environment specifics:
  Developed on Arduino 1.6.4
  Developed with ROB-9457
******************************************************************************/

// This is the library for the TB6612 that contains the class Motor and all the
// functions
#include <SparkFun_TB6612.h>

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch

#define AIN1 9  //definicion pin 9
#define BIN1 7  //definicion pin 7
#define AIN2 10 //definicion pin 10
#define BIN2 8  //definicion pin 8
#define PWMA 5  //definicion pin 5
#define PWMB 6  //definicion pin 6
#define STBY -1 //definicion pin -1

// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
  
const int offsetA = 1; // variable de desplazamiento A
const int offsetB = 1;  // variable de desplazamiento B

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);        // el motor 1 conectado a los pines (AIN1, AIN2, PWMA, offsetA, STBY)
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);        // el motor 2 conectado a los pines (BIN1, BIN2, PWMB, offsetB, STBY])

void setupmotor()
{
  //Nothing here
}

void atras(byte vel)
{
  // put your main code here, to run repeatedly:
  back(motor1, motor2, vel);    // atras (motor1, motor2, vel)
}

void adelante(byte vel)  //  adelante (byte vel)
{
  //Use of the back function, which takes as arguments two motors
  //and optionally a speed.  Either a positive number or a negative
  //number for speed will cause it to go backwards
  forward (motor1, motor2, vel);   // delante (motor1, motor2, vel)
}
void izquierda(byte vel)
{
  left(motor1, motor2, vel);
}
void derecha(byte vel)
{
  right(motor1, motor2, vel);
}
void freno()
{ 
  brake(motor1, motor2);
}
