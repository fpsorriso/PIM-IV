/*
 * Peca.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

typedef struct peca {
	int id;
	char *titulo;
} Peca;

int isPecaNula(Peca peca) {
	return peca == NULL;
}

Peca *criar(int id, char *titulo) {
	Peca peca = (Peca *) malloc(sizeof(Peca));
	peca.id = id;
	peca.titulo = titulo;

	return (Peca *) peca;
}

int getId(Peca peca) {
	if (!isPecaNula(peca)) {
		return peca.id;
	}

	return 0;
}

char *getTitulo(Peca peca) {
	if (isPecaNula(peca)) {
		return (char *)peca.titulo;
	}

	return NULL;

}

void setTitulo(Peca *peca, char titulo[]) {
	if (!isPecaNula(peca)) {
		peca->titulo = titulo;
	}
}
