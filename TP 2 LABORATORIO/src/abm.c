#include "abm.h"

//-----------------------------------------------------STATICS HEADERS---------------------------------------------------

static int sPass__getID(void);
static int sPass_getFreeIndex(sPassengers array[], int TAM);
static int sPass_findPassengerByID(sPassengers array[], int TAM, int ID);
static sPassengers sPass_enterData(void);
static sPassengers sPass_modifyOne(sPassengers Pasajero);
static void sPass_printOne(sPassengers Pasajero, int criterio);

//-----------------------------------------------------STATICS SOURCES---------------------------------------------------

/// @fn int sPass__getID(void)
/// @brief Con la variable passenger_idIncremental incrementa un ID desde 1000 en adelante
/// @return Retorna el ID que incremento
static int sPass__getID(void)
{
	///INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION sPass_getID();
	static int passenger_idIncremental = 1000;
	static int rtn;

	rtn = passenger_idIncremental++;

	return rtn;
}

/// @fn int sPass_getFreeIndex(sPassengers[], int)
/// @brief Recibe el array cuyo tipo de dato es sPassengers y su tama�o, luego busca un espacio LIBRE en el indice,
///  para despu�s guardar datos en ese espacio
/// @param array
/// @param TAM
/// @return Retorna el espacio LIBRE que encontro en el indice
static int sPass_getFreeIndex(sPassengers array[], int TAM)
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
static int sPass_findPassengerByID(sPassengers array[], int TAM, int ID)
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
static sPassengers sPass_enterData(void)
{
	sPassengers auxiliar;
	int opcionTipoPasajero;
	int opcionEstadoVuelo;

	printf("\n");
	utn_getString("INGRESE NOMBRE: ", "ERROR. ", 2, TAM_CHAR, auxiliar.name);
	utn_getString("INGRESE APELLIDO: ", "ERROR. ", 2, TAM_CHAR, auxiliar.lastname);
	utn_getAlfaNum("INGRESE EL CODIGO DE VUELO ALFANUMERICO (no mas de 10 caracteres): ",
			"ERROR. ", 2, 11, auxiliar.flycode);

	utn_getNumero("INGRESE TIPO DE PASAJERO (TIPO 1: TURISTA | TIPO 2: EJECUTIVO | TIPO 3: PREMIUM): ",
				"ERROR. ", 1, 3, 2, &opcionTipoPasajero);
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
			"ERROR. ", 0, 2, 2, &opcionEstadoVuelo);
	switch(opcionEstadoVuelo)
	{
		case 1:
			auxiliar.statusFlight = ACTIVO;
		break;

		case 2:
			auxiliar.statusFlight = CANCELADO;
		break;
	}

	utn_getNumFloat("INGRESE PRECIO: ", "ERROR. ", 0, 999999, 2, &auxiliar.price);

	return auxiliar;
}

