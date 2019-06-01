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

int sessaoIsNull(Sessao pSessao) {
	if (&pSessao == NULL) {
		return 1;
	}

	return 0;
}

int sessaoDataIsNull(Sessao pSessao) {
	if (pSessao.dataHora == (time_t) -1) {
		return 1;
	}

	return 0;
}


Peca sessaoGetPeca(Sessao pSessao) {
	if (!sessaoIsNull(pSessao)) {
		return pSessao.peca;
	}

	return pecaVazia();
}

time_t sessaoGetDataHora(Sessao pSessao) {
	if (!sessaoIsNull(pSessao)) {
		return pSessao.dataHora;
	}

	return NULL;
}

char* sessaoGetDataHoraStr(Sessao pSessao) {
	char *vResult = calloc(1, sizeof(char));

	if (!sessaoIsNull(pSessao) && !sessaoDataIsNull(pSessao)) {
		Sessao* vPointer = &pSessao;
		struct tm* vDate = localtime(vPointer->dataHora);
		strftime(vResult, sizeof(vResult), _ISO_DATE_TIME, vDate);
		free(vDate);
	}

	return (char *) vResult;
}

void sessaoSetDataHora(Sessao pSessao, time_t pDateTime) {
	if (!sessaoIsNull(pSessao)) {
		pSessao.dataHora = pDateTime;
	}
}

void sessaoSetDataHoraStr(Sessao pSessao, char* pDateTime) {
	if (!sessaoIsNull(pSessao)) {
		if (strlen(pDateTime) > 0) {
			struct tm vDate;
			strptime(pDateTime, _ISO_DATE_TIME, &vDate);
			pSessao.dataHora = mktime(&vDate);
		} else {
			pSessao.dataHora = (time_t) -1;
		}
	}
}
int sessaoIsTercaFeira(Sessao pSessao) {
	if (!sessaoIsNull(pSessao) && pSessao.dataHora ) {
		Sessao* vPointer = &pSessao;
		struct tm* vDate = localtime(vPointer->dataHora);

		if (vDate->tm_wday == 2) {
			free(vDate);
			return 1;
		}

		free(vDate);
	}

	return 0;
}

Sessao sessaoNew(int pId, Peca pPeca, char* pDataHora) {
	Sessao vSessao;
	vSessao.id = pId;
	vSessao.peca = pPeca;
	sessaoSetDataHoraStr(vSessao, pDataHora);

	return vSessao;
}

int sessaoGetId(Sessao pSessao) {
	if (!sessaoIsNull(pSessao)) {
		return pSessao.id;
	}

	return 0;
}

static comparable* sessaoComparable(Sessao pSessao, int pId) {
	return sessaoGetId(pSessao) == pId;
}

Sessao* sessaoFind(LinkedList* pList, int pId) {
	Node* vNode = linkedListSearch(pList, pId, sessaoComparable);

	if (vNode != NULL) {
		return (Sessao*) vNode->value;
	}

	return NULL;
}

void sessaoPrint(Sessao pSessao) {
	pecaPrint(pSessao.peca);
	printf("\n\t[Sess\u00E3o] %s - R$ %.2f", sessaoGetDataHoraStr(pSessao), pecaGetValorIngresso(pSessao.peca));
}

char requestDateTimeOfSession() {
	char vDateTime[strlen(_ISO_DATE_TIME_VIEW)];
	char vOption;

	do {
		vDateTime[0] = '\0';
		vOption = '\0';
		printf("Informe a data e hora da sess\u00E3o (%s):\n",
				_ISO_DATE_TIME_VIEW);
		fgets(vDateTime, strlen(_ISO_DATE_TIME_VIEW) + 1, stdin);

		if (strIsEmpty(vDateTime)
				|| strlen(strTrim(vDateTime)) != strlen(_ISO_DATE_TIME_VIEW)) {
			printf(_EXCEPTION_CAMPO_OBRIGATORIO, "Data e Hora");
			printf(_MENSAGEM_INFORMAR_NOVAMENTE);
			scanf(" %c", &vOption);
		}
	} while ((strIsEmpty(vDateTime)
			|| strlen(strTrim(vDateTime)) != strlen(_ISO_DATE_TIME_VIEW))
			&& vOption == 's');
	return vDateTime;
}

LinkedList* sessaoAddToList(LinkedList* pList, Peca pPeca) {
	char* vDateTime;

	vDateTime = requestDateTimeOfSession();

	if (strIsEmpty(vDateTime)) {
		printf(_EXCEPTION_IMPOSSIVEL_CADASTRAR, "da Sess\u00E3o");
		return pList;
	}

	int vNovoId = linkedListCount(pList) + 1;
	Sessao vResult = sessaoNew(vNovoId, pPeca, vDateTime);

	return linkedListPut(&vResult, pList);
}
