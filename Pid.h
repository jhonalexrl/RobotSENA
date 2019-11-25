
#include <PID_v1.h>
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp = 50, Ki = 0.05, Kd = 1;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void SetupPID()
{
  //initialize the variables we're linked to
  Input = medir();
  Setpoint = 15;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);
}


void TareaPID()
{
  if (State)
  {
    Input = medir();
    myPID.Compute();
    //  Serial.print(Input);
    //  Serial.print(" ");
    //  Serial.println(Setpoint);

    if (Output == 0)
    {
      atras(0);
    }
    else
    {
      if (Output > 0)
      {
        adelante(Output);
      }
      else
      {
        atras(Output);
      }
    }
  }


}

boolean estado;
void loopcontrol()
{
  if (estado == true)
  {
    adelante(150);
  }
  else
  {
    atras(150);
  }
  estado = !estado;
}