/// @fn sPassengers sPass_modifyOne(sPassengers)
/// @brief Recibe un tipo de dato sPassengers, muestra un men� con opciones para
/// que el usuario selecione cual dato quiere modificar y los carga en un
/// auxiliar para luego igualarlo al tipo de dato que recibi�
/// @param Pasajero
/// @return Retorna
static sPassengers sPass_modifyOne(sPassengers Pasajero)
{
	int opcionMenuModificar;
	int opcionEstadoVuelo;
	int opcionTipoPasajero;

	do
	{
		puts("\nCAMPOS A MODIFICAR:");
		puts("1. NOMBRE");
		puts("2. APELLIDO");
		puts("3. CODIGO DE VUELO");
		puts("4. TIPO DE PASAJERO");
		puts("5. ESTADO DE VUELO");
		puts("6. PRECIO");
		puts("7. GUARDAR CAMBIOS");

		utn_getNumero("\nINGRESE LA OPCION DEL CAMPO A MODIFICAR: ", "ERROR. ", 1, 7, 1, &opcionMenuModificar);

		switch(opcionMenuModificar)
		{
			case 1:
				if(utn_getString("INGRESE EL NUEVO NOMBRE: ", "ERROR. ", 2, TAM_CHAR, Pasajero.name) == 0)
				{
					puts("EL NOMBRE SE HA MODIFICADO.");
				}
			break;

			case 2:
				if(utn_getString("INGRESE EL NUEVO APELLIDO: ", "ERROR. ", 2, TAM_CHAR, Pasajero.lastname) == 0)
				{
					puts("EL APELLIDO SE HA MODIFICADO.");
				}
			break;

			case 3:
				if(utn_getAlfaNum("INGRESE EL NUEVO CODIGO DE VUELO ALFANUMERICO (no mas de 10 caracteres): ",
						"ERROR. ", 2, 11, Pasajero.flycode) == 0)
				{
					puts("EL CODIGO DE VUELO SE HA MODIFICADO.");
				}
			break;

			case 4:
				utn_getNumero("INGRESE NUEVO TIPO DE PASAJERO (TIPO 1: TURISTA | TIPO 2: EJECUTIVO | TIPO 3: PREMIUM): ",
								"ERROR. ", 1, 3, 2, &opcionTipoPasajero);
				switch(opcionTipoPasajero)
				{
					case 1:
						Pasajero.typePassenger = TURISTA;
						puts("EL TIPO DE PASAJERO SE HA MODIFICADO.");
					break;

					case 2:
						Pasajero.typePassenger = EJECUTIVO;
						puts("EL TIPO DE PASAJERO SE HA MODIFICADO.");
					break;

					case 3:
						Pasajero.typePassenger = PREMIUM;
						puts("EL TIPO DE PASAJERO SE HA MODIFICADO.");
					break;
				}
			break;

			case 5:
				utn_getNumero("INGRESE EL NUEVO ESTADO DE VUELO (OPCION 1: ACTIVO | OPCION 2: INACTIVO): ",
							  "ERROR. ", 0, 10, 2, &opcionEstadoVuelo);
				switch(opcionEstadoVuelo)
				{
					case 1:
						Pasajero.statusFlight = ACTIVO;
						puts("EL ESTADO DEL PASAJERO SE HA MODIFICADO.");
					break;

					case 2:
						Pasajero.statusFlight = CANCELADO;
						puts("EL ESTADO DEL PASAJERO SE HA MODIFICADO.");
					break;
				}
			break;

			case 6:
				if(utn_getNumFloat("INGRESE EL NUEVO PRECIO: ", "ERROR. ", 0, 999999, 2, &Pasajero.price) == 0)
				{
					puts("EL PRECIO SE HA MODIFICADO.");
				}
			break;

			case 7:
				puts("\nDATOS MODIFICADOS CORRECTAMENTE, VOLVIENDO AL MENU PRINCIPAL...");
			break;
		}
	}while(opcionMenuModificar != 7);

	return Pasajero;
}

/// @fn void sPass_printOne(sPassengers, int)
/// @brief Recibe un tipo de dato sPassenger y un criterio a mostrar. Seg�n el criterio,
/// muestra
/// @param Pasajero
/// @param criterio
static void sPass_printOne(sPassengers Pasajero, int criterio)
{
	char estadoVuelo[TAM_CHAR];
	char tipoPasajero[TAM_CHAR];

	switch(criterio)
	{
		case 1:
			printf("|%4d|%-15s|%-16s|%-12.2f|", Pasajero.id, Pasajero.lastname, Pasajero.name, Pasajero.price);

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

				printf("|%4d|%-15s|%-16s|%-12.2f|%-16s|", Pasajero.id, Pasajero.lastname, Pasajero.name, Pasajero.price,Pasajero.flycode);
				strncpy(estadoVuelo, "ACTIVO", sizeof(estadoVuelo));
				printf("%-16s|\n", estadoVuelo);
			}
		break;
	}
}

