// constants won't change. They're used here to set pin numbers:
boolean State= LOW;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void SetupBoton() {
  // initialize the pushbutton pin as an input:
  pinMode(BUTTONPIN, INPUT);
}

void LecBoton() {
  // read the state of the pushbutton value:
 if (digitalRead(BUTTONPIN)==1)
 {
  State = !State;
 }
}
