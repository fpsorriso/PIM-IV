/*
 * Util.c
 *
 *  Created on: 20 de nov de 2018
 *      Author: sorriso
 */

#include "../def/Util.h"
#include <stdio.h>
#include <string.h>

/**
 * Nao valida caracter de final de texto.
 */
int char_IsCaracterControle(char caracter) {
	switch (caracter) {
	case '\n':
	case '\t':
	case '\r':
	case ' ':
		return 1;
	default:
		return 0;
	}
}

void strCopy(char* source, char* destine) {
	while (*source != '\0') {
		*destine = *source;
		++destine;
		++source;
	}

	*destine = '\0';
}

char* strSubstr(char* str, int indexInicial, int quantidadeCaracteres) {
	int sizeStrOriginal = strlen(str);
	int quantidadeCaracteresCopiar = quantidadeCaracteres > sizeStrOriginal ? sizeStrOriginal : quantidadeCaracteres;
	char* result = (char*) calloc(quantidadeCaracteresCopiar == 0 ? 1 : quantidadeCaracteresCopiar, sizeof(char));

	if (str != NULL && strlen(str) > 0 && quantidadeCaracteres > 0 && indexInicial > -1) {
		for (int i = 0; i < quantidadeCaracteresCopiar; i++) {
			result[i] = str[i + indexInicial];
		}
	}

	return result;
}

char* strRTrim(char* str) {
	if (str != NULL && strlen(str) > 0) {
		int strSizeOriginal = strlen(str);
		int i = strSizeOriginal;

		while (i > -1) {
			if (char_IsCaracterControle(str[i - 1])) {
				i--;
				continue;
			}

			break;
		}

		if (i < strSizeOriginal) {
			return strSubstr(str, 0, i);
		}
	}

	return str;
}

char* strLTrim(char* str) {
	if (str != NULL && strlen(str) > 0) {
		int strSizeOriginal = strlen(str);
		int i = 0;

		while (str[i] != '\0') {
			if (char_IsCaracterControle(str[i])) {
				i++;
				continue;
			}

			break;
		}

		if (i > 0) {
			return strSubstr(str, i, strSizeOriginal - i);
		}
	}

	return str;

}

char* strTrim(char* str) {
	if (str != NULL && strlen(str) > 0) {
		char* l = strLTrim(str);
		char* result = strRTrim(l);

		if (l != NULL && l != str) {
			free(l);
		}

		return result;
	}

	return str;
}

int strIsEmpty(char* str) {
	if (str != NULL) {
		char* t = strTrim(str);
		int result = strlen(t) == 0;

		return result;
	}

	return 0;
}
