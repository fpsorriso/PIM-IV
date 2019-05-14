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

Peca pecaVazia();

int pecaIsNull(Peca peca);

Peca pecaNova(Teatro pTeatro, char* pTitulo, double pValorIngresso);

Teatro pecaGetTeatro(Peca peca);

char* pecaGetTitulo(Peca peca);

void pecaSetTitulo(Peca pPeca, char* pTitulo);

double pecaGetValorIngresso(Peca peca);

void pecaSetValorIngresso(Peca peca, double valorIngresso);

void pecaPrint(Peca peca);

Peca pecaCadastro(Teatro pTeatro);

#endif /* _PECA_H_ */
