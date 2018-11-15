/*
 * Peca.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

struct peca {
	int id;
	char *titulo;
};

typedef struct peca Peca;

int isPecaNula(Peca *peca) {
	if (peca == NULL) {
		return 1;
	}

	return 0;
}

Peca *criar(int id, char *titulo) {
	Peca *peca = malloc(sizeof(peca));
	peca->id = id;
	peca->titulo = titulo;

	return peca;
}

int getId(Peca *peca) {
	if (!isPecaNula(peca)) {
		return peca->id;
	}

	return 0;
}

char *getTitulo(Peca *peca) {
	if (!isPecaNula(peca)) {
		return peca->titulo;
	}

	return NULL;

}

void setTitulo(Peca *peca, char titulo[]) {
	if (!isPecaNula(peca)) {
		peca->titulo = titulo;
	}
}
