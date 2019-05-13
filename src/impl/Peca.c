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

int peca_isNull(Peca* pPeca) {
	if (pPeca == NULL) {
		return 1;
	}

	return 0;
}

Peca* peca_novo(Teatro pTeatro, char* pTitulo, double pValorIngresso) {
	Peca *vPeca = (Peca*) calloc(1, sizeof(Peca));

	if (vPeca == NULL) {
		printf("Ocorreu o um erro ao tentar criar uma nova pe\u00E7a. %d - %s",
            _ERROR_CODE_MEMORIA_INSUFICIENTE, _EXCEPTION_MEMORIA_INSUFICIENTE);
		return NULL;
	}

	vPeca->teatro = pTeatro;
	vPeca->titulo = pTitulo;
	vPeca->valorIngresso = pValorIngresso;

	return vPeca;
}

Teatro peca_getTeatro(Peca pPeca) {
	Teatro vResult;

	if (!peca_isNull(&pPeca)) {
		vResult = pPeca.teatro;
	}

	return vResult;
}

char* peca_getTitulo(Peca pPeca) {
	if (!peca_isNull(&pPeca)) {
		return pPeca.titulo;
	}

	return calloc(1, sizeof(char));
}

void peca_setTitulo(Peca* pPeca, char* pTitulo) {
	if (!peca_isNull(pPeca)) {
		strCopy(pTitulo, pPeca->titulo);
	}
}

double peca_getValorIngresso(Peca pPeca) {
	if (!peca_isNull(&pPeca)) {
		return pPeca.valorIngresso;
	}

	return 0.00;
}

void peca_setValorIngresso(Peca* pPeca, double pValorIngresso) {
	if (!pPeca_isNull(pPeca)) {
		pPeca->valorIngresso = pValorIngresso;
	}
}

void peca_print(Peca pPeca) {
	printf("\n[Peca] %d - %s", peca_getId(pPeca), peca_getTitulo(pPeca));
}

double informarValorIngresso() {
	char vOpcao;
	double vValorIngresso;

	do {
		vOpcao = '\0';
		vValorIngresso = 0.00;
		printf("\nInforme o valor do ingresso: ");
		scanf(" %2lf", &vValorIngresso);

		if (vValorIngresso == 0) {
			fprintf(stderr, _EXCEPTION_CAMPO_OBRIGATORIO, "Valor do Ingresso");
			fprintf(stderr, " ");
			fprintf(stderr, _MENSAGEM_INFORMAR_NOVAMENTE);
			scanf(" %c", &vOpcao);
		}
	} while (vValorIngresso == 0 && vOpcao == 's');

	return vValorIngresso;
}

Peca* peca_cadastro(Teatro pTeatro) {
	if (!teatro_isNull(&pTeatro)) {

		int vNovoIdPeca = 1;
		char vTitulo[_SIZE_TITULO];
		char vOpcao;

		do {
			vTitulo[0] = '\0';
			vOpcao = '\0';

			__fpurge(stdin);
			printf("\nInforme o titulo da Pe\u00E7a:");
			fgets(vTitulo, _SIZE_TITULO, stdin);


			if (strIsEmpty(vTitulo)) {
				fprintf(stderr, _EXCEPTION_CAMPO_OBRIGATORIO, "Titulo");
				fprintf(stderr, " ");
				fprintf(stderr, _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &vOpcao);
			}

		} while(strIsEmpty(vTitulo) && vOpcao == 's');

		if (strlen(vTitulo) == 0) {
			fprintf(stderr, _ERROR_CODE_IMPOSSIVEL_CADASTRAR, "da Pe\u00E7a");
			return NULL;
		}

		double vValorIngresso = informarValorIngresso();

		if (vValorIngresso == 0) {
				fprintf(stderr, _EXCEPTION_IMPOSSIVEL_CADASTRAR, "da Sess\u00E3o");
				return NULL;
		}

		return peca_novo(pTeatro, vTitulo, vValorIngresso);
	} else {
		fprintf(stderr, _EXCEPTION_CADASTRO_JA_EXISTENTE, "Pe\u00E7a");
		return NULL;
	}
}
