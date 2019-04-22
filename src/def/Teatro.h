/*
 * Teatro.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _TEATRO_H_
#define _TEATRO_H_

struct teatro {
	int capacidade;
};

typedef struct teatro Teatro;

int teatro_isNull(Teatro *teatro);

Teatro *teatro_novo(int capacidade);

int teatro_getCapacidade(Teatro *teatro);

void teatro_setCapacidade(Teatro *teatro, int capacidade);

void teatro_print(Teatro* teatro);

Teatro* teatro_cadastra(Teatro* teatro);

#endif /* _TEATRO_H_ */
