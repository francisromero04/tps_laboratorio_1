#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* aux = NULL;
	aux = (Passenger*)malloc(sizeof(Passenger));
	return aux;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,  char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
    Passenger* this = NULL;
    this = Passenger_new();

	if(this!=NULL)
	{
		if( !(Passenger_setId(this, atoi(idStr)) &&
			 Passenger_setNombre(this, nombreStr) &&
			 Passenger_setApellido(this, apellidoStr) &&
			 Passenger_setPrecio(this, atoi(precioStr)) &&
			 Passenger_setCodigoVuelo(this, codigoVueloStr) &&
			 Passenger_setTipoPasajero(this, atoi(tipoPasajeroStr)) &&
			 Passenger_setEstadoVuelo(this, atoi(estadoVueloStr))) )
		{
			Passenger_delete(this);
		}
	}

	return this;
}

//UTILIZO ESTA CUANDO UN USUARIO DA DE ALTA UN PASAJERO USANDO LOS INPUTS (controller_addPassenger)
Passenger* Passenger_newParametrosAlta(int id, char* nombreStr, char* apellidoStr, float precio, char* codigoVueloStr, int tipoPasajero, int estadoVuelo)
{
	Passenger* this;

	if(id > 0 && nombreStr != NULL && apellidoStr != NULL && tipoPasajero > 0 && precio > 0 && codigoVueloStr != NULL && estadoVuelo > 0)
	{
		this = Passenger_new();

		if(this != NULL)
		{
			if(Passenger_setId(this, id) == 1 && Passenger_setNombre(this, nombreStr) == 1 &&
			   Passenger_setApellido(this, apellidoStr) == 1 && Passenger_setPrecio(this, precio) == 1 &&
			   Passenger_setCodigoVuelo(this, codigoVueloStr) == 1 && Passenger_setTipoPasajero(this, tipoPasajero) == 1 &&
			   Passenger_setEstadoVuelo(this, estadoVuelo) == 1)
			{
				puts("\nALTA DE PASAJERO EXITOSA!\n");
			}
			else
			{
				Passenger_delete(this);
			}
		}
	}

	return this;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int Passenger_setId(Passenger* this, int id)
{
	int rtn = -1;

	if(this != NULL && id >= 1)
	{
		this->id = id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 20 && strlen(nombre) > 1)
		{
			strcpy(this->nombre, nombre);
			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int rtn = -1;
	if(this != NULL && apellido != NULL)
	{
		if(strlen(apellido) < 20 && strlen(apellido) > 1)
		{
			strcpy(this->apellido, apellido);
			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int rtn = -1;

	if(this!=NULL)
	{
		if(precio >= 500)
		{
			this->precio = precio;
			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int rtn = -1;
	if(this != NULL && codigoVuelo!=NULL)
	{
		if(strlen(codigoVuelo) < 10 && strlen(codigoVuelo) > 1)
		{
			strcpy(this->codigoVuelo, codigoVuelo);
			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int rtn = -1;

	if(this!=NULL)
	{
		if(tipoPasajero <=3 && tipoPasajero >=1)
		{
			this->tipoPasajero = tipoPasajero;
			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int rtn = -1;

	if(this!=NULL)
	{
		if(estadoVuelo <= 4 && estadoVuelo >= 1)
		{
			this->estadoVuelo = estadoVuelo;
			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_getId(Passenger* this, int* id)
{
	int rtn = -1;

	if(this != NULL)
	{
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
    int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
	int rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int rtn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int rtn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int rtn = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getTipoPasajeroStr(int tipoPasajero , char* tipoStr)
{
	int rtn = -1;

	if(tipoPasajero <= 3 &&  tipoPasajero >= 1 && tipoStr != NULL)
	{
		switch(tipoPasajero)
		{
			case 1:
				strcpy(tipoStr, "EconomyClass");
			break;

			case 2:
				strcpy(tipoStr, "ExecutiveClass");
			break;

			case 3:
				strcpy(tipoStr, "FirstClass");
			break;
		}
		rtn = 1;
	}

	return rtn;
}

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int rtn = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		rtn = 1;
	}
	return rtn;
}

int Passenger_getEstadoVueloStr(int estadoVuelo , char* estadoStr)
{
	int rtn = -1;

	if(estadoVuelo <= 4 &&  estadoVuelo >= 1 && estadoStr != NULL)
	{
		switch(estadoVuelo)
		{
			case 1:
				strcpy(estadoStr, "En Horario");
			break;

			case 2:
				strcpy(estadoStr, "En Vuelo");
			break;

			case 3:
				strcpy(estadoStr, "Demorado");
			break;

			case 4:
			strcpy(estadoStr, "Aterrizado");
			break;
		}
		rtn = 1;
	}

	return rtn;
}

void Passenger_imprimir(Passenger* pasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[10];
	int tipoPasajero;
	char descpTipoPasajero[30];
	int estadoVuelo;
	char descripEstadoVuelo[30];

	Passenger_getId(pasajero, &id);
	Passenger_getNombre(pasajero, nombre);
	Passenger_getApellido(pasajero, apellido);
	Passenger_getPrecio(pasajero, &precio);
	Passenger_getCodigoVuelo(pasajero, codigoDeVuelo);
	Passenger_getTipoPasajero(pasajero, &tipoPasajero);
	Passenger_getTipoPasajeroStr(tipoPasajero, descpTipoPasajero);
	Passenger_getEstadoVuelo(pasajero, &estadoVuelo);
	Passenger_getEstadoVueloStr(estadoVuelo, descripEstadoVuelo);

	printf("|%-4d|%-20s|%-20s|%-10.2f|%-14s|%-20s|%-20s|\n",id,nombre,apellido,precio,codigoDeVuelo,descpTipoPasajero, descripEstadoVuelo);
}

int Passenger_funcionCriterio(void* item1, void* item2)
{
	int rtn = -1;
	int primerId;
	int segundoId;
	Passenger* pPassengerUno;
	Passenger* pPassengerDos;

	if(item1 != NULL && item2 != NULL)
	{
		pPassengerUno = (Passenger*) item1;
		pPassengerDos = (Passenger*) item2;

		if(Passenger_getId(pPassengerUno, &primerId) == 1 &&
		   Passenger_getId(pPassengerDos, &segundoId) == 1)
		{
			if(primerId > segundoId)
			{
				rtn = 1;
			}
			else
			{
				if(primerId < segundoId)
				{
					rtn = 2;
				}
			}
		}
	}

	return rtn;
}

int Passenger_actualizarUltimoId(int idAnterior)
{
	int rtn = -1;

	FILE* pFile = fopen("ultimoId.txt", "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d\n", idAnterior+1);
		rtn = 1;
	}
	fclose(pFile);

	return rtn;
}
