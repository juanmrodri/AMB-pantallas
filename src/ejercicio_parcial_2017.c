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
#include "Hiring.h"
#define DISPLAYS_LEN 100


int main(void) {
	setbuf(stdout, NULL);
	int response;
	int res;
	int posDetected;
	int hirePosDetected;
	int idDisplaySelected;

	Display displayList[DISPLAYS_LEN];
	Hiring hiringList[DISPLAYS_LEN];

	disp_initList(displayList,DISPLAYS_LEN);
	hire_initList(hiringList,DISPLAYS_LEN);
	do
	{
		pedirIntAUsuario(&response, 1, 9, 2, "Que desea realizar:\n-------------------\n\n\t1.Ingresar una pantalla\n\n\t2.Mostrar disponibilidad\n\n\t3.Mostrar pantallas ingresadas\n\n\t4.Dar de baja una pantalla\n\n\t5.Contratatar publicidad\n\n\t6.Mostrar contraciones\n\n\t7.Dar de baja contratacion\n\n\t8.Limpiar pantalla\n\n\t9.Salir\n\n--------------> ","Error!");
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
			printf("\n\tPantallas Ingresadas:\n");
			if(disp_showEmpty(displayList,DISPLAYS_LEN)==DISPLAYS_LEN) // tener en cuenta aca que si devuelve 0 significa que no existen posiciones
			{
				printf("\n\tPor el momento no existen pantallas ingresadas\n\n");
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
			// aca va la contratacion
			if(disp_showEmpty(displayList,DISPLAYS_LEN)==DISPLAYS_LEN) // tener en cuenta aca que si devuelve 0 significa que no existen posiciones
			{
					printf("\n\tPor el momento no existen pantallas ingresadas, por favor ingrese una para contratar una publicidad\n\n");
			}
			else
			{
				printf("\n\tPantallas disponibles:\n");
				disp_show(displayList,DISPLAYS_LEN); // aca mostramos las pantallas que estan ingresadas para que el usuario elija una
				if(pedirIntAUsuario(&idDisplaySelected, 1, 100, 2, "\tPor favor ingrese el id de la pantalla donde quiere publicitar: ", "Se produjo un error!\n")==0)
				{
					// ingreso correcto
					if(hire_searchEmpty(hiringList,DISPLAYS_LEN,&hirePosDetected)==0)
							{
							if(hire_loadDisplay(&hiringList[hirePosDetected])==0)
								{
									printf("\n\tProceso finalizado, publicidad contratada!\n\n");
								}
							}
							else
							{
									printf("\n\tPor el momento, no hay mas lugar para cargar pantallas\n\n");
							}
				}

		}
			break;
		case 6:
			if(disp_showEmpty(displayList,DISPLAYS_LEN)==DISPLAYS_LEN) // tener en cuenta aca que si devuelve 0 significa que no existen posiciones
			{
					printf("\n\tPor el momento no existen pantallas ingresadas, por favor ingrese una para contratar\n\n");
			}
			else
			{
				// mostrar las contrataciones realizadas
						printf("\n\tPublicidades contratadas:\n");

				if(hire_showEmpty(hiringList,DISPLAYS_LEN)==DISPLAYS_LEN) // tener en cuenta aca que si devuelve 0 significa que no existen posiciones
				{
					printf("\n\tPor el momento no existen contrataciones\n\n");
				}
				else
				{
					hire_show(hiringList,DISPLAYS_LEN);
				}

			}

			break;

		case 7:
			printf("\tDar de baja contratacion(por id):\n");
						res = hire_showEmpty(hiringList,DISPLAYS_LEN);
						if(res==DISPLAYS_LEN)
						{
							printf("\n\tNo se puede dar de baja ya que no existen publicidades contratadas\n\n");
						}
						else
						{
							if(hire_delete(hiringList,DISPLAYS_LEN)==0)
							{
								printf("\n\tSe dio de baja la contratacion!\n\n");
							}
							else
							{
								printf("\n\tNo se realizo la baja!\n\n");
							}
						}

			break;

		case 8:
			system("cls");
			break;
		}


	}while(response!=9);




	return EXIT_SUCCESS;
}




