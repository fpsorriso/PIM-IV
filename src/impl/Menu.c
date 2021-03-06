/*
 * Menu.c
 *
 *  Created on: 22 de nov de 2018
 *      Author: sorriso
 */

#include "../def/Menu.h"

#include <stdio.h>
#include <string.h>

#include "../def/Util.h"

#define _TAMANHO_MENU 40

#define _CADASTRO_TEATRO 1
#define _CADASTRO_PECA 2
#define _CADASTRO_SESSAO 3
#define _OPERACAO_VENDA_INGRESSO 4
#define _RELATORIO_FECHAMENTO_CAIXA 5
#define _SAIR 6

void imprimeBarraSimples(int tamanhoBarra) {
	for (int col = 0; col < tamanhoBarra; col++) {
		printf("-");
	}
}

void imprimeBarraDupla(int tamanhoBarra) {
	for (int line = 0; line < 2; line++) {
		imprimeBarraSimples(tamanhoBarra);
		printf("\n");
	}
}

void imprimeTextoCentralizado(int tamanhoBarra, char* texto) {
	if (!strIsEmpty(texto)) {
		int tamanhoTexto = strlen(strTrim(texto));

		if (tamanhoBarra > 1) {
			int meio = (tamanhoBarra - tamanhoTexto) / 2;

			for (int col = 0; col <= meio; col++) {
				printf(" ");
			}
		}

		printf("%s", texto);
	}
}

void imprimeCabecalho(int tamanhoBarra, char* texto) {
	imprimeBarraDupla(tamanhoBarra);

	if (!strIsEmpty(texto)) {
		imprimeTextoCentralizado(tamanhoBarra, texto);
		printf("\n");
		imprimeBarraSimples(tamanhoBarra);
	}
}

void imprimeMenu(int tamanhoMenu) {
	imprimeCabecalho(tamanhoMenu, "MENU PRINCIPAL");

	printf("\nCADASTRO\n");
	imprimeBarraSimples(tamanhoMenu);
	printf("\n\t%d - TEATRO", _CADASTRO_TEATRO);
	printf("\n\t%d - PE\u00C7A", _CADASTRO_PECA);
	printf("\n\t%d - SESS\u00C3O\n", _CADASTRO_SESSAO);
	imprimeBarraSimples(tamanhoMenu);
	printf("\nOPERA\u00C7\u00C3O\n");
	imprimeBarraSimples(tamanhoMenu);
	printf("\n\t%d - VENDA DE INGRESSO\n", _OPERACAO_VENDA_INGRESSO);
	imprimeBarraSimples(tamanhoMenu);
	printf("\nRELATORIO\n");
	imprimeBarraSimples(tamanhoMenu);
	printf("\n\t%d - FECHAMENTO DE CAIXA\n", _RELATORIO_FECHAMENTO_CAIXA);
	imprimeBarraSimples(tamanhoMenu);
	printf("\nSAIR - %d", _SAIR);
	printf("\n");
	imprimeBarraDupla(tamanhoMenu);
	printf("Informe a op\u00E7\u00E3o desejada:");
}

void cadastro_teatro(int tamanhoMenu) {
	imprimeCabecalho(tamanhoMenu, "CADASTRO DO TEATRO");
}

void cadastro_peca(int tamanhoMenu) {
	imprimeCabecalho(tamanhoMenu, "CADASTRO DA PE\u00C7A");
}

void cadastro_sessao(int tamanhoMenu) {
	imprimeCabecalho(tamanhoMenu, "CADASTRO DA SESS\u00C3O");
}

void relatorio_fechamentoCaixa(int tamanhoMenu) {

}

void operacao_vendaIngresso(int tamanhoMenu) {

}

void executaOpcao(int tamanhoMenu, int opcao) {
	switch (opcao) {
		case _CADASTRO_TEATRO: {
			cadastro_teatro(tamanhoMenu);
			teatroCadastra();
			break;
		}
		case _CADASTRO_PECA: {
			cadastro_peca(tamanhoMenu);
			pecaCadastro();
			break;
		}

		case _CADASTRO_SESSAO: {
			cadastro_sessao(tamanhoMenu);
			break;
		}

		case _OPERACAO_VENDA_INGRESSO: {
			operacao_vendaIngresso(tamanhoMenu);
			break;
		}

		case _RELATORIO_FECHAMENTO_CAIXA: {
			relatorio_fechamentoCaixa(tamanhoMenu);
			break;
		}

		case _SAIR: {
			break;
		}

		default: {
			printf(stderr, "Op\u00E7\u00E3o invalida.");
			break;
		}
	}
}

void clear() {
    for (int i = 0; i< 50; i++) {
        printf("\n");
    }
}

void exibeMenuPrincipal() {
	int opcaoMenu = 0;

	do {
		opcaoMenu = 0;
		clear();
		imprimeMenu(_TAMANHO_MENU);
		scanf("%d", &opcaoMenu);
		executaOpcao(_TAMANHO_MENU, opcaoMenu);
	} while (opcaoMenu != _SAIR);
}
