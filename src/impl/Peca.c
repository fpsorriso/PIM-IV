/*
 * Peca.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include "../def/Peca.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/cexcept.h"
#include "../def/Constantes.h"

#define _SIZE_TITULO 50

int peca_isNull(Peca *peca) {
	if (peca == NULL) {
		return 1;
	}

	return 0;
}

Peca* peca_novo(int id, char *titulo) {
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
	printf("\n[Peca] %d - %s", peca_getId(peca), peca_getTitulo(peca));
}

void peca_cadastro(Peca* peca) {
	if (peca_isNull(peca)) {

		int novoIdPeca = 1;
		char titulo[_SIZE_TITULO];
		char opcao;

		do {
			strcmp(titulo, "\0");
			opcao = '\0';


			__fpurge(stdin);
			printf("\nInforme o titulo da Pe\u00E7a:");
			Try {
			scanf ( strcat(strcat("%", _SIZE_TITULO), "[^\n]"), titulo);
			} Catch(e) {
				Throw e;
			}

			if (strlen(titulo) == 0) {
				printf(strcat(strcat("\n", _CAMPO_OBRIGATORIO), ".%s"), "Titulo", _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &opcao);
			}

		} while(strlen(titulo) == 0 && opcao == 's');

		if (strlen(titulo) == 0) {
			Throw("\nN\u00E3o poss\u00EDvel realizar o cadastro do Pe\u00E7a.");
			return;
		}

		peca = peca_novo(novoIdPeca, titulo);
	} else {
		Throw("\nPe\u00E7a j\u00E1 cadastrada.");
		peca_print(peca);
	}
}
