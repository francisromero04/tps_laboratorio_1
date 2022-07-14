#include "abm.h"

//-----------------------------------------------------UTILES EN ABM---------------------------------------------------

/// @fn int sPass__getID(void)
/// @brief Con la variable passenger_idIncremental incrementa un ID desde 1000 en adelante
/// @return Retorna el ID que incremento
static int sPass__getID(void);
static int sPass__getID(void)
{
	///INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION sPass_getID();
	static int passenger_idIncremental = 1000;
	static int rtn;

	rtn = passenger_idIncremental++;

	return rtn;
}

/// @fn void sPass_initPassenger(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassengers y su tamaño, para asi darle un indice LIBRE
/// @param array
/// @param TAM
void sPass_initPassenger(sPassengers array[], int TAM)
{
	int i;

	///SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0)
	{
		///RECORRE EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			///SETEA ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

/// @fn int sPass_getFreeIndex(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassengers y su tama�o, luego busca un espacio LIBRE en el indice,
///  para despu�s guardar datos en ese espacio
/// @param array
/// @param TAM
/// @return Retorna el espacio LIBRE que encontro en el indice
int sPass_getFreeIndex(sPassengers array[], int TAM)
{
	int rtn = -1;
	int i;

	///SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0)
	{
		//RECORRO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			///PREGUNTA POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE)
			{
				///OBTIENE EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/// @fn int sPass_findPassengerByID(sPassengers[], int, int)
/// @brief Recibe el array cuyo tipo de dato es sPassengers, su tama�o y el ID a buscar en el indice
/// @param array
/// @param TAM
/// @param ID
/// @return Retorna el indice en dondese ubica el ID encontrado
int sPass_findPassengerByID(sPassengers array[], int TAM, int ID)
{
	int rtn = -1;
	int i;

	///SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0)
	{
		///RECORRE EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			///BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == OCUPADO)
			{
				///SI ENCONTRO EL ID
				///DEVUELVE EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/// @fn sPassengers sPass_enterData(void)
/// @brief Pide los datos a cargar en un auxiliar cuyo tipo de dato es sPassengers,
/// para luego poder darde ALTA un pasajero en sPass_addPassengers
/// @return Retorna ese auxiliar con los datos cargados
sPassengers sPass_enterData(void)
{
	sPassengers auxiliar;
	int opcionTipoPasajero;
	int opcionEstadoVuelo;

	utn_getString("\nINGRESE NOMBRE: ", "ERROR \n", 2, TAM_CHAR, auxiliar.name);
	utn_getString("INGRESE APELLIDO: ", "ERROR \n", 2, TAM_CHAR, auxiliar.lastname);
	utn_getAlfaNum("INGRESE EL CODIGO DE VUELO ALFANUMERICO (no mas de 10 caracteres): ",
			"ERROR, REINGRESE CODIGO ALFANUMERICO: ", 2, 11, auxiliar.flycode);

	utn_getNumero("INGRESE TIPO DE PASAJERO (TIPO 1: TURISTA | TIPO 2: EJECUTIVO | TIPO 3: PREMIUM): ",
				"ERROR \n", 1, 3, 2, &opcionTipoPasajero);
	switch(opcionTipoPasajero)
	{
		case 1:
			auxiliar.typePassenger = TURISTA;
		break;

		case 2:
			auxiliar.typePassenger = EJECUTIVO;
		break;

		case 3:
			auxiliar.typePassenger = PREMIUM;
		break;
	}

	utn_getNumero("INGRESE ESTADO DE VUELO (OPCION 1: ACTIVO | OPCION 2: CANCELADO): ",
			"ERROR \n", 0, 2, 2, &opcionEstadoVuelo);
	switch(opcionEstadoVuelo)
	{
		case 1:
			auxiliar.statusFlight = ACTIVO;
		break;

		case 2:
			auxiliar.statusFlight = CANCELADO;
		break;
	}

	utn_getNumFloat("INGRESE PRECIO: ", "ERROR \n", 0, 999999, 2, &auxiliar.price);

	return auxiliar;
}

/// @fn void sPass_printAverage(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassenger y su tama�o,
///  su funcionalidad es unicamente mostrar el precio total acumulado
/// entre todos los vuelos, calcula su promedio y cuenta cuantos
///  pasajeros superan ese promedio
/// @param array
/// @param TAM
void sPass_printAverage(sPassengers array[], int TAM)
{
	int i = 0;
	float promedioPrecio;
	int contadorPasajeros = 0;
	float acumuladorPrecio = 0;
	int contadorPasajerosMayorPrecio = 0;

	if(array != NULL && TAM > 0) ///PREGUNTA SI EL ARRAY EL TAM FUERON PASADOS CORRECTAMENTE
	{
		for(i = 0; i < TAM; i++) ///RECORRO EL ARRAY
		{
			if(array[i].isEmpty == OCUPADO) ///PREGUNTA SI EL ARRAY EN LA POSICION I ESTA OCUPADO
			{
				acumuladorPrecio += array[i].price;
				contadorPasajeros++;
				promedioPrecio = acumuladorPrecio/contadorPasajeros;

				if(array[i].price > promedioPrecio)
				{
					contadorPasajerosMayorPrecio++;
				}
			}
		}
		printf("\nPRECIO TOTAL RECAUDADO: %.2f",acumuladorPrecio);
		printf("\nPROMEDIO PRECIO: %.2f",promedioPrecio);
		printf("\nCANTIDAD DE PASAJEROS SUPERANDO EL PROMEDIO: %d",contadorPasajerosMayorPrecio);
	}
}

/// @fn sPassengers sPass_modifyOne(sPassengers)
/// @brief Recibe un tipo de dato sPassengers, muestra un men� con opciones para
/// que el usuario selecione cual dato quiere modificar y los carga en un
/// auxiliar para luego igualarlo al tipo de dato que recibi�
/// @param Pasajero
/// @return Retorna
sPassengers sPass_modifyOne(sPassengers Pasajero)
{
	sPassengers auxiliar;
	int opcionMenuModificar;
	int opcionEstadoVuelo;
	int opcionTipoPasajero;

	do
	{
		puts("\nCAMPOS A MODIFICAR: \n");
		puts("1. NOMBRE");
		puts("2. APELLIDO");
		puts("3. CODIGO DE VUELO");
		puts("4. TIPO DE PASAJERO");
		puts("5. ESTADO DE VUELO");
		puts("6. PRECIO");
		puts("7. SALIR");

		utn_getNumero("\nINGRESE LA OPCION DEL CAMPO A MODIFICAR: ", "ERROR. \n", 1, 7, 1, &opcionMenuModificar);

		switch(opcionMenuModificar)
		{
			case 1:
				if(utn_getString("\nINGRESE EL NUEVO NOMBRE: ", "ERROR \n", 2, TAM_CHAR, auxiliar.name) == 0)
				{
					puts("\nEL NOMBRE SE HA MODIFICADO.");
				}
			break;

			case 2:
				if(utn_getString("\nINGRESE EL NUEVO APELLIDO: ", "ERROR \n", 2, TAM_CHAR, auxiliar.lastname) == 0)
				{
					puts("\nEL APELLIDO SE HA MODIFICADO.");
				}
			break;

			case 3:
				if(utn_getAlfaNum("INGRESE EL NUEVO CODIGO DE VUELO ALFANUMERICO (no mas de 10 caracteres): ",
						"\nERROR, REINGRESE CODIGO ALFANUMERICO: ", 2, 11, auxiliar.flycode) == 0)
				{
					puts("\nEL CODIGO DE VUELO SE HA MODIFICADO.");
				}
			break;

			case 4:
				utn_getNumero("INGRESE NUEVO TIPO DE PASAJERO (TIPO 1: TURISTA | TIPO 2: EJECUTIVO | TIPO 3: PREMIUM): ",
								"ERROR \n", 1, 3, 2, &opcionTipoPasajero);
				switch(opcionTipoPasajero)
				{
					case 1:
						auxiliar.typePassenger = TURISTA;
						puts("\nEL TIPO DE PASAJERO SE HA MODIFICADO.");
					break;

					case 2:
						auxiliar.typePassenger = EJECUTIVO;
						puts("\nEL TIPO DE PASAJERO SE HA MODIFICADO.");
					break;

					case 3:
						auxiliar.typePassenger = PREMIUM;
						puts("\nEL TIPO DE PASAJERO SE HA MODIFICADO.");
					break;
				}
			break;

			case 5:
				utn_getNumero("INGRESE EL NUEVO ESTADO DE VUELO (OPCION 1: ACTIVO | OPCION 2: INACTIVO): ",
											"ERROR \n", 0, 10, 2, &opcionEstadoVuelo);
				switch(opcionEstadoVuelo)
				{
					case 1:
						auxiliar.statusFlight = ACTIVO;
						puts("\nEL ESTADO DEL PASAJERO SE HA MODIFICADO.");
					break;

					case 2:
						auxiliar.statusFlight = CANCELADO;
						puts("\nEL ESTADO DEL PASAJERO SE HA MODIFICADO.");
					break;
				}
			break;

			case 6:
				if(utn_getNumFloat("INGRESE EL NUEVO PRECIO: ", "ERROR \n", 0, 999999, 2, &auxiliar.price) == 0)
				{
					puts("\nEL PRECIO SE HA MODIFICADO.");
				}
			break;

			case 7:
				puts("\nVOLVIENDO AL MENU PRINCIPAL...");
			break;
		}
	}while(opcionMenuModificar != 7);

	auxiliar = Pasajero;

	return auxiliar;
}

/// @fn void sPass_printOne(sPassengers, int)
/// @brief Recibe un tipo de dato sPassenger y un criterio a mostrar. Seg�n el criterio,
/// muestra
/// @param Pasajero
/// @param criterio
void sPass_printOne(sPassengers Pasajero, int criterio)
{
	char estadoVuelo[TAM_CHAR];
	char tipoPasajero[TAM_CHAR];

	switch(criterio)
	{

		case 1:
			//CABECERA
			puts("\n+-------------------------------------------------------+");
			puts("|     APELLIDO   |     NOMBRE     | ID |       TIPO     |");
			puts("+-------------------------------------------------------+");

			printf("|%-16s|%-16s|%4d|", Pasajero.lastname, Pasajero.name, Pasajero.id);

			switch(Pasajero.typePassenger)
			{
				case TURISTA:
					strncpy(tipoPasajero, "TURISTA", sizeof(tipoPasajero));
					printf("%-16s|\n", tipoPasajero);
				break;

				case EJECUTIVO:
					strncpy(tipoPasajero, "EJECUTIVO", sizeof(tipoPasajero));
					printf("%-16s|\n", tipoPasajero);
				break;

				case PREMIUM:
					strncpy(tipoPasajero, "PREMIUM", sizeof(tipoPasajero));
					printf("%-16s|\n", tipoPasajero);
				break;
			}
		break;

		case 2:
			if(Pasajero.statusFlight == ACTIVO)
			{
				puts("\n+------------------------------------------------------------------------+");
				puts("|     APELLIDO   |     NOMBRE     | ID |  CODIGO VUELO  |     ESTADO     |");
				puts("+------------------------------------------------------------------------+");

				printf("|%-16s|%-16s|%4d|%-16s|", Pasajero.lastname, Pasajero.name, Pasajero.id, Pasajero.flycode);
				strncpy(estadoVuelo, "ACTIVO", sizeof(estadoVuelo));
				printf("%-16s|\n", estadoVuelo);
			}
			else
			{
				puts("\naNO SE CARGO NINGUN PASAJERO ACTIVO.");
			}
		break;
	}
}

///  @fn int sPass_printPassengers(sPassengers[], int, int)
/// @brief Recibe el array cuyo tipo de dato es sPassenger, su tama�o y el criterio el cual mostrar.
///	Luego ordena y muestra seg�n el criterio elegido.
/// @param Pasajeros
/// @param TAM
/// @param criterio
/// @return Retorna 1 si salio como se esperaba o -1 si hubo un error
int sPass_printPassengers(sPassengers Pasajeros[], int TAM, int criterio)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	///SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Pasajeros != NULL && TAM > 0)
	{
		///RECORRO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			///PREGUNTO POR SU ESTADO "OCUPADO"
			if (Pasajeros[i].isEmpty == OCUPADO)
			{
				switch(criterio)
				{
					case 1:
						///ORDENO POR APELLIDO ALFABETICAMENTE
						sPass_sortPassengers(Pasajeros, TAM, 1);
						///IMPRIMO UN SOLO PASAJERO
						sPass_printOne(Pasajeros[i],1);
						///CONTADOR DE PASAJEROS
						cantidad++;
					break;

					case 2:
						///ORDENO POR CODIGO DE VUELO ASCENDENTE Y MUESTRO ESTADO
						sPass_sortPassengers(Pasajeros, TAM, 2);
						///IMPRIMO UN SOLO PASAJERO
						sPass_printOne(Pasajeros[i],2);
						///CONTADOR DE PASAJEROS
						cantidad++;
					break;
				}
			}
		}
	}

	///SI CANTIDAD == 0 - NO HUBO PASAJEROS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

/// @fn int sPass_sortPassengers(sPassengers[], int, int)
/// @brief Recibe el array cuyo tipo de dato es sPassenger, su tama�o y el criterio por
/// el cual ordenar.
/// @param array
/// @param TAM
/// @param criterio
/// @return Retorna 1 si pudo ordenar el array y -1 si hubo algun error
int sPass_sortPassengers(sPassengers array[], int TAM, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	sPassengers aux;

	/** EJEMPLO DE SORT CON ID DE sPassengers
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE 1 -> ORDENA DE MENOR A MAYOR (ASCENDENTE) AL APELLIDO
	    CASE  2 -> ORDENA DE MENOR A MAYOR (ASCENDENTE) AL FLYCODE
	*/

	///SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0)
	{
		switch (criterio)
		{
			case 1:
				for (i = 0; i < TAM - 1; i++)
				{
					for (j = i + 1; j < TAM; j++)
					{
						///PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if (array[i].isEmpty == OCUPADO
								&& array[j].isEmpty == OCUPADO)
						{
							///CRITERIO DE ORDENAMIENTO
							if (strncmp(array[i].lastname, array[j].lastname, TAM_CHAR) > 0)
							{
								///INTERCAMBIO POSICIONES EN ARRAY
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}
					}
				}
				rtn = 1;
			break;

			case 2:
				for (i = 0; i < TAM - 1; i++)
				{
					for (j = i + 1; j < TAM; j++)
					{
						///PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if (array[i].isEmpty == OCUPADO
								&& array[j].isEmpty == OCUPADO)
						{
							///CRITERIO DE ORDENAMIENTO
							if (strncmp(array[i].flycode, array[j].flycode, TAM_CHAR) > 0)
							{
								///INTERCAMBIO POSICIONES EN ARRAY
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}
					}
				}
				rtn = 1;
			break;

			default:
				///CRITERIO DE ORDENAMIENTO MAL INGRESADO
				rtn = 0;
			break;
		}
	}
	return rtn;
}

//-----------------------------------------------------ABM--------------------------------------------------------------

/// @fn int sPass_addPassengers(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassenger y su tama�o, luego busca un indice LIBRE en el array para
/// poder dar de alta. Pide los datos del pasajero y le da un ID �nico a cada uno cambiandole su estado a OCUPADO
/// @param array
/// @param TAM
/// @return Retorna 1 si se pudo dar de alta o -1 si hubo algun error
int sPass_addPassengers(sPassengers array[], int TAM)
{
	int rtn = -1;
	sPassengers auxPasajeros;

	///BUSCO ESPACIO EN ARRAY
	int index = sPass_getFreeIndex(array, TAM);

	///SI INDEX == -1 ARRAY LLENO
	///SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE

	if (index != -1)
	{
		///PIDO DATOS - CARGO Pasajeros AUXILIAR
		auxPasajeros = sPass_enterData();

		///SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPasajeros.id = sPass__getID();

		///CAMBIO SU ESTADO A "OCUPADO"
		auxPasajeros.isEmpty = OCUPADO;

		///SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxPasajeros;

		///RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

/// @fn int sPass_removePassengers(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassenger y su tama�o, muestra un listado de
/// pasajeros donde se encuentran todos los datos de cada uno, pide el ID a dar de baja y
/// le cambia su estado a BAJA
/// @param array
/// @param TAM
/// @return Retorna 1 si se pudo dar de baja o -1 si hubo algun error
int sPass_removePassengers(sPassengers array[], int TAM)
{
	int rtn = 0;
	int idPasajero;
	int index;
	int flag = 0;

	///LISTO TODOS LOS Pasajeros
	if(sPass_printPassengers(array, TAM,1))
	{
		///BANDERA EN 1 SI HAY Pasajeros DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	///SI HAY Pasajeros PARA DAR DE BAJA
	if(flag)
	{
		///PIDO ID A DAR DE BAJA
		utn_getNumero("\n\n\nINGRESE ID DEL PASAJERO A DAR DE BAJA: ", "ERROR. ", 1000, 9999, 3, &idPasajero);

		///BUSCO INDEX POR ID EN ARRAY
		while (sPass_findPassengerByID(array, TAM, idPasajero) == -1)
		{
			puts("\nNO EXISTE ID.");

			///PIDO OTRA VEZ ID A DAR DE BAJA
			utn_getNumero("\n\n\nINGRESE ID DEL PASAJERO A DAR DE BAJA: ", "ERROR. ", 1000, 9999, 3, &idPasajero);
		}

		///OBTENGO INDEX DEL ARRAY DE Pasajeros A DAR DE BAJA
		index = sPass_findPassengerByID(array, TAM, idPasajero);

		///BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		puts("\nSE HA DADO DE BAJA EL PASAJERO. \n");

		///RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

/// @fn int sPass_modifyData(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassenger y su tama�o, muestra un listado de
/// pasajeros donde se encuentran todos los datos de cada uno, pide el ID a modificar y
/// usa sPass_modifyOne para modificar el campo que el usuario elija en el menu mostrado
/// @param array
/// @param TAM
/// @return @return Retorna 1 si se pudo modificar el campo requerido o -1 si hubo algun error
int sPass_modifyData(sPassengers array[], int TAM)
{
	int rtn = 0;
	int idPasajero;
	int index;
	int flag = 0;
	sPassengers auxiliar;

	///LISTO TODOS LOS Pasajeros
	if(sPass_printPassengers(array, TAM,1))
	{
		///BANDERA EN 1 SI HAY Pasajeros DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	///SI HAY Pasajeros PARA MODIFICAR
	if(flag)
	{
		///PIDO ID A MODIFICAR
		utn_getNumero("\n\nINGRESE ID DEL PASAJERO A MODIFICAR: ", "ERROR \n", 1000, 9999, 3, &idPasajero);

		///BUSCO INDEX POR ID EN ARRAY
		while (sPass_findPassengerByID(array, TAM, idPasajero) == -1)
		{
			puts("NO EXISTE ID.");

			///PIDO ID A MODIFICAR
			utn_getNumero("\n\nINGRESE ID DEL PASAJERO A MODIFICAR: ", "ERROR \n", 1000, 9999, 3, &idPasajero);
		}

		///OBTENGO INDEX DEL ARRAY DE Pasajeros A MODIFICAR
		index = sPass_findPassengerByID(array, TAM, idPasajero);

		///LLAMO A FUNCION QUE MODIFICA Pasajeros
		auxiliar = sPass_modifyOne(array[index]);

		///MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

