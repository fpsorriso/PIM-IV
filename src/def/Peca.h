/*
 * Peca.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _PECA_H_
#define _PECA_H_

struct peca {
	int id;
	char *titulo;
};

typedef struct peca Peca;

int peca_isNull(Peca *peca);

Peca* peca_novo(int id, char *titulo);

int peca_getId(Peca *peca);

char* peca_getTitulo(Peca *peca);

void peca_print(Peca* peca);

Peca* peca_cadastro(Peca* peca);

#endif /* _PECA_H_ */
