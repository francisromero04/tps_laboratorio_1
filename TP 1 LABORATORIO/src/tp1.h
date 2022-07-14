/*
 * tp1.h
 *
 *  Created on: 11 abr. 2022
 *      Author: PC
 */

#ifndef TP1_H_
#define TP1_H_

#include <stdio.h>
#include <stdlib.h>

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pNumeroIngresado);
float calcularDebito(int precioIngresado, float procentaje);
float calcularCredito(int precioIngresado, float porcentaje);
float calcularBtc(int precioIngresado, float precioBtc);
int calcularPrecioKm(int precioIngresado, int cantidadKm);
int calcularDiferencia(int precioAerolineas, int precioLatam);
void imprimirCalculos(int contadorVueltas, int kilometros, int precioAero, int precioLatam, int debitoAero, int creditoAero, int debitoLatam, int creditoLatam, float bitcoinAero, float bitcoinLatam, int unitarioAero, int unitarioLatam, float diferencia);

#endif /* TP1_H_ */
