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

Teatro teatroEmpty() {
	Teatro vTeatroVazio;
	vTeatroVazio.capacidade = 0;
	return vTeatroVazio;
}

Teatro teatroNew(int capacidade) {
	Teatro vTeatro;
	vTeatro.capacidade = capacidade;

	return vTeatro;
}

int teatroGetCapacidade(Teatro pTeatro) {
	return pTeatro.capacidade;
}

void teatroSetCapacidade(Teatro pTeatro, int capacidade) {
	pTeatro.capacidade = capacidade;
}

void teatroPrint(Teatro pTeatro) {
	printf("\n[Teatro] Total de acentos: %d", teatroGetCapacidade(pTeatro));
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
		return teatroEmpty();
	}

	return teatroNew(vCapacidade);
}
