/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/SerialEvent
*/

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void SetupComm() {
  // initialize serial:
  Serial.begin(BAUD_RATE);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  pinMode(PLED, OUTPUT);      //Configura pin 13 como salida

}

void Comm() {
  // print the string when a newline arrives:
  if (stringComplete) {
  String temp;
  byte tempor;
    if (inputString.startsWith("on"))
    {
      digitalWrite(PLED, HIGH);     // enciende el led conectado en LedPin
      State = HIGH;
    }
    if (inputString.startsWith("off"))
    {
      digitalWrite(PLED, LOW);     // enciende el led conectado en LedPin
      State = LOW;
    }
    if (inputString.startsWith("dis"))
    {
      Serial.println(Input);
    }
    if (inputString.startsWith("set="))
    {
      temp = inputString.substring(4);
      Setpoint =  temp.toInt();
      Serial.println(Setpoint);
    }
    if (inputString.startsWith("ade="))
    {
      temp = inputString.substring(4);
      tempor =  temp.toInt();
      adelante(tempor);
      Serial.println(tempor);
    }

    if (inputString.startsWith("ade="))
    {
      temp = inputString.substring(4);
      tempor =  temp.toInt();
      adelante(tempor);
      Serial.println(tempor);
    }

    if (inputString.startsWith("atr="))
    {
      temp = inputString.substring(4);
      tempor =  temp.toInt();
      atras(tempor);
      Serial.println(tempor);
    }


     if (inputString.startsWith("der="))
    {
      temp = inputString.substring(4);
      tempor =  temp.toInt();
      derecha(tempor);
      Serial.println(tempor);
    }

    if (inputString.startsWith("izq="))
    {
      temp = inputString.substring(4);
      tempor =  temp.toInt();
      izquierda(tempor);
      Serial.println(tempor);
    }

    if (inputString.startsWith("freno"))
    {
       freno();
    }
       
    // clear the string:
    //Serial.println(inputString);
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
