#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#define MAX_TAM 2000

int main(void)
{
	setbuf(stdout,NULL);

	int opcionMenu;
	int opcionInforme;
	int flagAlta = 0;
	sPassengers arrayPasajeros[MAX_TAM];
	sPass_initPassenger(arrayPasajeros, MAX_TAM);

	do
	{
		puts("\n\t\t\t\t MENU DE OPCIONES");
		puts("\t\t\t\t ---------------- \n");
		puts("1. ALTA DE UN PASAJERO \n");
		puts("2. MODIFICAR UN PASAJERO \n");
		puts("3. BAJA DE UN PASAJERO \n");
		puts("4. INFORMAR: \n"
			 "    1. LISTADO DE PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO \n"
			 "    2. TOTAL Y PROMEDIO DE PRECIO DE LOS PASAJES, Y CANTIDAD DE PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO \n"
			 "    3. LISTADO DE PASAJEROS POR C�DIGO DE VUELO Y ESTADOS DE VUELO ACTIVO \n");
		puts("5. SALIR \n");

		utn_getNumero("INGRESE OPCION: ", "ERROR. ", 1, 5, 1, &opcionMenu);

		switch(opcionMenu)
		{
			case 1:
				if(sPass_addPassengers(arrayPasajeros, MAX_TAM) == 1)
				{
					flagAlta = 1;
					puts("\nALTA EXITOSA.");
				}
				else
				{
					puts("\nNO SE HA PODIDO DAR DE ALTA");
				}
			break;

			case 2:
				if(flagAlta == 1)
				{
					sPass_modifyData(arrayPasajeros, MAX_TAM);
				}
				else
				{
					puts("\nNO SE HA DADO DE ALTA NINGUN PASAJERO PARA PODER MODIFICAR");
				}
			break;

			case 3:
				if(flagAlta == 1)
				{
				 sPass_removePassengers(arrayPasajeros, MAX_TAM);
				}
				else
				{
					puts("\nNO SE HA DADO DE ALTA NINGUN PASAJERO PARA PODER DAR DE BAJA");
				}
				break;

			case 4:
				if(flagAlta == 1)
				{
					utn_getNumero("\nINGRESE OPCION PARA INFORMAR: ", "\nERROR. ", 1, 3, 2, &opcionInforme);
					switch(opcionInforme)
					{
						case 1:
							sPass_printPassengers(arrayPasajeros, MAX_TAM, 1);
						break;

						case 2:
							sPass_printAverage(arrayPasajeros, MAX_TAM);
						break;

						case 3:
							sPass_printPassengers(arrayPasajeros, MAX_TAM, 2);
						break;
					}
				}
				else
				{
					puts("\nNO SE HA DADO DE ALTA NINGUN PASAJERO PARA PODER MOSTRAR");
				}
			break;

			case 5:
				puts("\nSALIENDO DEL PROGRAMA...");
			break;

		}//FIN SWITCH

	}while(opcionMenu != 5);

	return EXIT_SUCCESS;

} //FIN MAIN


