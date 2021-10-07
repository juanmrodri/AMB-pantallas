/*
 * utn_biblioteca_arrays.c
 *
 *  Created on: 18 sept 2021
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca_arrays.h"
#include "utn_biblioteca.h"

/**
 * @brief void imprimirArray(float[], int)
 * 		  imprime todas las posiciones del array, en este caso del tipo float
 *
 * @param pArrayUno esta es la direccion de memoria del array
 * @param len es la cantidad de posiciones del array
 */

void imprimirArray(int pArrayUno[], int len) // como regla gral, esta bueno tener en cuenta que como parametro, paso cuanto mide el array
{
	int i;
	int dia;

	if(pArrayUno!=NULL && len >=0)
	{
		for(i=0;i<len;i++)
			{
				dia=i+1;
				printf("Pos.(%d) - valor: %d\n",dia, pArrayUno[i]);
			}
	}
	else
	{
		printf("No existe nada para imprimir");
	}
}

/**
 * @brief void inicalizarArray(int[], int)
 * 		  inicializa todas las posiciones de un array, en este caso del tipo int
 *
 * @param pArrayUno esta es la direccion de memoria del array
 * @param len es la cantidad de posiciones del array
 * @param valorIninial es el valor que tendra cada posicion del array
 */

void inicializarArray(int pArrayUno[], int len, float valorIninial)
{
	int i;

		if(pArrayUno!=NULL)
		{
			for(i=0;i<len;i++)
				{
					pArrayUno[i]=valorIninial;
				}
		}
		else
		{
			printf("No existe nada para imprimir");
		}
}

/**
 * @brief void cargarNumerosEnArray(int[], int)
 * 		  inicializa todas las posiciones de un array, en este caso del tipo int
 *
 * @param pArrayUno esta es la direccion de memoria del array
 * @param len es la cantidad de posiciones del array
 */

void cargarNumerosEnArray(int arrayNum[], int len)
{
	int aux;
	int r;
	int i;
	int pos=0;

	for(i=0;i<len;i++)
	{
		r = pedirIntAUsuario(&aux,1,5,2, "Por favor ingrese un numero: ", "Error!");
		system("cls");
			if(r==0)
				{
					arrayNum[pos]=aux;
					printf("Se cargo correctamente!\n");
					pos++;
				}
					else
						{
							printf("Se produjo un error!\n");
						}
							printf("El numero elegido fue: %d\n",aux);
							printf("*************************\n");

	}

}
