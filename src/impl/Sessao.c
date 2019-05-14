/*
 * Sessao.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include "../def/Sessao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../def/Constante.h"
#include "../def/Util.h"

int sessao_isNull(Sessao sessao) {
	if (&sessao == NULL) {
		return 1;
	}

	return 0;
}

int sessao_dataIsNull(Sessao sessao) {
	if (sessao.dataHora == (time_t) -1) {
		return 1;
	}

	return 0;
}


Peca sessao_getPeca(Sessao sessao) {
	if (!sessao_isNull(sessao)) {
		return sessao.peca;
	}

	return pecaNova(NULL, "", 0.00);
}

void sessao_setPeca(Sessao* sessao, Peca* peca) {
	if (!sessao_isNull(sessao)) {
		sessao->peca = *peca;
	}
}

time_t sessao_getDataHora(Sessao sessao) {
	if (!sessao_isNull(sessao)) {
		return sessao->dataHora;
	}

	return NULL;
}

char* sessao_getDataHoraStr(Sessao sessao) {
	char *result = calloc(1, sizeof(char));

	if (!sessao_isNull(sessao) && !sessao_dataIsNull(sessao)) {
		struct tm* data = localtime(&sessao->dataHora);
		strftime(result, sizeof(result), _ISO_DATE_TIME, data);
		free(data);
	}

	return (char *) result;
}

void sessao_setDataHora(Sessao* sessao, time_t dataHora) {
	if (!sessao_isNull(sessao)) {
		sessao->dataHora = dataHora;
	}
}

void sessao_setDataHoraStr(Sessao* sessao, char* dataHora) {
	if (!sessao_isNull(sessao)) {
		if (strlen(dataHora) > 0) {
			struct tm data;
			strptime(dataHora, _ISO_DATE_TIME, &data);
			sessao->dataHora = mktime(&data);
		} else {
			sessao->dataHora = (time_t) -1;
		}
	}
}

int sessao_isTercaFeira(Sessao sessao) {
	if (!sessao_isNull(sessao) && sessao->dataHora ) {
		struct tm *data = localtime(&sessao->dataHora);

		if (data->tm_wday == 2) {
			free(data);
			return 1;
		}

		free(data);
	}

	return 0;
}

Sessao sessao_nova(Peca* pPeca, char* pDataHora) {
	Sessao sessao = (Sessao*) calloc(1, sizeof(Sessao));

	if (&sessao == NULL) {
		printf(_EXCEPTION_MEMORIA_INSUFICIENTE);
		return NULL;
	}

	sessao.peca = pPeca;
	sessao_setDataHoraStr(sessao, pDataHora);

	return sessao;
}

static comparable* sessao_comparableId(Sessao* sessao, char* pDataHora) {
	return strcmp(sessao_getDataHoraStr(sessao), pDataHora);
}

Sessao* sessao_busca(LinkedList* pList, char* pDataHora) {
	Node* node = linkedList_search(pList, pDataHora, sessao_comparableId);

	if (node != NULL) {
		return (Sessao*) node->value;
	}

	return NULL;
}

void sessao_print(Sessao sessao) {
	pecaPrint(sessao.peca);
	printf("\n\t[Sess\u00E3o] %s - R$ %.2f", sessao_getDataHoraStr(sessao), pecaGetValorIngresso(sessao.peca));
}

LinkedList* sessao_cadastra(LinkedList* list, Peca* peca) {
	char dataHora[strlen(_ISO_DATE_TIME_VIEW)];
	double valorIngresso = 0;
	int novoIdSessao = linkedList_count(list) + 1;
	char opcao;

	if (pecaIsNull(peca)) {
		fprintf(stderr, _EXCEPTION_NULL_POINT, "A pe\00F7a");
		return list;
	}

	do {
		dataHora[0] = '\0';
		opcao = '\0';

		printf("Informe a data e hora da sess\u00E3o (%s):\n", _ISO_DATE_TIME_VIEW);
		fgets(dataHora, strlen(_ISO_DATE_TIME_VIEW) + 1, stdin);

		if (strIsEmpty(dataHora) || strlen(strTrim(dataHora)) != strlen(_ISO_DATE_TIME_VIEW)) {
			fprintf(stderr, _EXCEPTION_CAMPO_OBRIGATORIO, "Data e Hora");
			fprintf(stderr, " ");
			fprintf(stderr, _MENSAGEM_INFORMAR_NOVAMENTE);
			scanf(" %c", &opcao);
		}

	} while ((strIsEmpty(dataHora) || strlen(strTrim(dataHora)) != strlen(_ISO_DATE_TIME_VIEW)) && opcao == 's');

	if (strIsEmpty(dataHora)) {
		fprintf(stderr, _EXCEPTION_IMPOSSIVEL_CADASTRAR, "da Sess\u00E3o");
		return list;
	}

	return linkedList_put(sessao_nova(peca, dataHora), list);
}
