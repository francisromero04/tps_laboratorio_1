#include "input.h"

//-----------------------------------------------TODAS USAN myGets------------------------------------------------------

int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strlen(bufferString)-1] == '\n')
			{
				bufferString[strlen(bufferString)-1] = '\0';
			}
			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//-----------------------------------------------GET NUMERO INT---------------------------------------------------------

int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* pResultado)
{
	int retorno = -1;
	int rtnGetInt;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		rtnGetInt = getInt(&bufferInt);

		if(rtnGetInt == 0 && pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& reintentos >= 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);

	return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; //VERDADERO
		for(i = 0; i<limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(	pResultado != NULL &&
		myGets(buffer, sizeof(buffer)) == 0 &&
		esNumerica(buffer,sizeof(buffer)) )
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	return retorno;
}

//-----------------------------------------------GET NUMERO FLOAT-------------------------------------------------------

int utn_getNumFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, float *pNumeroIngresado)
{
	int retorno = -1;
	float auxiliarFloat;
	float rtnGetFloat;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			rtnGetFloat = getFloat(&auxiliarFloat);

			if(rtnGetFloat == 0 && pNumeroIngresado != NULL && mensaje != NULL && mensajeError != NULL
					&& reintentos >= 0 && auxiliarFloat >= minimo && auxiliarFloat <= maximo)
			{
				retorno = 0;
				*pNumeroIngresado = auxiliarFloat;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}

int esNumericaFloat(char* cadena, int limite)
{
	int i = 0;
	int retorno = -1;
	int contadorPuntos = 0;

	if(cadena != NULL && limite > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] == '.' && contadorPuntos == 0)
			{
				contadorPuntos++;
				i++;
				continue;
			}

			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getFloat(float* pNumeroTomado)
{
	int retorno = -1;
	char numeroAuxiliar[200];

	if( myGets(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0
			&& esNumericaFloat(numeroAuxiliar, sizeof(numeroAuxiliar)) )
	{
		*pNumeroTomado = atof(numeroAuxiliar);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------GET STRING-------------------------------------------------------------

int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getString(bufferString, sizeof(bufferString)) == 0 &&
				strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}

		printf("%s",mensajeError);
	}

	return retorno;
}

int getString(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

	if(pResultado != NULL)
	{
		if(	myGets(buffer,sizeof(buffer)) == 0 &&
			esString(buffer, sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud )
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}

    return retorno;
}

int esString(char* cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if( (cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') )
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int utn_getAlfaNum(char mensaje[], char mensajeError[], int reintentos, int TAM, char cadena[])
{
	int rtn = -1;
	char buffer[TAM];
	int rtnString;

	if(mensaje != NULL && mensajeError != NULL && cadena != NULL && TAM > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		rtnString = myGets(buffer, sizeof(buffer));
		do
		{
			if(rtnString == 0 && strlen(buffer) <= TAM && esAlfanumerico(buffer, sizeof(buffer)) == 0)
			{
				strncpy(cadena, buffer, TAM);
				rtn = 0;
				break;
			}

			printf("%s", mensajeError);
			fflush(stdin);
			rtnString = myGets(buffer, sizeof(buffer));
			reintentos--;

		}while(reintentos >= 0);
	}
	return rtn;
}

int esAlfanumerico(char cadena[], int len)
{
	int rtn = -1;
	int i = 0;

	if(cadena != NULL && len > 0)
	{
		while(cadena[i] != '\0')
		{
			if( (cadena[i] < 'a' || cadena[i] > 'z') &&
			    (cadena[i] < 'A' || cadena[i] > 'Z') &&
			    (cadena[i] < '0' || cadena[i] > '9') )
			{
				rtn = 0;
				break;
			}
			i++;
		}
	}
	return rtn;
}

