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

int pecaIsNull(Peca pPeca) {
	if (&pPeca == NULL) {
		return 1;
	}

	return 0;
}

Peca pecaVazia() {
	Peca vPecaVazia;
	vPecaVazia.teatro = teatroVazio();
	vPecaVazia.titulo = "\0";
	vPecaVazia.valorIngresso = 0.00;

	return vPecaVazia;
}

Peca pecaNova(Teatro pTeatro, char* pTitulo, double pValorIngresso) {
	Peca vPeca;

	vPeca.teatro = pTeatro;
	vPeca.titulo = pTitulo;
	vPeca.valorIngresso = pValorIngresso;

	return vPeca;
}

Teatro pecaGetTeatro(Peca pPeca) {
	if (!pecaIsNull(pPeca)) {
		return pPeca.teatro;
	}

	return teatroVazio();
}

char* pecaGetTitulo(Peca pPeca) {
	if (!pecaIsNull(pPeca)) {
		return pPeca.titulo;
	}

	return calloc(1, sizeof(char));
}

void pecaSetTitulo(Peca pPeca, char* pTitulo) {
	if (!pecaIsNull(pPeca)) {
		strCopy(pTitulo, pPeca.titulo);
	}
}

double pecaGetValorIngresso(Peca pPeca) {
	if (!pecaIsNull(pPeca)) {
		return pPeca.valorIngresso;
	}

	return 0.00;
}

void pecaSetValorIngresso(Peca pPeca, double pValorIngresso) {
	if (!pPeca_isNull(pPeca)) {
		pPeca.valorIngresso = pValorIngresso;
	}
}

void pecaPrint(Peca pPeca) {
	printf("\n[Peca] %d - %s", peca_getId(pPeca), pecaGetTitulo(pPeca));
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
			printf(_EXCEPTION_CAMPO_OBRIGATORIO, "Valor do Ingresso");
			printf(_MENSAGEM_INFORMAR_NOVAMENTE);
			scanf(" %c", &vOpcao);
		}
	} while (vValorIngresso == 0 && vOpcao == 's');

	return vValorIngresso;
}

char* informarTitulo() {
	char vOpcao;
	char vTitulo[_SIZE_TITULO];

	do {
		vTitulo[0] = '\0';
		vOpcao = '\0';
		__fpurge(stdin);
		printf("\nInforme o titulo da Pe\u00E7a:");
		fgets(vTitulo, _SIZE_TITULO, stdin);

		if (strIsEmpty(vTitulo)) {
			printf(_EXCEPTION_CAMPO_OBRIGATORIO, "Titulo");
			printf(_MENSAGEM_INFORMAR_NOVAMENTE);
			scanf("%s", &vOpcao);
		}
	} while (strIsEmpty(vTitulo) && vOpcao == 's');

	return vTitulo;
}

Peca pecaCadastro(Teatro pTeatro) {
	if (!teatroIsNull(pTeatro)) {

		char vTitulo[_SIZE_TITULO] = '\0';
		double vValorIngresso = 0.00;

		vValorIngresso = informarValorIngresso();
        vTitulo = informarTitulo();

		if (strlen(vTitulo) == 0 || vValorIngresso == 0) {
			printf(_EXCEPTION_IMPOSSIVEL_CADASTRAR, "da Pe\u00E7a");
			return pecaVazia();
		}

		return pecaNova(pTeatro, vTitulo, vValorIngresso);
	} else {
		printf(_EXCEPTION_NULL_POINT, "Teatro");
		return pecaVazia();
	}
}
