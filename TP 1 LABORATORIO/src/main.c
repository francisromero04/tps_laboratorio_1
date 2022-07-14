/*
 ============================================================================
 Name        : TP.c
 Author      : Francis Romero división H
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;

	int cantidadKm = 0;
	int	precioKmAerolineas = 0;
	int precioKmLatam = 0;
	int precioForzadoKmLatam;
	int precioForzadoKmAerolineas;

	int precioAerolineas = 0;
	int precioDebitoAerolineas = 0;
	int precioCreditoAerolineas = 0;
	int precioDebitoForzadoAero;
	int precioCreditoForzadoAero;

	int precioLatam = 0;
	int precioDebitoLatam = 0;
	int precioCreditoLatam = 0;
	int precioDebitoForzadoLatam;
	int precioCreditoForzadoLatam;

	float precioAerolineasBtc = 0;
	float precioLatamBtc = 0;
	float precioBtcForzadoAero;
	float precioBtcForzadoLatam;

	float diferencia;
	float diferenciaForzada;

	int contadorVueltas = 0;

	puts("\t\t\t----------------");
	puts("\t\t\tMenú de Opciones");
	puts("\t\t\t----------------\n");
	puts("1. Ingresar kilómetros: ");
	puts("\n2. Ingresar precio de vuelos");
	puts("  -Precio vuelo Aerolíneas \n  -Precio vuelo Latam ");
	puts("\n3. Calcular todos los costos:");
	puts("  a) Tarjeta de débito (descuento 10%)");
	puts("  b) Tarjeta de crédito (interés 25%)");
	puts("  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
	puts("  d) Mostrar precio por km (precio unitario)");
	puts("  e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
	puts("\n4. Informar Resultados");
	puts("\n5. Carga forzada de datos");
	puts("\n6. Salir");

	do
	{
		contadorVueltas++;
		getInt("\nIngrese una opción: (Opciones 1, 2, 3, 4, 5, 6) ", ("Opción invalida, reingrese opción: "), 1, 6, 3, &opcion);

			switch(opcion)
			{
				case 1:
					getInt("\n1. Ingresar kilómetros: ", "Error, reingrese kilometros: ", 1, 999999, 3, &cantidadKm);
				break;

				case 2:
					getInt("\n2. Ingresar precio de vuelos: (Aerolíneas=y,Latam=z)\n  -Precio vuelo Aerolíneas: ",
							"\n -Error, reingrese precio: ", 1, 999999, 3, &precioAerolineas);
					getInt("  -Precio vuelo Latam: ", "\n -Error, reingrese precio: ", 1, 999999, 3, &precioLatam);
				break;

				case 3:
					if(cantidadKm != 0 && precioAerolineas != 0 && precioLatam != 0)
					{
//Debito
						precioDebitoAerolineas = calcularDebito(precioAerolineas, 0.1);
						precioDebitoLatam = calcularDebito(precioLatam, 0.1);
//Credito
						precioCreditoAerolineas = calcularCredito(precioAerolineas, 0.25);
						precioCreditoLatam = calcularCredito(precioLatam, 0.25);
//Btc
						precioAerolineasBtc = calcularBtc(precioAerolineas, 4606954.55);
						precioLatamBtc = calcularBtc(precioLatam, 4606954.55);
//Precio km
						precioKmAerolineas = calcularPrecioKm(precioAerolineas, cantidadKm);
						precioKmLatam = calcularPrecioKm(precioLatam, cantidadKm);
//Diferencia
						diferencia = calcularDiferencia(precioAerolineas, precioLatam);
						puts("\nUsted ingresó la opcion 3, se han calculado todos los costos.");
					}
					else
					{
						puts("\n-Regresarás al menu principal ya que no has ingresado los datos requeridos para calcular.");
					}
				break;

				case 4:
					if(cantidadKm != 0 && precioAerolineas != 0 && precioLatam != 0)
					{
						imprimirCalculos(contadorVueltas, cantidadKm, precioAerolineas, precioLatam,
								precioDebitoAerolineas, precioCreditoAerolineas, precioDebitoLatam,
								precioCreditoLatam, precioAerolineasBtc, precioLatamBtc,
								precioKmAerolineas, precioKmLatam, diferencia);
					}
					else
					{
						puts("\n-Regresarás al menu principal ya que no has ingresado los datos requeridos para calcular.");
					}
				break;

				case 5:
//Debito forzado
					precioDebitoForzadoAero = calcularDebito(162965, 0.1);
					precioDebitoForzadoLatam = calcularDebito(159339, 0.1);
//Credito forzado
					precioCreditoForzadoAero = calcularCredito(162965, 0.25);
					precioCreditoForzadoLatam = calcularCredito(159339, 0.25);
//Btc forzado
					precioBtcForzadoAero = calcularBtc(162965, 4606954.55);
					precioBtcForzadoLatam = calcularBtc(159339, 4606954.55);
//Precio km forzado
					precioForzadoKmLatam = calcularPrecioKm(159339 , 7090 );
					precioForzadoKmAerolineas = calcularPrecioKm(162965, 7090 );
//Diferencia forzado
					diferenciaForzada = calcularDiferencia(162965, 159339);

					imprimirCalculos(contadorVueltas,7090, 162965, 159339,precioDebitoForzadoAero,
							precioCreditoForzadoAero, precioDebitoForzadoLatam,
							precioCreditoForzadoLatam,precioBtcForzadoAero,
							precioBtcForzadoLatam, precioForzadoKmAerolineas,
							precioForzadoKmLatam, diferenciaForzada);
				break;
			} //fin switch
	}while(opcion != 6);

	return EXIT_SUCCESS;
}//FIN MAIN