//-----------------------------------------------------ABM---------------------------------------------------------------

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
		utn_getNumero("\nINGRESE ID DEL PASAJERO A DAR DE BAJA: ", "ERROR. ", 1000, 9999, 3, &idPasajero);

		///BUSCO INDEX POR ID EN ARRAY
		while (sPass_findPassengerByID(array, TAM, idPasajero) == -1)
		{
			puts("\nNO EXISTE ID.");

			///PIDO OTRA VEZ ID A DAR DE BAJA
			utn_getNumero("\nINGRESE ID DEL PASAJERO A DAR DE BAJA: ", "ERROR. ", 1000, 9999, 3, &idPasajero);
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
/// @brief Recibe el array cuyo tipo de dato es sPassenger y su tamaño, muestra un listado de
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
		utn_getNumero("\nINGRESE ID DEL PASAJERO A MODIFICAR: ", "ERROR. ", 1000, 9999, 3, &idPasajero);

		///BUSCO INDEX POR ID EN ARRAY
		while(sPass_findPassengerByID(array, TAM, idPasajero) == -1)
		{
			puts("NO EXISTE ID.");
			///PIDO ID A MODIFICAR
			utn_getNumero("\nREINGRESE ID DEL PASAJERO A MODIFICAR: ", "ERROR. ", 1000, 9999, 3, &idPasajero);
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

int sPass_CargaForzada(sPassengers listaPasajeros[])
{
	int rtn = -1;

	if(listaPasajeros != NULL)
	{
		sPassengers pasajeroAuxiliar[10];

		pasajeroAuxiliar[0].id = 1000;
		strcpy(pasajeroAuxiliar[0].name,"Jose");
		strcpy(pasajeroAuxiliar[0].lastname,"Falcon");
		pasajeroAuxiliar[0].price = 86000;
		pasajeroAuxiliar[0].typePassenger = TURISTA;
		strcpy(pasajeroAuxiliar[0].flycode,"PMQ897");
		pasajeroAuxiliar[0].statusFlight = ACTIVO;
		pasajeroAuxiliar[0].isEmpty = OCUPADO;

		pasajeroAuxiliar[1].id = 1001;
		strcpy(pasajeroAuxiliar[1].name,"Liliana");
		strcpy(pasajeroAuxiliar[1].lastname,"Carreras");
		pasajeroAuxiliar[1].price = 80000;
		pasajeroAuxiliar[1].typePassenger = TURISTA;
		strcpy(pasajeroAuxiliar[1].flycode,"BVA582");
		pasajeroAuxiliar[1].statusFlight = ACTIVO;
		pasajeroAuxiliar[1].isEmpty = OCUPADO;

		pasajeroAuxiliar[2].id = 1002;
		strcpy(pasajeroAuxiliar[2].name,"Celeste");
		strcpy(pasajeroAuxiliar[2].lastname,"Falcon");
		pasajeroAuxiliar[2].price = 83000;
		pasajeroAuxiliar[2].typePassenger = TURISTA;
		strcpy(pasajeroAuxiliar[2].flycode,"HIJ719");
		pasajeroAuxiliar[2].statusFlight = ACTIVO;
		pasajeroAuxiliar[2].isEmpty = OCUPADO;

		pasajeroAuxiliar[3].id = 1003;
		strcpy(pasajeroAuxiliar[3].name,"Carla");
		strcpy(pasajeroAuxiliar[3].lastname,"Falcon");
		pasajeroAuxiliar[3].price = 85000;
		pasajeroAuxiliar[3].typePassenger = TURISTA;
		strcpy(pasajeroAuxiliar[3].flycode,"FRA263");
		pasajeroAuxiliar[3].statusFlight = ACTIVO;
		pasajeroAuxiliar[3].isEmpty = OCUPADO;

		pasajeroAuxiliar[4].id = 1004;
		strcpy(pasajeroAuxiliar[4].name,"Horacio");
		strcpy(pasajeroAuxiliar[4].lastname,"Romero");
		pasajeroAuxiliar[4].price = 70000;
		pasajeroAuxiliar[4].typePassenger = EJECUTIVO;
		strcpy(pasajeroAuxiliar[4].flycode,"MRN375");
		pasajeroAuxiliar[4].statusFlight = CANCELADO;
		pasajeroAuxiliar[4].isEmpty = OCUPADO;

		pasajeroAuxiliar[5].id = 1005;
		strcpy(pasajeroAuxiliar[5].name,"Daniela");
		strcpy(pasajeroAuxiliar[5].lastname,"Barrionuevo");
		pasajeroAuxiliar[5].price = 50000;
		pasajeroAuxiliar[5].typePassenger = EJECUTIVO;
		strcpy(pasajeroAuxiliar[5].flycode,"ELN358");
		pasajeroAuxiliar[5].statusFlight = CANCELADO;
		pasajeroAuxiliar[5].isEmpty = OCUPADO;

		pasajeroAuxiliar[6].id = 1006;
		strcpy(pasajeroAuxiliar[6].name,"Marianela");
		strcpy(pasajeroAuxiliar[6].lastname,"Romero");
		pasajeroAuxiliar[6].price = 57000;
		pasajeroAuxiliar[6].typePassenger = EJECUTIVO;
		strcpy(pasajeroAuxiliar[6].flycode,"MTS076");
		pasajeroAuxiliar[6].statusFlight = CANCELADO;
		pasajeroAuxiliar[6].isEmpty = OCUPADO;

		pasajeroAuxiliar[7].id = 1007;
		strcpy(pasajeroAuxiliar[7].name,"Francis");
		strcpy(pasajeroAuxiliar[7].lastname,"Romero");
		pasajeroAuxiliar[7].price = 60000;
		pasajeroAuxiliar[7].typePassenger = PREMIUM;
		strcpy(pasajeroAuxiliar[7].flycode,"CRL205");
		pasajeroAuxiliar[7].statusFlight = ACTIVO;
		pasajeroAuxiliar[7].isEmpty = OCUPADO;

		pasajeroAuxiliar[8].id = 1008;
		strcpy(pasajeroAuxiliar[8].name,"Exequiel");
		strcpy(pasajeroAuxiliar[8].lastname,"Capelleti");
		pasajeroAuxiliar[8].price = 97000;
		pasajeroAuxiliar[8].typePassenger = PREMIUM;
		strcpy(pasajeroAuxiliar[8].flycode,"RCO246");
		pasajeroAuxiliar[8].statusFlight = ACTIVO;
		pasajeroAuxiliar[8].isEmpty = OCUPADO;

		pasajeroAuxiliar[9].id = 1009;
		strcpy(pasajeroAuxiliar[9].name,"Fidel");
		strcpy(pasajeroAuxiliar[9].lastname,"Jofre");
		pasajeroAuxiliar[9].price = 79000;
		pasajeroAuxiliar[9].typePassenger = PREMIUM;
		strcpy(pasajeroAuxiliar[9].flycode,"AGS192");
		pasajeroAuxiliar[9].statusFlight = ACTIVO;
		pasajeroAuxiliar[9].isEmpty = OCUPADO;

		listaPasajeros[10] = pasajeroAuxiliar[0];
		listaPasajeros[11] = pasajeroAuxiliar[1];
		listaPasajeros[12] = pasajeroAuxiliar[2];
		listaPasajeros[13] = pasajeroAuxiliar[3];
		listaPasajeros[14] = pasajeroAuxiliar[4];
		listaPasajeros[15] = pasajeroAuxiliar[5];
		listaPasajeros[16] = pasajeroAuxiliar[6];
		listaPasajeros[17] = pasajeroAuxiliar[7];
		listaPasajeros[18] = pasajeroAuxiliar[8];
		listaPasajeros[19] = pasajeroAuxiliar[9];

		rtn = 1;
	}

	return rtn;
}

