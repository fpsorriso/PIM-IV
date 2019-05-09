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

int teatro_isNull(Teatro *pTeatro);

Teatro *teatro_novo(int capacidade);

int teatro_getCapacidade(Teatro *pTeatro);

void teatro_setCapacidade(Teatro *pTeatro, int capacidade);

void teatro_print(Teatro* pTeatro);

Teatro* teatro_cadastra(Teatro* pTeatro);

#endif /* _TEATRO_H_ */
