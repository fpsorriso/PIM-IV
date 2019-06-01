/*
 * Sessao.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _SESSAO_H_
#define _SESSAO_H_

#include <time.h>
#include "LinkedList.h"
#include "Peca.h"

struct sessao {
	int id;
	Peca peca;
	time_t dataHora;
};

typedef struct sessao Sessao;

Sessao sessaoEmpty();

int sessaoIsNull(Sessao pSessao);

Peca sessaoGetPeca(Sessao pSessao);

time_t sessaoGetDataHora(Sessao pSessao);

char* sessaoGetDataHoraStr(Sessao pSessao);

void sessaoSetDataHora(Sessao pSessao, time_t pDateTime);

void sessaoSetDataHoraStr(Sessao pSessao, char* pDateTime);

int sessaoIsTercaFeira(Sessao pSessao);

int sessaoGetId(Sessao pSessao);

Sessao sessaoNew(int pId, Peca pPeca, char* pDateTime);

Sessao* sessaoFind(LinkedList* pList, int pId);

void sessaoPrint(Sessao pSessao);

LinkedList* sessaoAddToList(LinkedList* pList, Peca pPeca);

#endif /* _SESSAO_H_ */
