
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
#define SHIELD_ADAFRUIT
//#define SHIELD_TB6612
//***********************************
#ifdef SHIELD_ADAFRUIT
//#include <AFMotor.h>
#include "ControlMotAD.h"
#endif
//*************************************************
#ifdef SHIELD_TB6612
#include <SparkFun_TB6612.h>
#include "ControlMot.h"
#endif
//*************************************************
// Tiempos de tareas
#define Ts1 50      // Periodo de la tarea 1 LED blink
#define Ts2 50      // Periodo de la tarea 2 Medicion Sensor

//************************************************

// tarea de comunicacion configura la velocidad (9600,...)
#define BAUD_RATE 115200

// configura el pin de blink led
#define BLED_PCU  13

// configura los pines de conexion de sensor HC-SR04
#define TRIGGER  A0
#define ECHO A1
