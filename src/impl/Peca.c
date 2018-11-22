/*
 * Peca.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include "../def/Peca.h"

#include <stdio.h>
#include <stdlib.h>

#include "../def/Util.h"
#include "../def/Constante.h"

#define _SIZE_TITULO 50

int peca_isNull(Peca *peca) {
	if (peca == NULL) {
		return 1;
	}

	return 0;
}

Peca* peca_novo(int id, char *titulo) {
	Peca *peca = malloc(sizeof(peca));

	if (peca == NULL) {
		error(0, _ERROR_CODE_MEMORIA_INSUFICIENTE, _EXCEPTION_MEMORIA_INSUFICIENTE);
		return NULL;
	}

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

void peca_setTitulo(Peca *peca, char* titulo) {
	if (!peca_isNull(peca)) {
		peca->titulo = titulo;
	}
}

void peca_print(Peca* peca) {
	printf("\n[Peca] %d - %s", peca_getId(peca), peca_getTitulo(peca));
}

Peca* peca_cadastro(Peca* peca) {
	if (peca_isNull(peca)) {

		int novoIdPeca = 1;
		char titulo[_SIZE_TITULO];
		char opcao;

		do {
			titulo[0] = '\0';
			opcao = '\0';

			__fpurge(stdin);
			printf("\nInforme o titulo da Pe\u00E7a:");
			fgets(titulo, _SIZE_TITULO, stdin);


			if (strIsEmpty(titulo)) {
				fprintf(stderr, _EXCEPTION_CAMPO_OBRIGATORIO, "Titulo");
				fprintf(stderr, " ");
				fprintf(stderr, _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &opcao);
			}

		} while(strIsEmpty(titulo) && opcao == 's');

		if (strlen(titulo) == 0) {
			fprintf(stderr, _ERROR_CODE_IMPOSSIVEL_CADASTRAR, "da Pe\u00E7a");
			return NULL;
		}

		return peca_novo(novoIdPeca, titulo);
	} else {
		fprintf(stderr, _EXCEPTION_CADASTRO_JA_EXISTENTE, "Pe\u00E7a");
		peca_print(peca);
		return peca;
	}
}
