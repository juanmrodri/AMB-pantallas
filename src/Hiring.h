/*
 * hiring.h
 *
 *  Created on: 12 oct 2021
 *      Author: juanm
 */

#ifndef HIRING_H_
#define HIRING_H_

typedef struct
{
	int id;
	char cuit[64]; // lo guardo como char por los guiones
	int duration;
	char archiveName[128];
	int idDisplay;
	int flagEmpty; // 0: ocupado -- 1: vacio/libre

}Hiring;


int hire_initList(Hiring* hiringList, int len);

int hire_loadDisplay(Hiring* hiringList);

int hire_searchEmpty(Hiring* hiringList, int len, int* pos);

int hire_showEmpty(Hiring* hiringList, int len);

int hire_show(Hiring* hiringList, int len);

int hire_delete(Hiring* hiringList, int len);

#endif /* HIRING_H_ */
