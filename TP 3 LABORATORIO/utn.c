#include "utn.h"

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
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getInt(int * pResultado)
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
		printf("%s",mensaje);
		rtnGetFloat = getFloat(&auxiliarFloat);
		do
		{
			if(rtnGetFloat == -1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				printf("%s",mensajeError);
				fflush(stdin); //si ingresa letra no entra mas en el while
				getFloat(&auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

int esNumericaFloat(char cadena[])
{
	int retorno = -1;
	int i = 0;
	int contadorPuntos = 0;

	if(cadena != NULL)
	{
		while(cadena[i] != '\0' || (cadena[i] > '9' && cadena[i] != '.') )
		{
			i++;
			if(cadena[i] == '.')
			{
				contadorPuntos++;
			}

			if(contadorPuntos > 1)
			{
				retorno = -2;
				puts("\nError, mas de un punto\n");
				break;
			}
		}
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}

int getFloat(float* pNumeroTomado)
{
	int retorno = -1;
	char numeroAuxiliar[200];

	if( myGets(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0
			&& esNumericaFloat(numeroAuxiliar) )
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
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer)) ==0 &&
    		esNombre(buffer, sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud )
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int esNombre(char* cadena,int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if( (cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				(cadena[i] < '0' || cadena[i] > '9') )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//---------------------------------------CAMBIAR ESTAS FUNCIONES DE LUGAR--------------------------------------------
void invertirCadena(char* cadena)
{
	int i, len;

	if(cadena != NULL)
	{
		len = strlen(cadena);

		for(i = len-1; i >= 0; i--)
		{
			printf("CADENA INVERTIDA: %c", cadena[i]);
		}
	}
}

int ordenarCaracteres(char* cadena)
{
	int i, j;
	int aux;
	int rtn = -1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for (i = 0; i < strlen(cadena) - 1; i++)
		{
			for (j = i + 1; j < 10; j++)
			{
				///CRITERIO DE ORDENAMIENTO
				if (cadena[i] > cadena[j])
				{
					///INTERCAMBIO POSICIONES EN ARRAY
					aux = cadena[i];
					cadena[i] = cadena[j];
					cadena[j] = aux;
					rtn = 1;
				}
			}
		}
	}

	return rtn;
}