/*
 * Teatro.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include "../def/Teatro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../def/Constante.h"

int teatro_isNull(Teatro *pTeatro){
	if (pTeatro == NULL) {
		return 1;
	}

	return 0;
}

Teatro* teatro_novo(int id, int capacidade) {
	Teatro* vTeatro = (Teatro *) calloc(1, sizeof(Teatro));

	if (vTeatro == NULL) {
		error(0, _ERROR_CODE_MEMORIA_INSUFICIENTE, _EXCEPTION_MEMORIA_INSUFICIENTE);
		return NULL;
	}

	vTeatro->capacidade = capacidade;

	return vTeatro;
}

int teatro_getCapacidade(Teatro *pTeatro) {
	if (!teatro_isNull(pTeatro)) {
		return (int) pTeatro->capacidade;
	}

	return 0;
}

void teatro_setCapacidade(Teatro *pTeatro, int capacidade) {
	if (!teatro_isNull(pTeatro)) {
		pTeatro->capacidade = capacidade;
	}
}


void teatro_print(Teatro* pTeatro) {
	printf("\n[Teatro] %d", teatro_getId(pTeatro));
}

Teatro* teatro_cadastra(Teatro* pTeatro) {
	int vCapacidade;
	int vNovoIdTeatro = 1;
	char vOpcao;

	if (teatro_isNull(pTeatro)) {
		do {
			vCapacidade = 0;
			vOpcao = '\0';
			printf("\nInformar a lota\u00E7\u00E3o do Teatro:");
			scanf("%d", &vCapacidade);

			if (vCapacidade == 0) {
				fprintf(stderr, _EXCEPTION_CAMPO_OBRIGATORIO, "lota\u00E7\u00E3o");
				fprintf(stderr, " %s", _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &vOpcao);
				vCapacidade = 0;
			}

		} while (vCapacidade == 0 && vOpcao == 's');

		if (vCapacidade == 0) {
			fprintf(stderr, _EXCEPTION_IMPOSSIVEL_CADASTRAR, "do Teatro");
			return NULL;
		}

		return teatro_novo(vNovoIdTeatro, vCapacidade);

	} else {
		fprintf(stderr, _EXCEPTION_CADASTRO_JA_EXISTENTE, " do Teatro");
		teatro_print(pTeatro);
		return pTeatro;
	}
}
