#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile = fopen(path, "r");

	if(pArrayListPassenger != NULL && path != NULL)
	{
		printf("\nSE HAN CARGADO LOS DATOS DEL ARCHIVO CSV...\n");
		parser_PassengerFromText(pFile, pArrayListPassenger);
		rtn = 1;
	}
	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		printf("\nSE HAN CARGADO LOS DATOS DEL ARCHIVO BIN...\n");
		FILE* pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			parser_PassengerFromBinary(pFile , pArrayListPassenger);
			rtn = 1;
		}
	}
	return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int auxId;
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[TAM_CODIGO];
	char auxNombre[TAM_CADENA];
	char auxApellido[TAM_CADENA];
	int auxEstadoVuelo;
	Passenger* unPasajero = NULL;

	if(pArrayListPassenger != NULL)
	{
		auxId = controller_getUltimoId();

		if( utn_getString("\nINGRESE SU NOMBRE: ", "\nERROR. \n", 2, TAM_CADENA, auxNombre) == 0 &&
			utn_getString("\nINGRESE SU APELLIDO: ", "\nERROR. \n", 2, TAM_CADENA, auxApellido) == 0 &&
			utn_getString("\nINGRESE CODIGO DE VUELO: ", "\nERROR. \n", 2, TAM_CODIGO, auxCodigoVuelo) == 0 &&
			utn_getNumFloat("\nINGRESE PRECIO: ", "\nERROR. \n", 1, 999999, 2, &auxPrecio) == 0 &&
			utn_getNumero("\nINGRESE TIPO O CLASE DE PASAJERO (1. ECONOMICA | 2. EJECUTIVA | 3. PRIMERA CLASE): ", "\nERROR. \n", 1, 3, 2, &auxTipoPasajero) == 0 &&
			utn_getNumero("\nINGRESE ESTADO VUELO (1. EN HORARIO | 2. EN VUELO | 3. DEMORADO | 4. ATERRIZADO): ", "\nERROR. \n", 1, 4, 2, &auxEstadoVuelo) == 0)
		{
			unPasajero = Passenger_newParametrosAlta(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
			if(unPasajero != NULL)
			{
				ll_add(pArrayListPassenger, unPasajero);
				Passenger_actualizarUltimoId(auxId);
				rtn = 1;
			}
		}
	}

    return rtn;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int i;
	int rtn = -1;
	float precio;
	int idAbuscar;
	int opcionMenu;
	int tipoPasajero;
	int estadoVuelo;
	char codigoVuelo[TAM_CODIGO];
	char nombre[TAM_CADENA];
	char apellido[TAM_CADENA];
	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		if(utn_getNumero("\nINGRESE EL ID DEL PASAJERO A MOFIDIFICAR: ", "\nERROR.", 0, 10000, 2, &idAbuscar) == 0)
		{

			for(i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

				if(idAbuscar == pPassenger->id)
				{
					puts("\n\t\t\t\t\tPASAJERO A MODIFICAR");
					puts("+------------------------------------------------------------------------------------------------------------------+");
					puts("| ID |       NOMBRE       |      APELLIDO      |  PRECIO  | CODIGO VUELO |  TIPO DE PASAJERO  |   ESTADO DE VUELO  |");
					puts("+------------------------------------------------------------------------------------------------------------------+");

					ll_get(pArrayListPassenger, i);
					Passenger_imprimir(pPassenger);

					puts("+------------------------------------------------------------------------------------------------------------------+");

					if(utn_getNumero("\nCAMPOS A MODIFICAR: \n"
									"1. NOMBRE \n2. APELLIDO \n"
									"3. PRECIO \n4. CODIGO DE VUELO \n"
									"5. TIPO O CLASE \n6. ESTADO DE VUELO \n"
									"7. SALIR \n"
									"\nINGRESE OPCION: ", "\nERROR.", 1, 7, 2, &opcionMenu) == 0)
					{
						switch(opcionMenu)
						{
							case 1:
								if(utn_getString("\nINGRESE NUEVO NOMBRE: ", "\nERROR.", 2, TAM_CADENA, nombre) == 0)
								{
									if(Passenger_setNombre(pPassenger, nombre) == 1)
									{
										puts("\nNOMBRE MODIFICADO.");
									}
								}
							break;

							case 2:
								if(utn_getString("\nINGRESE NUEVO APELLIDO: ", "\nERROR.", 2, TAM_CADENA, apellido) == 0)
								{
									if(Passenger_setApellido(pPassenger, apellido) == 1)
									{
										puts("\nAPELLIDO MODIFICADO.");
									}
								}
							break;

							case 3:
								if(utn_getNumFloat("\nINGRESE NUEVO PRECIO: ", "\nERROR.", 1, 9999999, 2, &precio) == 0)
								{
									if(Passenger_setPrecio(pPassenger, precio) == 1)
									{
										puts("\nPRECIO MODIFICADO.");
									}
								}
							break;

							case 4:
								if(utn_getString("\nINGRESE NUEVO CODIGO DE VUELO: ", "\nERROR.", 2, TAM_CODIGO, codigoVuelo) == 0)
								{
									if(Passenger_setCodigoVuelo(pPassenger, codigoVuelo) == 1)
									{
										puts("\nCODIGO DE VUELO MODIFICADO.");
									}
								}
							break;

							case 5:
								if(utn_getNumero("\nINGRESE NUEVO TIPO O CLASE DE PASAJERO (1. ECONOMICA | 2. EJECUTIVA | 3. PRIMERA CLASE): ",
										  "\nERROR.", 1, 3, 2, &tipoPasajero) == 0)
								{
									if(Passenger_setTipoPasajero(pPassenger, tipoPasajero) == 1)
									{
										puts("\nTIPO DE PASAJERO MODIFICADO.");
									}
								}
							break;

							case 6:
								if(utn_getNumero("\nINGRESE ESTADO VUELO (1. EN HORARIO | 2. EN VUELO | 3. DEMORADO | 4. ATERRIZADO): ",
										"\nERROR.", 1, 4, 2, &estadoVuelo) == 0)
								{
									if(Passenger_setEstadoVuelo(pPassenger, estadoVuelo) == 1)
									{
										puts("\nESTADO DE VUELO MODIFICADO.");
									}
								}
							break;
						}
					}
				}
			}
		}
		rtn = 1;
	}

    return rtn;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int i;
	int idAbuscar;
	int opcionBaja;
	int indexABorrar;
	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		if(utn_getNumero("\nINGRESE EL ID DEL PASAJERO A DAR DE BAJA: ", "\nERROR.", 0, 10000, 2, &idAbuscar) == 0)
		{
			for(i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

				if(idAbuscar == pPassenger->id)
				{
					puts("\n\t\t\t\t\tPASAJERO A DAR DE BAJA");
					puts("+------------------------------------------------------------------------------------------------------------------+");
					puts("| ID |       NOMBRE       |      APELLIDO      |  PRECIO  | CODIGO VUELO |  TIPO DE PASAJERO  |   ESTADO DE VUELO  |");
					puts("+------------------------------------------------------------------------------------------------------------------+");

					ll_get(pArrayListPassenger, i);
					Passenger_imprimir(pPassenger);

					puts("+------------------------------------------------------------------------------------------------------------------+");

					utn_getNumero("\nESTA SEGURO QUE QUIERE DAR DE BAJA ESTE PASAJERO? (1-SI | 2-NO): ", "\nERROR.", 1, 2, 2, &opcionBaja);

					indexABorrar = ll_indexOf(pArrayListPassenger, pPassenger);

					if(opcionBaja == 1)
					{
						ll_remove(pArrayListPassenger, indexABorrar);
						rtn = 1;
					}
				}
			}
		}
	}
	else
	{
		rtn = 0;
	}

    return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	if(pArrayListPassenger!=NULL)
	{
		int lenList = ll_len(pArrayListPassenger);

		puts("\n\t\t\t\t\tLISTADO DE PASAJEROS");
		puts("+------------------------------------------------------------------------------------------------------------------+");
		puts("| ID |       NOMBRE       |      APELLIDO      |  PRECIO  | CODIGO VUELO |  TIPO DE PASAJERO  |   ESTADO DE VUELO  |");
		puts("+------------------------------------------------------------------------------------------------------------------+");

		for(int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			Passenger_imprimir(pPassenger);
		}

		puts("+------------------------------------------------------------------------------------------------------------------+");
		rtn = 1;
	}
	return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	if(pArrayListPassenger != NULL)
	{
		rtn = 1;
		ll_sort(pArrayListPassenger, Passenger_funcionCriterio, 1);
	}
	else
	{
		rtn = 0;
	}

    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[10];
	int tipoPasajero;
	int estadoVuelo;

	Passenger* pasajero = NULL;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "w");

		pasajero=Passenger_new();

		if(pasajero != NULL)
		{
			fprintf(pFile, "id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				if(pasajero != NULL)
				{
					Passenger_getId(pasajero, &id);
					Passenger_getNombre(pasajero, nombre);
					Passenger_getApellido(pasajero, apellido);
					Passenger_getPrecio(pasajero, &precio);
					Passenger_getCodigoVuelo(pasajero, codigoDeVuelo);
					Passenger_getTipoPasajero(pasajero, &tipoPasajero);
					Passenger_getEstadoVuelo(pasajero, &estadoVuelo);

					fprintf(pFile,"%d,%s,%s,%.2f,%s,%d,%d\n", id, nombre, apellido, precio, codigoDeVuelo, tipoPasajero, estadoVuelo);
					rtn = 1;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
		}
		fclose(pFile);

		if(rtn)
		{
			printf("\nLA LISTA SE GUARDO CON EXITO (TXT)\n");
		}
	}

	return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int tamArray;
	Passenger* auxPassenger;

	tamArray = ll_len(pArrayListPassenger);

	FILE* pFile;
	pFile = fopen(path, "wb");

	if(pFile != NULL && path != NULL)
	{
		for (int i = 0; i < tamArray; i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
		}
		printf("\nLA LISTA SE GUARDO CON EXITO (BIN)\n");
		rtn = 1;
	}
	fclose(pFile);
	return rtn;
}

int controller_getUltimoId()
{
	int ultimoId = 1;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", ultimoIdStr);

		ultimoId = atoi(ultimoIdStr);
	}
	else
	{
	    pFile = fopen("ultimoId.txt", "w");
	    fprintf(pFile, "%d\n", ultimoId);
	}
	fclose(pFile);

	return ultimoId;
}
