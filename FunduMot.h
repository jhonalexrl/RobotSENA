/*
   Shied para el control de motores con configuracion de un L298
   Creado por Jhon Alexander Rosero
*/

// The following pin designations are fixed by the shield
int const BUZZER = 4;
//  Motor A
int const ENA = 10;
int const INA = 12;
//  Motor B
int const ENB = 11;
int const INB = 13;
// Constantes de configuracion de motor
int const MIN_SPEED = 27;   // Set to minimum PWM value that will make motors turn
int const MAX_SPEED = 255;
int const IN_MAX = 255;
//===============================================================================
//  Initialization
//===============================================================================
void setupmotor()
{
  pinMode(ENA, OUTPUT);   // set all the motor control pins to outputs
  pinMode(ENB, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

/*
   Motor function does all the heavy lifting of controlling the motors
   mot = motor to control either 'A' or 'B'.  'C' controls both motors.
   dir = Direction either '1' Forward or '0' Reverse
   speed = Speed.  Takes in 1-100 percent and maps to 0-255 for PWM control.
   Mapping ignores speed values that are too low to make the motor turn.
   In this case, anything below 27, but 0 still means 0 to stop the motors.
*/
void Motor(char mot, boolean dir, int speed)
{
  // remap the speed from range 0-100 to 0-255
  int newspeed;
  if (speed == 0)
    newspeed = 0;   // Don't remap zero, but remap everything else.
  else
    newspeed = map(speed, 1, IN_MAX, MIN_SPEED, MAX_SPEED);

  switch (mot) {
    case 'A':   // Controlling Motor A
      if (dir) {
        digitalWrite(INA, HIGH);
      }
      else {
        digitalWrite(INA, LOW);
      }
      analogWrite(ENA, newspeed);
      break;

    case 'B':   // Controlling Motor B
      if (dir) {
        digitalWrite(INB, HIGH);
      }
      else {
        digitalWrite(INB, LOW);
      }
      analogWrite(ENB, newspeed);
      break;

    case 'C':  // Controlling Both Motors
      if (dir) {
        digitalWrite(INA, HIGH);
        digitalWrite(INB, HIGH);
      }
      else {
        digitalWrite(INA, LOW);
        digitalWrite(INB, LOW);
      }
      analogWrite(ENA, newspeed);
      analogWrite(ENB, newspeed);
      break;
  }
  // impresion para el desarrollo o la correccion de errores
  //  Serial.print ("Motor: ");
  //  if (mot=='C')
  //      Serial.print ("Both");
  //    else
  //      Serial.print (mot);
  //  Serial.print ("t Direction: ");
  //  Serial.print (dir);
  //  Serial.print ("t Speed: ");
  //  Serial.print (speed);
  //  Serial.print ("t Mapped Speed: ");
  //  Serial.println (newspeed);
}

//********************************************************************************
void adelante(byte vel)
{
  Motor('C', 1, vel);
}
void atras(byte vel)
{
  Motor('C', 0, vel);
}
void izquierda(byte vel)
{
  Motor('A', 1, vel);
  Motor('B', 0, vel);  
}
void derecha(byte vel)
{
  Motor('A', 0, vel);
  Motor('B', 1, vel);
}
void freno()
{
  Motor('C', 1, 0);
}
