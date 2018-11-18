/*
 * Teatro.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */
#include <stdio.h>

struct teatro {
	int id;
	int capacidade;
};

typedef struct teatro Teatro;

int teatro_isNull(Teatro *teatro) {
	if (teatro == NULL) {
		return 1;
	}

	return 0;
}

Teatro *teatro_novo(int id, int capacidade) {
	Teatro *teatro = (Teatro *) calloc(1, sizeof *teatro);

	if (teatro == NULL) {
		throwStackOverFlowWithParam();
	}

	teatro->id = id;
	teatro->capacidade = capacidade;

	return (Teatro *) teatro;
}

int teatro_getId(Teatro *teatro) {
	if (!teatro_isNull(teatro)) {
		return (int) teatro->id;
	}

	return 0;
}

int teatro_getCapacidade(Teatro *teatro) {
	if (!teatro_isNull(teatro)) {
		return (int) teatro->capacidade;
	}

	return 0;
}

void teatro_setCapacidade(Teatro *teatro, int capacidade) {
	if (!teatro_isNull(teatro)) {
		teatro->capacidade = capacidade;
	}
}

int teatro_equals(Teatro *teatro, Teatro *outroTeatro) {
	if (!teatro_isNull(teatro) && !teatro_isNull(outroTeatro)) {
		return teatro->id == outroTeatro->id;
	}

	return teatro_isNull(teatro) && teatro_isNull(outroTeatro);
}

void teatro_print(Teatro* teatro) {
	printf("[Teatro] %d", teatro_getId(teatro));
}
