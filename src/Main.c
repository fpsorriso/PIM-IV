/*
 * Main.c
 *
 *  Created on: 27 de out de 2018
 *      Author: sorriso
 */

#include <stdio.h>

#include "def/Menu.h"

int main() {
	LinkedList* listaSessao = NULL;
	LinkedList* listaVenda = NULL;
	Teatro teatro = teatroEmpty();
	Peca peca = pecaEmpty();

	exibeMenuPrincipal();
	printf("\nSistema encerrado.");
	return(0);
}

