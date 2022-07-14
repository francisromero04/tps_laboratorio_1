#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	Passenger* auxPassenger;
	int contadorIdIncialLista=controller_getUltimoId();
	char buffer[7][50];
	int aux;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
			if(aux == 7)
			{
				auxPassenger = Passenger_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

				if(auxPassenger != NULL)
				{

					auxPassenger->id=contadorIdIncialLista;
					contadorIdIncialLista++;
					aux = ll_add(pArrayListPassenger, auxPassenger);


					if(aux != 0)
					{
						Passenger_delete(auxPassenger);
						break;
					}
					else
					{
						rtn = 1;
					}
				}
			}
			else
			{
				break;
			}
		}
		Passenger_actualizarUltimoId(contadorIdIncialLista-1);
	}
	return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int lectura;
	int contadorId = controller_getUltimoId();

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		Passenger* pPass = Passenger_new();

		do
		{
			lectura = fread(pPass, sizeof(Passenger), 1, pFile);

			if(lectura)
			{
				pPass->id = contadorId;
				contadorId++;
				ll_add(pArrayListPassenger, pPass);
				pPass = Passenger_new();
				rtn = 1;
			}
		}while(!feof(pFile));

		Passenger_actualizarUltimoId(contadorId);
		free(pPass);
		fclose(pFile);
	}

	return rtn;
}
