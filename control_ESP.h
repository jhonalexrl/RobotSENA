
#define STBY 27
//******************************************************************************************//
//para motor 1
const int freq = 50000;
const int ledChannel = 0 ;
const int resolution = 8;
#define PWMA 14
#define AIN2 19
#define AIN1 18

//******************************************************************************************//
//para motor 2

const int freq2 = 50000;
const int ledChannel2 = 0 ;
const int resolution2 = 8;
#define PWMB 4
#define BIN1 26
#define BIN2 25
//

void setupmotor() {
  pinMode(STBY, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  ledcSetup(ledChannel, freq, resolution);
  ledcSetup(ledChannel2, freq2, resolution2);
  ledcAttachPin (PWMA, ledChannel);
  ledcAttachPin (PWMB, ledChannel2);
}



void adelante(byte vel)
{
  digitalWrite(STBY, HIGH); // put your main code here, to run repeatedly:

  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(BIN1, LOW);
  ledcWrite (ledChannel, vel);
  ledcWrite (ledChannel2, vel);
}

void atras(byte vel)
{
  digitalWrite(STBY, HIGH); // put your main code here, to run repeatedly:

  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, HIGH);

  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, HIGH);
  ledcWrite (ledChannel, vel);
  ledcWrite (ledChannel2, vel);
}
void izquierda(byte vel)
{
  digitalWrite(STBY, HIGH); // put your main code here, to run repeatedly:

  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, HIGH);

  digitalWrite(BIN2, HIGH);
  digitalWrite(BIN1, LOW);
  ledcWrite (ledChannel, vel);
  ledcWrite (ledChannel2, vel);
}
void derecha(byte vel)
{

  digitalWrite(STBY, HIGH); // put your main code here, to run repeatedly:

  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);

  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, HIGH);
  ledcWrite (ledChannel, vel);
  ledcWrite (ledChannel2, vel);
}
void freno()
{

  digitalWrite(STBY, LOW); // put your main code here, to run repeatedly:

  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, LOW);

  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, LOW);

}
