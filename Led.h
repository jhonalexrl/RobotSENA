const int PLED = 13;
boolean LEDStatus = LOW;
boolean State= LOW;


//---------configuración de la tarea LED
void SetupLED()
{ LEDStatus = LOW;
  pinMode(PLED, OUTPUT);
}

//---------Actualización de la tarea LED1
void LedIntermitente()
{ digitalWrite(PLED, LEDStatus);
  LEDStatus = !LEDStatus;
}
