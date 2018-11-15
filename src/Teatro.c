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

int isTeatroNulo(Teatro *teatro) {
	if (*teatro == NULL) {
		return 1;
	}

	return 0;
}

Teatro* criar(int id, int capacidade) {
	Teatro *teatro = malloc(sizeof *teatro);
	teatro->id = id;
	teatro->capacidade = capacidade;

	return *teatro;
}

int getId(Teatro *teatro) {
	if (!isTeatroNulo(teatro)) {
		return (int) teatro->id;
	}

	return 0;
}

int getCapacidade(Teatro *teatro) {
	if (!isTeatroNulo(teatro)) {
		return (int) teatro->capacidade;
	}

	return 0;
}

void setCapacidade(Teatro *teatro, int capacidade) {
	if (!isTeatroNulo(teatro)) {
		teatro->capacidade = capacidade;
	}
}
