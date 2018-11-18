/*
 * Peca.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include <stdlib.h>

struct peca {
	int id;
	char *titulo;
};

typedef struct peca Peca;

int peca_isNull(Peca *peca) {
	if (peca == NULL) {
		return 1;
	}

	return 0;
}

Peca *peca_novo(int id, char *titulo) {
	Peca *peca = malloc(sizeof(peca));
	peca->id = id;
	peca->titulo = titulo;

	return peca;
}

int peca_getId(Peca *peca) {
	if (!peca_isNull(peca)) {
		return peca->id;
	}

	return 0;
}

char* peca_getTitulo(Peca *peca) {
	if (!peca_isNull(peca)) {
		return peca->titulo;
	}

	return NULL;

}

void peca_setTitulo(Peca *peca, char titulo[]) {
	if (!peca_isNull(peca)) {
		peca->titulo = titulo;
	}
}

void peca_print(Peca* peca) {
	printf("[Peca] %d - %s", peca_getId(peca), peca_getTitulo(peca));
}
