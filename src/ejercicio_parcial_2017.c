/*
 ============================================================================
 Name        : ejercicio_parcial_2017.c
 Author      : Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#include "utn_biblioteca_arrays.h"
#include "Pantalla.h"
#define DISPLAYS_LEN 1


int main(void) {
	setbuf(stdout, NULL);
	int response;
	int res;
	int posDetected;


	Display displayList[DISPLAYS_LEN];

	disp_initList(displayList,DISPLAYS_LEN);
	do
	{
		pedirIntAUsuario(&response, 1, 6, 2, "Que desea realizar:\n-------------------\n\n\t1.Ingresar una pantalla\n\n\t2.Mostrar disponibilidad\n\n\t3.Mostrar pantallas contratadas\n\n\t4.Dar de baja una pantalla\n\n\t5.Limpiar pantalla\n\n\t6.Salir\n\n--------------> ","Error!");
		switch(response)
		{
		case 1:
			if(disp_searchEmpty(displayList,DISPLAYS_LEN,&posDetected)==0)
			{
				if(disp_loadDisplay(&displayList[posDetected])==0)
				{
					printf("\n\tProceso finalizado!\n\n");
				}
			}
			else
			{
				printf("\n\tPor el momento, no hay mas lugar para cargar pantallas\n\n");
			}
			break;
		case 2:
			printf("\n\tPantallas disponibles:\n\n");
			res = disp_showEmpty(displayList,DISPLAYS_LEN);
			if(res==0)
			{
				printf("\n\tNo existen pantallas disponibles por ahora\n\n");
			}
			else
			{
				printf("\t%d\n\n",res);
			}
			break;
		case 3:
			printf("\n\tPantallas contratadas:\n");
			if(disp_showEmpty(displayList,DISPLAYS_LEN)==DISPLAYS_LEN) // tener en cuenta aca que si devuelve 0 significa que no existen posiciones
			{
				printf("\n\tPor el momento no existen pantallas contratas\n\n");
			}
			else
			{
				disp_show(displayList,DISPLAYS_LEN);
			}

			break;
		case 4:
			printf("\tDar de baja pantalla(por id):\n");
			res = disp_showEmpty(displayList,DISPLAYS_LEN);
			if(res==DISPLAYS_LEN)
			{
				printf("\n\tNo se puede dar de baja ya que no existen pantallas contratadas\n\n");
			}
			else
			{
				if(disp_delete(displayList,DISPLAYS_LEN)==0)
				{
					printf("\n\tLa pantalla se encuentra nuevamente disponible para contratar!\n\n");
				}
				else
				{
					printf("\n\tNo se realizo la baja!\n\n");
				}
			}

			break;
		case 5:
			system("cls");
			break;
		}


	}while(response!=6);




	return EXIT_SUCCESS;
}




