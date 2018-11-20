/*
 * Exceptions.c
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#include "../def/Exceptions.h"
#include <stdio.h>

int throwExceptionWithParam(char* mensagem, void **params) {
	printf(mensagem, params);
	return 0;
}

int throwException(char* mensagem) {
	printf(mensagem);
	return 0;
}

int throwNullPointException() {
	throwException("Opera\u00E7\u00E3o invalida. Objeto nulo");
	return 1;
}


int throwStackOverFlowException() {
	throwException("N\u00E3o foi poss\u00EDvel realizar o oper\u00E7\u00E3o, pois a mem\u00F3ria esta cheia.");
	return 0;
}
