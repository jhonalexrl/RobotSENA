//Nombre del Autor: IMEEI - Jhon Alexander Rosero
//Fecha Modificación: 22/10/2019
//Uso del programa
//Funcionamiento del programa
//Doy fe que este ejercicio es de mi autoría, en caso de encontrar plagio la nota de todo mi
//trabajo debe ser de NO APROBADO además de las respectivas sanciones a que haya lugar

// Planificador de tareas 
// -------------------- Librerías ------------------------------------------
#include "Pines.h"
#include "Boton.h"
#include "ControlMot.h"
#include "Led.h"
#include "SenDis.h"
#include "Pid.h"
#include "Comm.h"



// -- Variables de control de tiempo --------------------- 
unsigned long int TiempoActual; //Registro en el que se guarda el tiempo en millis actual
// Tiempo total (microsegundos) 
// -- Variables de temporización de tareas --------------- 
// Tarea 1: Control de servo A 
#define PeriodoT1 50 // Periodo de la tarea 1
#define PeriodoT2 20 // Periodo de la tarea 2
#define PeriodoT3 50 // Periodo de la tarea 3
#define PeriodoT4 10 // Periodo de la tarea 3
#define PeriodoT5 10 // Periodo de la tarea 3
unsigned long int TiemUltEje1; // Tiempo de la última ejecución 1
unsigned long int TiemUltEje2; // Tiempo de la última ejecución 2
unsigned long int TiemUltEje3; // Tiempo de la última ejecución 3
unsigned long int TiemUltEje4; // Tiempo de la última ejecución 3
unsigned long int TiemUltEje5; // Tiempo de la última ejecución 3


// -- Funciones de definición de tareas ------------------

// -- Inicializacion ------------------------------------- 
void setup() {// Se ejecuta cuando el micro se inicia, enciendo, reinicia, para configuracion
  // Inicializacion de temporizadores de tarea 
  TiemUltEje1 = 0;
  SetupLED();
  TiemUltEje2 = 0;
  setupSen();
  TiemUltEje3 = 0;
  SetupComm();
  TiemUltEje4 = 0;
  setupmotor();
   SetupPID();
   SetupBoton();
  
}

// -- Bucle principal ------------------------------------ 
void loop() { // se ejecuta una y otra vez indefinidamente.
  // Actualizar tiempo 
    TiempoActual = millis(); 
  // Temporizacion tarea 1 

    if (TiempoActual - TiemUltEje1 >= PeriodoT1) 
      { 
      LedIntermitente(); 
      TiemUltEje1 = TiempoActual; 

      }
       if (TiempoActual - TiemUltEje2 >= PeriodoT2) 
       {
   
      //loopSen(); 
      TiemUltEje2 = TiempoActual;
      }
      if (TiempoActual - TiemUltEje3 >= PeriodoT3) 
       {
      TareaPID(); 
      TiemUltEje3 = TiempoActual;
      }
      if (TiempoActual - TiemUltEje4 >= PeriodoT4) 
       {
      Comm(); 
      TiemUltEje4 = TiempoActual;
      }
          if (TiempoActual - TiemUltEje5 >= PeriodoT5) 
       {
      LecBoton(); 
      TiemUltEje5 = TiempoActual;
      }  
}
