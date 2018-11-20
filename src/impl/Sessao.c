/*
 * Sessao.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include "../def/Sessao.h"
#include "../def/Constantes.h"
#include <time.h>
#include <stdlib.h>

int sessao_isNull(Sessao* sessao) {
	if (sessao == NULL) {
		return 1;
	}

	return 0;
}

int sessao_getId(Sessao* sessao) {
	if (!sessao_isNull(sessao)) {
		return (int) sessao->id;
	}

	return (int) 0;
}

Peca* sessao_getPeca(Sessao* sessao) {
	if (!sessao_isNull(sessao)) {
		return &sessao->peca;
	}

	return NULL;
}

void sessao_setPeca(Sessao* sessao, Peca* peca) {
	if (!sessao_isNull(sessao)) {
		sessao->peca = *peca;
	}
}

Teatro* sessao_getTeatro(Sessao* sessao) {
	if (!sessao_isNull(sessao)) {
		return &sessao->teatro;
	}

	return NULL;
}

void sessao_setTeatro(Sessao* sessao, Teatro* teatro) {
	if (!sessao_isNull(sessao)) {
		sessao->teatro = *teatro;
	}
}

time_t sessao_getDataHora(Sessao* sessao) {
	if (!sessao_isNull(sessao)) {
		return sessao->dataHora;
	}

	return NULL;
}

char* sessao_getDataHoraStr(Sessao* sessao) {
	char *result = (char *) malloc(30 * sizeof(char));

	if (!sessao_isNull(sessao) && sessao->dataHora != NULL) {
		struct tm *data = localtime((time_t *) sessao->dataHora);
		strftime(result, sizeof(result), _ISO_DATE_TIME, data);
		free(data);
	}

	return (char *) result;
}

void sessao_setDataHora(Sessao* sessao, time_t* dataHora) {
	if (!sessao_isNull(sessao)) {
		sessao->dataHora = &dataHora;
	}
}

void sessao_setDataHoraStr(Sessao* sessao, char* dataHora) {
	if (!sessao_isNull(sessao)) {
		if (strlen(dataHora) > 0) {
			struct tm *data;
			strptime(dataHora, _ISO_DATE_TIME, data);
			sessao->dataHora = mktemp(data);
			free(data);

		} else {
			sessao->dataHora = (time_t *) NULL;
		}
	}
}

double sessao_getValorIngresso(Sessao* sessao) {
	if (!sessao_isNull(sessao)) {
		return sessao->valorIngresso;
	}

	return 0.00;
}

void sessao_setValorIngresso(Sessao* sessao, double valorIngresso) {
	if (!sessao_isNull(sessao)) {
		sessao->valorIngresso = valorIngresso;
	}
}

//int sessao_equals(Sessao* sessao, Sessao* outraSessao) {
//	if (!sessao_isNull(sessao) && !sessao_isNull(outraSessao)) {
//		return sessao->id == outraSessao->id;
//	}
//
//	return sessao_isNull(sessao) && sessao_isNull(outraSessao);
//}

int sessao_isTercaFeira(Sessao* sessao) {
	if (!sessao_isNull(sessao) && sessao->dataHora != NULL) {
		struct tm *data = localtime((time_t) sessao->dataHora);

		if (data->tm_wday == 2) {
			free(data);
			return 1;
		}

		free(data);
	}

	return 0;
}

Sessao* sessao_nova(int id, Teatro* teatro, Peca* peca, char* dataHora, double valorIngresso) {
	Sessao* sessao = (Sessao*) calloc(1, sizeof(Sessao));

	if (sessao == NULL) {
		throwStackOverFlowException();
	}

	sessao->id = id;
	sessao->teatro = *teatro;
	sessao->peca = *peca;
	sessao->valorIngresso = valorIngresso;

	return sessao;
}

void sessao_cadastra(LinkedList* list, Teatro* teatro, Peca* peca) {
	char* dataHora = NULL;
	double valorIngresso = 0;
	int novoIdSessao = linkedList_count(list) + 1;

	if (teatro_isNull(teatro)) {
		throwException("\nO teatro não foi cadastrado para a sess\u00E3o.");
	}

	if (peca_isNull(peca)) {
		throwException("\nA pe\00F7a n\u00E3o foi cadastrada para a sess\u00E3o.");
	}

	printf("Informe a data e hora da sess\u00E3o (dd/mm/yyyy HH:MM):\n");
	gets(dataHora);

	printf("Informe o valor do ingresso para a sess\u00E3o:\n");
	scanf("%.2f", &valorIngresso);

	linkedList_put(sessao_nova(novoIdSessao, teatro, peca, dataHora, valorIngresso), list);
}

static comparable* sessao_comparableId(Sessao* sessao, int id) {
	return sessao_getId(sessao) == id;
}

Sessao* sessao_busca(LinkedList* list, int id) {
	Node* node = linkedList_search(list, id, sessao_comparableId);

	if (node != NULL) {
		return (Sessao*) node->value;
	}

	return NULL;
}

void sessao_print(int comTeatro, int comPeca, Sessao* sessao) {
	if (comTeatro) {
		teatro_print(&sessao->teatro);
	}

	if (comPeca) {
		peca_print(&sessao->peca);
	}

	printf("\n\t[Sessao] %d - %s - R$ %.2f", sessao_getId(sessao), sessao_getDataHoraStr(sessao), sessao_getValorIngresso(sessao));
}

void sessao_simplePrint(Sessao* sessao) {
	printf("\n\t[Sessao] %d - %s", sessao_getId(sessao), sessao_getDataHoraStr(sessao));
}
