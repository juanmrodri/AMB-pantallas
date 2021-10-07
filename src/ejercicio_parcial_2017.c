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
#define DISPLAYS_LEN 2


int main(void) {
	setbuf(stdout, NULL);
	int response;
	int res;
	int posDetected;


	Display displayList[DISPLAYS_LEN];


/*
	displayList[0].id=1;
	displayList[0].price=20000;
	displayList[0]->name="Pantalla Samsung";
	displayList[0].address="Av. Callao y Guido";
	displayList[0].flagEmpty=0;
	displayList[0].type=1;
*/
	disp_initList(displayList,DISPLAYS_LEN);
	do
	{
		pedirIntAUsuario(&response, 1, 6, 2, "Que desea realizar:\n-------------------\n\n\t1.Ingresar una pantalla\n\n\t2.Mostrar disponibilidad\n\n\t3.Mostrar pantallas contratadas\n\n\t4.Modificar dato\n\n\t5.Limpiar pantalla\n\n\t6.Salir\n\n--------------> ","Error!");
		switch(response)
		{
		case 1:
			if(disp_searchEmpty(displayList,DISPLAYS_LEN,&posDetected)==0)
			{
				if(disp_loadDisplay(&displayList[posDetected])==0)
				{
					printf("\nProceso finalizado!\n\n");
				}
			}
			else
			{
				printf("\nNo hay mas lugar para cargar\n\n");
			}
			break;
		case 2:
			printf("\nPantallas disponibles:\n\n");
			res = disp_showEmpty(displayList,DISPLAYS_LEN);
			printf("%d\n\n",res);
			break;
		case 3:
			printf("\tPantallas contratadas:\n");
			if(disp_showEmpty(displayList,DISPLAYS_LEN)==DISPLAYS_LEN) // tener en cuenta aca que si devuelve 0 significa que no existen posiciones
			{
				printf("\n\tNo existen pantallas contratas\n\n");
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
				printf("\n\tNo existen pantallas ingresadas\n\n");
			}
			else
			{
				disp_delete(displayList,DISPLAYS_LEN);
			}

			break;
		case 5:
			system("cls");
			break;
		}


	}while(response!=6);




	return EXIT_SUCCESS;
}




