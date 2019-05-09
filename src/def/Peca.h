/*
 * Peca.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _PECA_H_
#define _PECA_H_

#define _SIZE_TITULO 50
#include "Teatro.h"

typedef struct {
	Teatro teatro;
	char* titulo;
	double valorIngresso;
} Peca;

int peca_isNull(Peca* peca);

Peca* peca_novo(Teatro pTeatro, char* pTitulo, double pValorIngresso);

Teatro peca_getTeatro(Peca peca);

char* peca_getTitulo(Peca peca);

void peca_setTitulo(Peca* pPeca, char* pTitulo);

double peca_getValorIngresso(Peca peca);

void peca_setValorIngresso(Peca* peca, double valorIngresso);

void peca_print(Peca peca);

Peca* peca_cadastro(Peca* peca);

#endif /* _PECA_H_ */
