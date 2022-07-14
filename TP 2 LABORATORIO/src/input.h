#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CADENA 11

//PROTOTIPOS FUNCIONES GET INT
int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* pResultado);
int esNumerica(char* cadena, int limite);
int getInt(int *pResultado);

//PROTOTIPOS FUNCIONES GET FLOAT
int utn_getNumFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, float *pNumeroIngresado);
int esNumericaFloat(char* cadena, int limite);
int getFloat(float* pNumeroTomado);

//PROTOTIPOS FUNCIONES GET STRING
int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);
int getString(char* pResultado, int longitud);
int esString(char* cadena, int longitud);

//PROTOTIPOS FUNCIONES GET STRING ALFANUM
int utn_getAlfaNum(char mensaje[], char mensajeError[], int reintentos, int TAM, char cadena[]);
int esAlfanumerico(char cadena[], int len);

//PROTOTIPO MYGETS | SE USA EN TODAS
int myGets(char* cadena, int longitud);

#endif /* INPUT_H_ */
