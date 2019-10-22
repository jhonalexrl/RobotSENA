
//Nombre del Autor: IMEEI - Jhon Alexander Rosero
//Fecha Modificación: 22/10/2019
//Uso del programa
//Funcionamiento del programa
//Doy fe que este ejercicio es de mi autoría, en caso de encontrar plagio la nota de todo mi
//trabajo debe ser de NO APROBADO además de las respectivas sanciones a que haya lugar

// Planificador de tareas 
// -------------------- Librerías ------------------------------------------


#include "Led.h"
// -- Variables de control de tiempo --------------------- 
unsigned long int TiempoActual; //Registro en el que se guarda el tiempo en millis actual
// Tiempo total (microsegundos) 
// -- Variables de temporización de tareas --------------- 
// Tarea 1: Control de servo A 
#define PeriodoT1 50 // Periodo de la tarea 1
unsigned long int TiemUltEje; // Tiempo de la última ejecución

// -- Funciones de definición de tareas ------------------

// -- Inicializacion ------------------------------------- 
void setup() {// Se ejecuta cuando el micro se inicia, enciendo, reinicia, para configuracion
  // Inicializacion de temporizadores de tarea 
  TiemUltEje = 0;
  SetupLED();
}

// -- Bucle principal ------------------------------------ 
void loop() { // se ejecuta una y otra vez indefinidamente.
  // Actualizar tiempo 
    TiempoActual = millis(); 
  // Temporizacion tarea 1 

    if (TiempoActual - TiemUltEje >= PeriodoT1) 
      { 
      LedIntermitente(); 
      TiemUltEje = TiempoActual; 
      }
}
