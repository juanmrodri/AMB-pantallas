/*
 * Pantalla.h
 *
 *  Created on: 30 sept 2021
 *      Author: juanm
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_


typedef struct
{
	int type;
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; // 0: ocupado -- 1: vacio/libre

}Display;

int disp_initList(Display* displayList, int len);

int disp_loadDisplay(Display* pDisplay);

int disp_searchEmpty(Display* pDisplay, int len, int* pos);

int disp_showEmpty(Display* pDisplay, int len);

int disp_show(Display* pDisplay, int len);

int disp_delete(Display* pDisplay, int len);


#endif /* PANTALLA_H_ */
