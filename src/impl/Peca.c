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

Peca pecaEmpty() {
	Peca vPecaVazia;
	vPecaVazia.teatro = teatroEmpty();
	vPecaVazia.titulo = "\0";
	vPecaVazia.valorIngresso = 0.00;

	return vPecaVazia;
}

Peca pecaNew(Teatro pTeatro, char* pTitulo, double pValorIngresso) {
	Peca vPeca;

	vPeca.teatro = pTeatro;
	vPeca.titulo = pTitulo;
	vPeca.valorIngresso = pValorIngresso;

	return vPeca;
}

Teatro pecaGetTeatro(Peca pPeca) {
	return pPeca.teatro;

}

char* pecaGetTitulo(Peca pPeca) {

	return pPeca.titulo;
}

void pecaSetTitulo(Peca pPeca, char* pTitulo) {
	strCopy(pTitulo, pPeca.titulo);
}
exibeMenuPrincipal
double pecaGetValorIngresso(Peca pPeca) {
	return pPeca.valorIngresso;
}

void pecaSetValorIngresso(Peca pPeca, double pValorIngresso) {
	pPeca.valorIngresso = pValorIngresso;
}

void pecaPrint(Peca pPeca) {
	printf("\n[Peca] %s", pecaGetTitulo(pPeca));
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
	char* vTitulo;
	double vValorIngresso = 0.00;

	vValorIngresso = informarValorIngresso();
	vTitulo = informarTitulo();

	if (strlen(vTitulo) == 0 || vValorIngresso == 0) {
		printf(_EXCEPTION_IMPOSSIVEL_CADASTRAR, "da Pe\u00E7a");
		return pecaEmpty();
	}

	return pecaNew(pTeatro, vTitulo, vValorIngresso);
}
