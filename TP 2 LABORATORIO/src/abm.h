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

//PROTOTIPOS ABM
int sPass_addPassengers(sPassengers array[], int TAM);
int sPass_removePassengers(sPassengers array[], int TAM);
int sPass_modifyData(sPassengers array[], int TAM);
void sPass_initPassenger(sPassengers array[], int TAM);
int sPass_printPassengers(sPassengers Pasajeros[], int TAM, int criterio);
void sPass_printAverage(sPassengers array[], int TAM);
int sPass_sortPassengers(sPassengers array[], int TAM, int criterio);
int sPass_CargaForzada(sPassengers listaPasajeros[]);

#endif /* ABM_H_ */
