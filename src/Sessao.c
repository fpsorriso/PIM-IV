/*
 * Sessao.c
 *
 *  Created on: 30 de out de 2018
 *      Author: sorriso
 */

#include <time.h>

#include "DateTimeFormatter.h"
#include "Peca.c"
#include "Teatro.c"

struct sessao {
	int id;
	Teatro teatro;
	Peca peca;
	time_t dataHora;
	double valorIngresso;

};

typedef struct sessao Sessao;

Sessao *criar(int id, Teatro *teatro, Peca *peca, time_t dataHora,
		double valorIngresso) {
	Sessao *sessao = malloc(sizeof(Sessao));
	sessao->id = id;
	sessao->teatro = *teatro;
	sessao->peca = *peca;
	sessao->dataHora = dataHora;
	sessao->valorIngresso = valorIngresso;

	return sessao;
}

int isSessaoNula(Sessao *sessao) {
	if (sessao == NULL) {
		return 1;
	}

	return 0;
}

int getId(Sessao *sessao) {
	if (!isSessaoNula(sessao)) {
		return (int)sessao->id;
	}

	return (int) 0;
}

Peca* getPeca(Sessao *sessao) {
	if (!isSessaoNula(sessao)) {
		return sessao->peca;
	}

	return NULL;
}

void setPeca(Sessao *sessao, Peca *peca) {
	if (!isSessaoNula(sessao)) {
		sessao->peca = *peca;
	}
}

Teatro* getTeatro(Sessao *sessao) {
	if (!isSessaoNula(sessao)) {
		return (Teatro *)sessao->teatro;
	}

	return NULL;
}

void setTeatro(Sessao *sessao, Teatro *teatro) {
	if (!isSessaoNula(sessao)) {
		sessao->teatro = *teatro;
	}
}

time_t getDataHora(Sessao *sessao) {
	if (!isSessaoNula(sessao)) {
		return sessao->dataHora;
	}

	return NULL;
}

char *getDataHoraStr(Sessao *sessao) {
	char *result = (char *)malloc(30 * sizeof(char));

	if (!isSessaoNula(sessao) && sessao->dataHora != NULL) {
		struct tm *data = localtime((time_t)sessao->dataHora);
		strftime(result, sizeof(result), ISO_DATE_TIME, data);
	}

	return (char *)result;
}

void setDataHora(Sessao *sessao, time_t *dataHora) {
	if (!isSessaoNula(sessao)) {
		sessao->dataHora = &dataHora;
	}
}

void setDataHoraStr(Sessao *sessao, char *dataHora) {
	if (!isSessaoNula(sessao)) {
		if (strlen(&dataHora) > 0) {
			struct tm data;
			strptime(dataHora, ISO_DATE_TIME, data);
			sessao->dataHora = mktemp(data);

		} else {
			sessao->dataHora = (time_t *) NULL;
		}
	}
}


double getValorIngresso(Sessao *sessao) {
	if (!isSessaoNula(sessao)) {
		return sessao->valorIngresso;
	}

	return 0.00;
}

void setValorIngresso(Sessao *sessao, double valorIngresso) {
	if (!isSessaoNula(sessao)) {
		sessao->valorIngresso = valorIngresso;
	}
}
