#include "IRremote.h"

int velo = 0;
IRrecv irrecv(RECEIVER);
decode_results results;

#define INC 15

void setupIR()
{
  irrecv.enableIRIn();
}


void ControlIR()
{
  if (irrecv.decode(&results))

  {
    switch (results.value)
    {
      case 0xFF18E7: Serial.println("Tecla: Arriba");

        Serial.println(velo);
        velo += INC;
        if (velo >= 255)
        {
          velo = 255;
        }

        break;
      case 0xFF10EF: Serial.println("Tecla: Izquierda");
        break;
      case 0xFF38C7: Serial.println("Tecla: OK");
        velo=0;
        break;
      case 0xFF5AA5: Serial.println("Tecla: Derecha");
        Serial.println(velo);
        velo += INC;
        if (velo >= 255)
        {
          velo = 255;
        }

        break;
      case 0xFF4AB5: Serial.println("Tecla: Abajo");
        Serial.println(velo);
        velo -= INC;
        Serial.println("nueva velocidad");
        Serial.println(velo);
        if (velo <= -255)
        {
            velo = -255;
        }

        break;
      case 0xFFA25D: Serial.println("Tecla: 1");
        digitalWrite(PLED, HIGH);     // enciende el led conectado en LedPin
        State = HIGH;
        break;
      case 0xFF629D: Serial.println("Tecla: 2");
        digitalWrite(PLED, LOW);     // enciende el led conectado en LedPin
        State = LOW;
        break;
      case 0xFFE21D: Serial.println("Tecla: 3");
        break;
      case 0xFF22DD: Serial.println("Tecla: 4");
        digitalWrite(4, !digitalRead(4));
        break;
      case 0xFF02FD: Serial.println("Tecla: 5");
        digitalWrite(5, !digitalRead(5));
        break;
      case 0xFFC23D: Serial.println("Tecla: 6");
        digitalWrite(6, !digitalRead(6));
        break;
      case 0xFFE01F: Serial.println("Tecla: 7");
        digitalWrite(7, !digitalRead(7));
        break;
      case 0xFFA857: Serial.println("Tecla: 8");
        break;
      case 0xFF906F: Serial.println("Tecla: 9");
        break;
      case 0xFF6897: Serial.println("Tecla: *");
        break;
      case 0xFF9867: Serial.println("Tecla: 0");
        break;
      case 0xFFB04F: Serial.println("Tecla: #");

        break;
    }
    irrecv.resume();
  }

   if (velo == 0)
    {
      //freno();
    }
    else
    {
      if (velo > 0)
      {
        adelante(velo);
      }
      else
      {
        atras(-velo);
      }
    }


}
