
/********************************************************
 * TAREA DEFINICION PINES, VELOCIDAD COMUNICACION Y SHIELD
********************************************************/
 #pragma once
/********************************************************
 * Definiciones para las shield disponibles
 * 
 * Shield Adafruit 0
 * Shield TB 6612
 *******************************************************/
//#define SHIELD_ADAFRUIT
//#define SHIELD_TB6612
#define SHIELD_FUNDUMOTO

//***********************************
#ifdef SHIELD_ADAFRUIT
//#include <AFMotor.h>
#include "ControlMotAD.h"
#define BUTTONPIN A3     // Configura el pin de entrada del boton
// Configurar el pin en el que se conecta el sensor
#define ECHO   A5 //El terminal A5 Esta conectado a ECHO.
#define TRIGER A4 //El terminal A4 Esta conectado a TRIGER.
#endif
//*************************************************
#ifdef SHIELD_TB6612
#include <SparkFun_TB6612.h>
#include "ControlMot.h"
#define BUTTONPIN 12   // Configura el pin de entrada del boton
// Configurar el pin en el que se conecta el sensor
#define ECHO   A5 //El terminal A5 Esta conectado a ECHO.
#define TRIGER A4 //El terminal A4 Esta conectado a TRIGER.
#endif
//*************************************************
#ifdef SHIELD_FUNDUMOTO
#include "FunduMot.h"
#define BUTTONPIN 3    // Configura el pin de entrada del boton
// Configurar el pin en el que se conecta el sensor
#define ECHO  7 //El terminal A5 Esta conectado a ECHO.
#define TRIGER 8 //El terminal A4 Esta conectado a TRIGER.
#endif
//*************************************************

// Tiempos de tareas
#define PeriodoT1 50      // Periodo de la tarea 1 LED blink
#define PeriodoT2 5000      // Periodo de la tarea 2 loop control
#define PeriodoT3 50 // Periodo de la tarea PID
#define PeriodoT4 10 // Periodo de la tarea Comm
#define PeriodoT5 10 // Periodo de la tarea Lectura del boton
//************************************************

// tarea de comunicacion configura la velocidad (9600,...)
#define BAUD_RATE 115200

// configura el pin de blink led
#define PLED 2

// Configura el pin de entrada del boton
