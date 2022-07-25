#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

int main()
{
    setbuf(stdout, NULL);
    int option;
    LinkedList* listaPasajeros = ll_newLinkedList();
    int flagCargarTexto = 0;
    int flagCargarBin = 0;

    do{
    	puts("\n\t\t\tMENU DE OPCIONES:\n"
    		"\t\t\t-----------------\n\n"
    		"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n"
    		"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n"
    		"3. Alta de pasajero \n"
    		"4. Modificar datos de pasajero \n"
    		"5. Baja de pasajero \n"
    		"6. Listar pasajeros \n"
    		"7. Ordenar pasajeros \n"
    		"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n"
    		"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n"
    		"10. Salir \n");

    	utn_getNumero("INGRESE OPCION: ", "ERROR \n", 1, 10, 2, &option);

        switch(option)
        {
            case 1:
            	if(flagCargarTexto == 0)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
					flagCargarTexto = 1;
            	}
            	else
            	{
            		puts("\nERROR, YA SE HA CARGADO LA LISTA (TXT).\n");
            	}
            break;

            case 2:
            	if(flagCargarBin == 0)
            	{
					controller_loadFromBinary("data.bin", listaPasajeros);
					flagCargarBin = 1;
            	}
            	else
            	{
            		puts("\nERROR, YA SE HA CARGADO LA LISTA (BIN).\n");
            	}
            break;

            case 3:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
					controller_addPassenger(listaPasajeros);
				}
				else
				{
					puts("\nANTES DE AÑADIR PRIMERO CARGUE LOS DATOS DEL ARCHIVO.\n");
				}
            break;

            case 4:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
            	{
					controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		puts("\nANTES DE MODIFICAR PRIMERO CARGUE LOS DATOS DEL ARCHIVO.\n");
            	}
			break;

            case 5:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
    				controller_removePassenger(listaPasajeros);
				}
				else
				{
					puts("\nANTES DE ELIMINAR PRIMERO CARGUE LOS DATOS DEL ARCHIVO.\n");
				}
			break;

            case 6:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					puts("\nANTES DE LISTAR PRIMERO CARGUE LOS DATOS DEL ARCHIVO.\n");
				}
			break;

            case 7:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
                	controller_sortPassenger(listaPasajeros);
				}
				else
				{
					puts("\nANTES DE ORDENAR PRIMERO CARGUE LOS DATOS DEL ARCHIVO.\n");
				}
            break;

            case 8:
            	if(flagCargarTexto == 1)
            	{
					controller_saveAsText("data.csv", listaPasajeros);
            	}
            	else
            	{
					puts("\nANTES DE GUARDAR PRIMERO CARGUE LOS DATOS DEL ARCHIVO (TXT) .\n");
            	}
           	break;

            case 9:
            	if(flagCargarBin == 1)
				{
					controller_saveAsBinary("data.bin", listaPasajeros);
				}
				else
				{
					puts("\nANTES DE GUARDAR PRIMERO CARGUE LOS DATOS DEL ARCHIVO (BIN) .\n");
				}
            break;

            case 10:
            	puts("\nPROGRAMA CERRADO.");
            break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}
