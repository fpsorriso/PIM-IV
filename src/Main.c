/*
 * Main.c
 *
 *  Created on: 27 de out de 2018
 *      Author: sorriso
 */

#include <stdio.h>

#include "./def/LinkedList.h"
#include "./def/Peca.h"
#include "./def/Sessao.h"
#include "./def/Teatro.h"

int main() {
	LinkedList* listaSessao = NULL;
	LinkedList* listaVenda = NULL;
	Teatro* teatro = NULL;
	Peca* peca = NULL;

	teatro = teatro_cadastra(teatro);
	peca = peca_cadastro(peca);
	listaSessao = sessao_cadastra(listaSessao, teatro, peca);
	listaVenda = venda_cadastra(listaVenda, listaSessao);

	linkedList_dispose(listaSessao);
	linkedList_dispose(listaVenda);
	free(teatro);
	free(peca);
	printf("Sistema encerrado.");
	return(0);
}

