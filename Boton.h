// constants won't change. They're used here to set pin numbers:
#define BUTTONPIN = 12;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void SetupBoton() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void LecBoton() {
  // read the state of the pushbutton value:
 if (digitalRead(BUTTONPIN)==0)
 {
  buttonState = !buttonState;
 }
}
