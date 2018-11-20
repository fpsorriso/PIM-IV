/*
 * Teatro.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _TEATRO_H_
#define _TEATRO_H_

struct teatro {
	int id;
	int capacidade;
};

typedef struct teatro Teatro;

int teatro_isNull(Teatro *teatro);

Teatro *teatro_novo(int id, int capacidade);

int teatro_getId(Teatro *teatro);

int teatro_getCapacidade(Teatro *teatro);

void teatro_setCapacidade(Teatro *teatro, int capacidade);

int teatro_equals(Teatro *teatro, Teatro *outroTeatro);

void teatro_print(Teatro* teatro);

void teatro_cadastra(Teatro* teatro);

#endif /* _TEATRO_H_ */
