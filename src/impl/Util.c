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
int char_IsCaracterControle(char pCaracter) {
	switch (pCaracter) {
	case '\n':
	case '\t':
	case '\r':
	case ' ':
		return 1;
	default:
		return 0;
	}
}

/**
 * Copia uma string para outra.
 */
void strCopy(char* pSource, char* pDestine) {
	while (*pSource != '\0') {
		*pDestine = *pSource;
		++pDestine;
		++pSource;
	}

	*pDestine = '\0';
}

/**
 * Copia uma perte da String
 */
char* strSubstr(char* pStr, int pIndexInicial, int pQuantidadeCaracteres) {
	int vSizeStrOriginal = strlen(pStr);
	int vQuantidadeCaracteresCopiar =
			pQuantidadeCaracteres > vSizeStrOriginal ?
					vSizeStrOriginal : pQuantidadeCaracteres;

	char* vResult = (char*) calloc(
			vQuantidadeCaracteresCopiar == 0 ? 1 : vQuantidadeCaracteresCopiar,
			sizeof(char));

	if (pStr != NULL && strlen(pStr) > 0 && pQuantidadeCaracteres > 0
			&& pIndexInicial > -1) {
		for (int i = 0; i < vQuantidadeCaracteresCopiar; i++) {
			vResult[i] = pStr[i + pIndexInicial];
		}
	}

	return vResult;
}

/**
 * Remove os espaços em branco do lado direito
 */
char* strRTrim(char* pStr) {
	if (pStr != NULL && strlen(pStr) > 0) {
		int strSizeOriginal = strlen(pStr);
		int i = strSizeOriginal;

		while (i > -1) {
			if (char_IsCaracterControle(pStr[i - 1])) {
				i--;
				continue;
			}

			break;
		}

		if (i < strSizeOriginal) {
			return strSubstr(pStr, 0, i);
		}
	}

	return pStr;
}

/**
 * Remove os espaços em branco do lado esquedo
 */
char* strLTrim(char* pStr) {
	if (pStr != NULL && strlen(pStr) > 0) {
		int strSizeOriginal = strlen(pStr);
		int i = 0;

		while (pStr[i] != '\0') {
			if (char_IsCaracterControle(pStr[i])) {
				i++;
				continue;
			}

			break;
		}

		if (i > 0) {
			return strSubstr(pStr, i, strSizeOriginal - i);
		}
	}

	return pStr;

}

/**
 * Remove os espaços em branco de ambos os lados
 */
char* strTrim(char* pStr) {
	if (pStr != NULL && strlen(pStr) > 0) {
		char* l = strLTrim(pStr);
		char* result = strRTrim(l);

		if (l != NULL && l != pStr) {
			free(l);
		}

		return result;
	}

	return pStr;
}

/**
 * Verifica se uma String esta vazia.
 */
int strIsEmpty(char* pStr) {
	if (pStr != NULL) {
		char* t = strTrim(pStr);
		int result = strlen(t) == 0;

		return result;
	}

	return 0;
}
