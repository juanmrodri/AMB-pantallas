/*
 * Hiring.c
 *
 *  Created on: 12 oct 2021
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Hiring.h"
#define EMPTY 1
#define OCCUP 0

static int dameUnIdNuevo(void);

int hire_initList(Hiring* hiringList, int len)
{
	int ret=-1;
	int i;

	if(hiringList!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			hiringList[i].flagEmpty = EMPTY;

		}
		ret=0;
	}

	return ret;
}

int hire_loadDisplay(Hiring* hiringList)
{
	int ret=-1;
	char cuit[64];
	int duration;
	char archiveName[128];

	if(pedirTextoUsuario(cuit, 64, 2, "\tPor favor ingrese el cuit: ", "\tSe produjo un error!\n")==0) // LCD 0 LED 1
	{
		if(pedirIntAUsuario(&duration, 1, 30, 2, "\n\tPor favor ingrese la duracion(dias): ", "\tSe produjo un error!\n")==0)
		{
			if(pedirTextoUsuario(archiveName, 128, 2, "\n\tPor favor ingrese el nombre del archivo de video: ", "\tSe produjo un error!\n")==0)
				{
					strncpy(hiringList->cuit,cuit,sizeof(hiringList->cuit));
					hiringList->id = dameUnIdNuevo();
					hiringList->duration = duration;
					strncpy(hiringList->archiveName,archiveName,sizeof(hiringList->archiveName));
					hiringList->flagEmpty=OCCUP;
					printf("\n\tSe cargo correctamente!\n");
					ret=0;
			   }
				else
				{
				ret=-1;
				}
		}
	}
	return ret;
}


int hire_searchEmpty(Hiring* hiringList, int len, int* pos)
{
	int ret=-1;

	if(hiringList!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(hiringList[i].flagEmpty==EMPTY)
				{
					*pos=i;
					ret=0;
					break;
				}
		}
	}

	return ret;
}

int hire_showEmpty(Hiring* hiringList, int len)
{
	int count=0;

	if(hiringList!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(hiringList[i].flagEmpty==EMPTY)
				{
					count++;
				}
		}
	}

	return count;
}

int hire_show(Hiring* hiringList, int len)
{
	int ret=-1;

	if(hiringList!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(hiringList[i].flagEmpty==OCCUP)
					{
						printf("\n************************************\n");
						printf("\tId contratacion: %d\n\n\tDuracion(dias): %d\n\n\tNombre de archivo cargado: %s\n\n",hiringList[i].id,hiringList[i].duration,hiringList[i].archiveName);
						ret=0;
					}
			}
		}

	return ret;
}

int hire_delete(Hiring* hiringList, int len)
{
	int ret=-1;
	int bufferId;
	int bufferResponse;
	if(hiringList!=NULL && len>0)
	{
		if(pedirIntAUsuario(&bufferId, 1, 5, 2, "\tPor favor, ingrese el ID de la pantalla que quiere modificar: ", "\tError!!!\n")==0)
			{
				for(int i=0; i<len;i++)
				{
					if(hiringList[i].id==bufferId)
					{
						printf("\tUsted esta por dar de baja: %s\n", hiringList[i].archiveName);
						if(pedirIntAUsuario(&bufferResponse, 0, 1, 2, "\tDesea continuar(0 si- 1 no)? ", "Error!!!\n")==0)
						{
							if(bufferResponse==0)
							{
								hiringList[i].flagEmpty=1; // lo cambio a libre!
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
