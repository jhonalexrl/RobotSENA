
boolean LEDStatus = LOW;
//---------configuración de la tarea LED

void SetupLED()
{
  LEDStatus = LOW;
  pinMode(PLED, OUTPUT);
}

//---------Actualización de la tarea LED1
void LedIntermitente()
{
  if (State)
  {
    digitalWrite(PLED, LEDStatus);
    LEDStatus = !LEDStatus;
  }
}
