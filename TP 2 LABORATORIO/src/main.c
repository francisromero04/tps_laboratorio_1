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
	int flagAltaForzada = 0;
	sPassengers arrayPasajeros[MAX_TAM];
	sPass_initPassenger(arrayPasajeros, MAX_TAM);

	do
	{
		puts("\n\n\t\t\t\t MENU DE OPCIONES");
		puts("\t\t\t\t ---------------- \n");
		puts("1. ALTA DE UN PASAJERO.");
		puts("2. MODIFICAR UN PASAJERO.");
		puts("3. BAJA DE UN PASAJERO.");
		puts("4. INFORMAR: \n"
			 "    1. LISTADO DE PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO \n"
			 "    2. EL TOTAL DE LOS PASAJES CON SU PROMEDIO Y PASAJEROS QUE LO SUPERAN \n"
			 "    3. LISTADO DE PASAJEROS POR CODIGO DE VUELO Y ESTADOS DE VUELO ACTIVO");
		puts("5. CARGA FORZADA DE PASAJEROS.");
		puts("6. SALIR DEL PROGRAMA. \n");

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
				if(flagAlta == 1 || flagAltaForzada == 1)
				{
					puts("\n+-------------------------------------------------------------------+");
					puts("| ID |    APELLIDO   |     NOMBRE     |   PRECIO   |      TIPO      |");
					puts("+-------------------------------------------------------------------+");
					sPass_modifyData(arrayPasajeros, MAX_TAM);
				}
				else
				{
					puts("\nNO SE HA DADO DE ALTA NINGUN PASAJERO PARA PODER MODIFICAR");
				}
			break;

			case 3:
				if(flagAlta == 1 || flagAltaForzada == 1)
				{
					puts("\n+-------------------------------------------------------------------+");
					puts("| ID |    APELLIDO   |     NOMBRE     |   PRECIO   |      TIPO      |");
					puts("+-------------------------------------------------------------------+");
					sPass_removePassengers(arrayPasajeros, MAX_TAM);
				}
				else
				{
					puts("\nNO SE HA DADO DE ALTA NINGUN PASAJERO PARA PODER DAR DE BAJA");
				}
				break;

			case 4:
				if(flagAlta == 1 || flagAltaForzada == 1)
				{
					utn_getNumero("INGRESE OPCION PARA INFORMAR: ", "ERROR. ", 1, 3, 2, &opcionInforme);
					switch(opcionInforme)
					{
						case 1:
							puts("\n+-------------------------------------------------------------------+");
							puts("| ID |    APELLIDO   |     NOMBRE     |   PRECIO   |      TIPO      |");
							puts("+-------------------------------------------------------------------+");
							sPass_printPassengers(arrayPasajeros, MAX_TAM, 1);
							puts("+-------------------------------------------------------------------+");
						break;

						case 2:
							sPass_printAverage(arrayPasajeros, MAX_TAM);
						break;

						case 3:
							puts("\n+------------------------------------------------------------------------------------+");
							puts("| ID |    APELLIDO   |     NOMBRE     |   PRECIO   |  CODIGO VUELO  |     ESTADO     |");
							puts("+------------------------------------------------------------------------------------+");
							sPass_printPassengers(arrayPasajeros, MAX_TAM, 2);
							puts("+------------------------------------------------------------------------------------+");
						break;
					}
				}
				else
				{
					puts("\nNO SE HA DADO DE ALTA NINGUN PASAJERO PARA PODER MOSTRAR");
				}
			break;

			case 5:
				if(sPass_CargaForzada(arrayPasajeros) == 1)
				{
					flagAltaForzada = 1;
					puts("\nCARGA FORZADA CON EXITO! YA PUEDE OPERAR CON DICHOS PASAJEROS.");
				}
			break;

			case 6:
				puts("\nSALIENDO DEL PROGRAMA...");
			break;

		}//FIN SWITCH

	}while(opcionMenu != 6);

	return EXIT_SUCCESS;

} //FIN MAIN


