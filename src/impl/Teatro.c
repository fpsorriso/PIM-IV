/*
 * Teatro.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */
#include "../def/Teatro.h"
#include "../def/Constantes.h"

#include <stdio.h>

int teatro_isNull(Teatro *teatro) {
	if (teatro == NULL) {
		return 1;
	}

	return 0;
}

Teatro *teatro_novo(int id, int capacidade) {
	Teatro *teatro = (Teatro *) calloc(1, sizeof *teatro);

	if (teatro == NULL) {
		throwStackOverFlowException();
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
	printf("\n[Teatro] %d", teatro_getId(teatro));
}

void teatro_cadastra(Teatro* teatro) {
	int capacidade;
	int novoIdTeatro = 1;
	char opcao;

	if (teatro_isNull(teatro)) {
		do {
			capacidade = 0;
			opcao = '\0';
			printf("\nInformar a lota\u00E7\u00E3o do Teatro:");
			scanf("%d", &capacidade);

			if (capacidade == 0) {
				throwExceptionWithParam("\nA lota\u00E7\u00E3o do Teatro deve ser maior do que Zero. %s", _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &opcao);
				capacidade = 0;
			}

		} while (capacidade ==0 && opcao == 's');

		if (capacidade == 0) {
			printf("\nN\u00E3o poss\u00EDvel realizar o cadastro do Teatro.");
			return;
		}

		teatro = teatro_novo(novoIdTeatro, capacidade);

	} else {
		throwException("\nTeatro j\u00E1 cadastrado.");
		teatro_print(teatro);
	}
}
