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

Teatro teatroVazio() {
	Teatro vTeatroVazio;
	vTeatroVazio.capacidade = 0;
	return vTeatroVazio;
}

int teatroIsNull(Teatro pTeatro) {
	if (&pTeatro == NULL) {
		return 1;
	}

	return 0;
}

Teatro teatroNovo(int id, int capacidade) {
	Teatro vTeatro;
	vTeatro.capacidade = capacidade;

	return vTeatro;
}

int teatroGetCapacidade(Teatro pTeatro) {
	if (!teatroIsNull(pTeatro)) {
		return (int) pTeatro->capacidade;
	}

	return 0;
}

void teatroSetCapacidade(Teatro pTeatro, int capacidade) {
	if (!teatroIsNull(pTeatro)) {
		pTeatro->capacidade = capacidade;
	}
}

void teatroPrint(Teatro pTeatro) {
	printf("\n[Teatro] %d", teatro_getId(pTeatro));
}

Teatro teatroCadastra() {
	int vCapacidade;
	char vOpcao;

	do {
		vCapacidade = 0;
		vOpcao = '\0';
		printf("\nInformar a lota\u00E7\u00E3o do Teatro:");
		scanf("%d", &vCapacidade);

		if (vCapacidade == 0) {
			printf(_EXCEPTION_CAMPO_OBRIGATORIO, "lota\u00E7\u00E3o");
			printf(" %s", _MENSAGEM_INFORMAR_NOVAMENTE);
			scanf("%s", &vOpcao);
			vCapacidade = 0;
		}

	} while (vCapacidade == 0 && vOpcao == 's');

	if (vCapacidade == 0) {
		printf(_EXCEPTION_IMPOSSIVEL_CADASTRAR, "do Teatro");
		return teatroVazio();
	}

	return teatroNovo(vCapacidade);
}
