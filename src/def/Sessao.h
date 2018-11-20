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
#include "Teatro.h"

struct sessao {
	int id;
	Teatro teatro;
	Peca peca;
	time_t dataHora;
	double valorIngresso;

};

typedef struct sessao Sessao;

int sessao_isNull(Sessao* sessao);

int sessao_getId(Sessao* sessao);

Peca* sessao_getPeca(Sessao* sessao);

Teatro* sessao_getTeatro(Sessao* sessao);

time_t sessao_getDataHora(Sessao* sessao);

char* sessao_getDataHoraStr(Sessao* sessao);

void sessao_setDataHora(Sessao* sessao, time_t* dataHora);

void sessao_setDataHoraStr(Sessao* sessao, char* dataHora);

double sessao_getValorIngresso(Sessao* sessao);

void sessao_setValorIngresso(Sessao* sessao, double valorIngresso);

int sessao_isTercaFeira(Sessao* sessao);

Sessao* sessao_nova(int id, Teatro* teatro, Peca* peca, char* dataHora, double valorIngresso);

void sessao_cadastra(LinkedList* list, Teatro* teatro, Peca* peca);

Sessao* sessao_busca(LinkedList* list, int id);

void sessao_print(int comTeatro, int comPeca, Sessao* sessao);

void sessao_simplePrint(Sessao* sessao);

#endif /* _SESSAO_H_ */