/*
 * Teatro.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _TEATRO_H_
#define _TEATRO_H_

typedef struct {
	int capacidade;
} Teatro;

Teatro teatroEmpty();

Teatro teatroNew(int capacidade);

int teatroGetCapacidade(Teatro pTeatro);

void teatroSetCapacidade(Teatro pTeatro, int capacidade);

void teatroPrint(Teatro pTeatro);

Teatro teatroCadastra();

#endif /* _TEATRO_H_ */
