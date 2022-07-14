#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TAM_CODIGO 7
#define TAM_CADENA 20

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[TAM_CODIGO];
	int estadoVuelo;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
Passenger* Passenger_newParametrosAlta(int id, char* nombreStr, char* apellidoStr, float precio, char* codigoVueloStr, int tipoPasajero, int estadoVuelo);

void Passenger_delete();

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_getTipoPasajeroStr(int tipoPasajero , char* tipoStr);
int Passenger_getEstadoVueloStr(int estadoVuelo , char* estadoStr);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

void Passenger_imprimir(Passenger* pasajero);

int Passenger_funcionCriterio(void* item1, void* item2);

int Passenger_actualizarUltimoId(int idViejo);

#endif /* PASSENGER_H_ */
