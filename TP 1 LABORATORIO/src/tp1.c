/*
 * tp1.c
 *
 *  Created on: 11 abr. 2022
 *      Author: PC
 */

#include "tp1.h"

/// @fn int getInt(char[], char[], int, int, int, int*)
/// @brief Reserva un espacio de memoria para un mensaje y para un mensaje de error a traves de punteros, luego un entero
/// para un minimo y un maximo, otro para reintentos y reserva memoria mediante puntero para undato ingresado tipo int
/// @param char[] mensaje
/// @param char[] mensajeError
/// @param int minimo
/// @param int maximo
/// @param int reintentos
/// @param int* pNumeroIngresado
/// @return Retorna un mensaje de error si el usuario ingresa mal el dato a traves de un valor de -1, sino se guarda en
/// un auxiliar con un valor de retornode 0

//Desarrollo getInt
int getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pNumeroIngresado)
{
	int retorno = -1; //significa que no pudo tomar el dato correcto
	int auxiliarInt; //aca guardamos el dato que ingresa el usuario
	int retornoScanf;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)//null es la direccion 0 de la memoria
	{
		printf("%s",mensaje);
		retornoScanf = scanf("%d",&auxiliarInt);
		fflush(stdin);
		do
		{
			if(retornoScanf == -1 || auxiliarInt > maximo || auxiliarInt < minimo)
			{
				printf("%s",mensajeError);
				retornoScanf = scanf("%d",&auxiliarInt);
				fflush(stdin);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroIngresado = auxiliarInt;
				retorno = 0; //retorna 0 pq esta bien
			}
		}while(reintentos > 0);
	}//FIN IF
	return retorno;
}

/// @fn float calcularDebito(int, float)
/// @brief Recibe un entero para el precio de vuelo ingresado por el usuario a traves de la funcion getInt,
/// y un flotante para recibir un valor que multiplica al precio ingresado y lo resta para calcular descuento
/// @param int precioIngresado
/// @param float porcentaje
/// @return Retorna el precio con decremento

//Desarrollo debito
float calcularDebito(int precioIngresado, float porcentaje) //funcion para sacar un descuento
{
	float rtn;
	rtn = precioIngresado - (precioIngresado*porcentaje);
	return rtn;
}

/// @fn float calcularCredito(int, float)
/// @brief Recibe un entero para el precio de vuelo ingresado por el usuario a traves de la funcion getInt,
/// y un flotante para recibir un valor que multiplica al precio ingresado y lo suma para calcular descuento
/// @param int precioIngresado
/// @param float porcentaje
/// @return Retorna el precio co incremento

//Desarrollo credito
float calcularCredito(int precioIngresado, float porcentaje) //funcion para sacar un incremento
{
	float rtn;
	rtn = precioIngresado + (precioIngresado*porcentaje);
	return rtn;
}

/// @fn float calcularBtc(int, float)
/// @brief Recibe un entero para el precio de vuelo ingresado por el usuario a traves de la funcion getInt,
/// y un flotante para recibir un valor que divida al precio ingresado y asi calcular precio bitcoin
/// @param int precioIngresado
/// @param float precioBtc
/// @return Retorna un flotante

//Desarrollo btc
	float calcularBtc(int precioIngresado, float precioBtc) //funcion division reutilizada
	{
		float rtn = 0;
		if(precioBtc != 0)
		{
			rtn = precioIngresado / precioBtc;
		}
		rtn = ((float)precioIngresado) / precioBtc;
		return rtn;
	}

	/// @fn int calcularPrecioKm(int, int)
/// @brief Recibe un entero para el precio de vuelo ingresado por el usuario a traves de la funcion getInt,
/// y otro entero para recibir un valor que divide al precio ingresado
/// @param int precioIngresado
/// @param int cantidadKm
/// @return Retorna un flotante

//Desarrollo precioKm
	int calcularPrecioKm(int precioIngresado, int cantidadKm) //funcion division reutilizada
	{
		float rtn = 0;
		if(cantidadKm != 0)
		{
			rtn = precioIngresado / cantidadKm;
		}
		rtn = ((float)precioIngresado) / cantidadKm;
		return rtn;
	}

/// @fn int calcularDiferencia(int, int)
/// @brief Recibe dos enteros para los distintos precio de vuelo ingresado por el usuario a traves de la funcion getInt
/// @param int precioAerolineas
/// @param int precioLatam
/// @return Retorna un flotante por si el resultado es un valor muy alto

//Desarrollo diferencia //funcion resta reutilizada y casteada a flotante
	int calcularDiferencia(int precioAerolineas, int precioLatam)
	{
		float rtn;
		if(precioAerolineas > precioLatam)
		{
			rtn = ((float)precioAerolineas) - precioLatam;
		}
		else
		{
			rtn = ((float)precioLatam) - precioAerolineas;
		}
		return rtn;
	}

/// @fn int imprimirCalculos(int, int, int, int, int, int, int, int, float, float, int, int, float)
/// @brief Recibe enteros y flotantes dependiendo los resultados que fueron calculados mediante lasfunciones y mostralos
/// @param int contadorVueltas
/// @param int kilometros
/// @param int precioAero
/// @param int precioLatam
/// @param int debitoAero
/// @param int creditoAero
/// @param int debitoLatam
/// @param int creditoLatam
/// @param float bitcoinAero
/// @param float bitcoinLatam
/// @param int unitarioAero
/// @param int unitarioLatam
/// @param float diferencia
/// @return Retorna void, solo resultados ya que unicamente muestra

//Desarrollo imprimirCalculos
	void imprimirCalculos(int contadorVueltas, int kilometros, int precioAero, int precioLatam, int debitoAero,
			int creditoAero, int debitoLatam, int creditoLatam, float bitcoinAero, float bitcoinLatam,
			int unitarioAero, int unitarioLatam, float diferencia)
	{
		printf("\nVuelta n° %d",contadorVueltas);
		puts("\n-----------\n");
		printf("1. Ingresar kilómetros: (km = %d)\n\n",kilometros);
		printf("2. Ingresar precio de vuelos: (Aerolíneas = $%d,Latam = $%d)\n",precioAero, precioLatam);
		puts("\n3. Calcular todos los costos: ");
		puts("  a) Tarjeta de débito (descuento 10%)");
		puts("  b) Tarjeta de crédito (interés 25%)");
		puts("  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		puts("  d) Mostrar precio por km (precio unitario)");
		puts("  e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
		puts("4. Informar Resultados: ");
		puts("  Latam:");
		printf("  a) Precio con tarjeta de débito: $%d \n",debitoLatam);
		printf("  b) Precio con tarjeta de crédito: $%d \n",creditoLatam);
		printf("  c) Precio pagando con bitcoin : %.2f BTC \n",bitcoinLatam);
		printf("  d) Precio unitario: $%d \n\n",unitarioLatam);
		puts("  Aerolíneas:");
		printf("  a) Precio con tarjeta de débito: $%d \n",debitoAero);
		printf("  b) Precio con tarjeta de crédito: $%d \n",creditoAero);
		printf("  c) Precio pagando con bitcoin : %.2f BTC \n",bitcoinAero);
		printf("  d) Precio unitario: $%d \n",unitarioAero);
		printf("  La diferencia de precio es : $%.2f \n\n",diferencia);
		puts("5. Carga forzada de datos \n");
		puts("6. Salir");
	}




