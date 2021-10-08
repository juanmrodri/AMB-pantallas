/*
 * Pantalla.c
 *
 *  Created on: 30 sept 2021
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Pantalla.h"
#define EMPTY 1
#define OCCUP 0

static int dameUnIdNuevo(void);

/// @fn int disp_initList(Display displayList[], int len)
/// @param displayList recibe el puntero del array de estructura
/// @param len tamaño del array
/// @return -1 error o 0 ok!
int disp_initList(Display displayList[], int len)
{
	int ret=-1;
	int i;

	if(displayList!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			displayList[i].flagEmpty = EMPTY;

		}
		ret=0;
	}

	return ret;
}
/// @fn int disp_loadDisplay(Display*)
/// @param pDisplay recibe el puntero del array de estructura
/// @return -1 error 0 ok!
int disp_loadDisplay(Display* pDisplay)
{
	int ret=-1;
	int type;
	float price;
	char name[128];
	char address[128];

	if(pedirIntAUsuario(&type, 0, 1, 2, "\tPor favor ingrese el tipo: LCD 0 - LED 1: ", "\tSe produjo un error!\n")==0) // LCD 0 LED 1
	{
		if(pedirFloatAUsuario(&price, 1500, 85000, 2, "\n\tPor favor ingrese el precio: ", "\tSe produjo un error!\n")==0)
		{
			if(pedirTextoUsuario(name, 128, 2, "\n\tPor favor ingrese el nombre: ", "\tSe produjo un error!\n")==0)
				{
					if(pedirTextoUsuario(address, 128, 2, "\n\tPor favor ingrese el la direccion: ", "\tSe produjo un error!\n")==0)
					{
						printf("\n\tSe cargo correctamente!\n");
						pDisplay->type = type;
						pDisplay->price = price;
						pDisplay->id = dameUnIdNuevo();
						strncpy(pDisplay->name,name,sizeof(pDisplay->name));
						strncpy(pDisplay->address,address,sizeof(pDisplay->address));
						pDisplay->flagEmpty=OCCUP;
						ret=0;
					}
					else
					{
						ret=-1;
					}
			   }
		}
	}

	return ret;
}

/// @fn int disp_searchEmpty(Display* pDisplay, int len)
/// @param pDisplay puntero del array de estructuras
/// @param len tamaño del array
/// @return retorna un estado -1 error , i para devolver la posicion libre
int disp_searchEmpty(Display* pDisplay, int len, int* pos)
{
	int ret=-1;

	if(pDisplay!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pDisplay[i].flagEmpty==EMPTY)
				{
					*pos=i;
					ret=0;
					break;
				}
		}
	}

	return ret;
}

/// @fn int disp_showEmpty(Display* pDisplay, int len)
/// @param pDisplay puntero del array de estructuras
/// @param len tamaño del array
/// @return retorna un entero que representa la cantidad de pantallas disponibles
int disp_showEmpty(Display* pDisplay, int len)
{
	int count=0;

	if(pDisplay!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pDisplay[i].flagEmpty==EMPTY)
				{
					count++;
				}
		}
	}

	return count;
}

/// @fn int disp_show(Display* pDisplay, int len)
/// @param pDisplay puntero del array de estructuras
/// @param len tamaño del array
/// @return -1 error 0 ok!
int disp_show(Display* pDisplay, int len)
{
	int ret=-1;

	if(pDisplay!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(pDisplay[i].flagEmpty==OCCUP)
					{
						printf("\n************************************\n");
						printf("\tTipo: %d\n\tPrecio: %.2f\n\tID: %d\n\tNombre: %s\n\tDireccion: %s\n\n",pDisplay[i].type,pDisplay[i].price,pDisplay[i].id,pDisplay[i].name,pDisplay[i].address);
						ret=0;
					}
			}
		}

	return ret;
}

/// @fn int disp_delete(Display* pDisplay, int le)
/// @param pDisplay
/// @param len
/// @return -1 error 0 ok!
int disp_delete(Display* pDisplay, int len)
{
	int ret=-1;
	int bufferId;
	int bufferResponse;
	if(pDisplay!=NULL && len>0)
	{
		if(pedirIntAUsuario(&bufferId, 1, 5, 2, "\tPor favor, ingrese el ID de la pantalla que quiere modificar: ", "\tError!!!\n")==0)
			{
				for(int i=0; i<len;i++)
				{
					if(pDisplay[i].id==bufferId)
					{
						printf("\tUsted esta por dar de baja: %s\n", pDisplay[i].name);
						if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\tDesea continuar(0 si- 1 no)? ", "Error!!!\n")==0)
						{
							if(bufferResponse==0)
							{
								pDisplay[i].flagEmpty=1; // lo cambio a libre!
								ret=0;
								printf("\n\tEl dato fue dado de baja!!!\n");
							}
							else
							{
								// estuvo de acuerdo pero existe esta instancia donde puede fallar y no darse de baja
								printf("\n\tNo se realizara la modificacion!\n");
							}

						}
						else
						{
							// no esta de acuerdo
							printf("\n\tNo se realizara la modificacion!\n");
						}
					}
				}


			}
	}
	else
	{
		printf("\n\tLos datos no pudieron ser leidos");
	}

	return ret;

}

static int dameUnIdNuevo(void)
{
	static int contador=1;
	return contador++; // preferible ponerle () para que no tenga en cuenta el numero anterior y quede desfazado
}
