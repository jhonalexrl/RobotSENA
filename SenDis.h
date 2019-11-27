//Nombre del Autor: Jorge Andres,Hugo Navarrete, Henry Estrella
//Fecha: 21/10/2019
//Uso del programa:Medir Distancia
//Funcionamiento del programa: Pormedio del sensor ultrasonido, obtener la distancia.
//Doy fe que este ejercicio es de mi autoría, en caso de encontrar plagio la nota de todo mi
//trabajo debe ser de NO APROBADO además de las respectivas sanciones a que haya lugar

long tiempo;//
double distAct, DistanciaMedia;

float alpha = 0.1;
//intervalo de medicion de tiempo
unsigned int interval1 = interval1 * alpha;

void setupSen() { // El setup es la primera función en ejecutarse dentro de un programa en Arduino.
  Serial.begin(115200);// Establece la velocidad de datos en bits por segundo
  pinMode(TRIGER, OUTPUT); /*activación del pin A5 como salida: para el pulso ultrasónico*/
  pinMode(ECHO, INPUT); /*activación del pin A4 como entrada: tiempo del rebote del ultrasonido*/
}

float medir() //Medicion en decimales
{
  digitalWrite(TRIGER, LOW); // Por cuestión de estabilización del sensor en bajo
  delayMicroseconds(5); // Pausa el programa durante el tiempo para recibir la señar de ultrasonido.
  digitalWrite(TRIGER, HIGH); // envío del pulso ultrasónico*/
  delayMicroseconds(10);//Pausa el programa durante el tiempo para recibir la señar de ultrasonido.
  tiempo = pulseIn(ECHO, HIGH);
  /* Función para medir la longitud del pulso entrante. Mide el tiempo que a transcurrido entre el envío
    del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin ECHO empieza a recibir el rebote, HIGH, hasta que
    deja de hacerlo, LOW, la longitud del pulso entrante
  */

  float distancia = float(0.01716 * tiempo); /*fórmula para calcular la distancia obteniendo un valor flotante* para que una mejor precicion./
  /*Monitorización en centímetros por el monitor serial*/
  //Serial.print("Distancia ");
  //Serial.println(distancia);
  //Serial.println(" cm");

  DistanciaMedia = (alpha * distancia) + ((1 - alpha) * DistanciaMedia); //Filtro pasabajo EMA

  return DistanciaMedia;// Con este comando realiza el retorno de la medicion.
}

void loopSen()  //es la que se ejecuta un número infinito de veces.
{
  //Serial.print(distAct);//se puede  repetirla funcion de medir
  //Serial.print(" ");
  Serial.println(DistanciaMedia);//se puede  repetirla funcion de medir
}
