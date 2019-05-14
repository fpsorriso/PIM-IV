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
	Peca peca;
	time_t dataHora;
};

typedef struct sessao Sessao;

int sessao_isNull(Sessao sessao);

Peca* sessao_getPeca(Sessao sessao);

time_t sessao_getDataHora(Sessao sessao);

char* sessao_getDataHoraStr(Sessao sessao);

void sessao_setDataHora(Sessao* sessao, time_t dataHora);

void sessao_setDataHoraStr(Sessao* sessao, char* dataHora);

int sessao_isTercaFeira(Sessao sessao);

Sessao* sessao_nova(Peca peca, char* dataHora);

Sessao* sessao_busca(LinkedList* list, char* dataHora);

void sessao_print(Sessao sessao);

LinkedList* sessao_cadastra(LinkedList* list, Peca peca);

#endif /* _SESSAO_H_ */
