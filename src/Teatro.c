/*
 * Teatro.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

typedef struct teatro {
	int id;
	int capacidade;
} Teatro;

int isTeatroNulo(Teatro teatro) {
	return teatro == NULL;
}

Teatro *criar(int id, int capacidade) {
	Teatro teatro = (Teatro *) malloc(sizeof(Teatro));
	teatro.id = id;
	teatro.capacidade = capacidade;

	return (Teatro *) teatro;
}

int getId(Teatro teatro) {
	if (!isTeatroNulo(teatro)) {
		return teatro.id;
	}

	return 0;
}

int getCapacidade(Teatro teatro) {
	if (!isTeatroNulo(teatro)) {
		return teatro.capacidade;
	}

	return 0;
}

void setCapacidade(Teatro *teatro, int capacidade) {
	if (!isTeatroNulo(teatro)) {
		teatro->capacidade = capacidade;
	}
}
