#ifndef ABM_H_
#define ABM_H_

#include "input.h"
#define TAM_CHAR 51

//ESTADO ABM
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//ESTADO VUELO
#define ACTIVO 2
#define CANCELADO 3

//TIPO PASAJERO
#define TURISTA 4
#define EJECUTIVO 5
#define PREMIUM 6

typedef struct
{
	int id;
	char name[TAM_CHAR];
	char lastname[TAM_CHAR];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} sPassengers;

//PROTOTIPOS FUNCIONES UTILES EN ABM
void sPass_initPassenger(sPassengers array[], int TAM);
int sPass_getFreeIndex(sPassengers array[], int TAM);
int sPass_findPassengerByID(sPassengers array[], int TAM, int ID);
sPassengers sPass_enterData(void);
sPassengers sPass_modifyOne(sPassengers Pasajeros);
void sPass_printOne(sPassengers Pasajero, int criterio);
int sPass_printPassengers(sPassengers Pasajeros[], int TAM, int criterio);
void sPass_printAverage(sPassengers array[], int TAM);
int sPass_sortPassengers(sPassengers array[], int TAM, int criterio);

//PROTOTIPOS FUNCIONES ABM
int sPass_addPassengers(sPassengers array[], int TAM);
int sPass_removePassengers(sPassengers array[], int TAM);
int sPass_modifyData(sPassengers array[], int TAM);

#endif /* ABM_H_ */
