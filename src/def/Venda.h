/*
 * Venda.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef SRC_VENDA_H_
#define SRC_VENDA_H_

#include "LinkedList.h"
#include "Sessao.h"

typedef struct {
	int id;
	time_t dataCriacao;
	Sessao* sessao;
	LinkedList* ingressos;
} Venda;


int vendaIsNull(Venda pVenda);

Venda vendaNew(int id, Sessao *sessao);

int vendaGetId(Venda pVenda);

Sessao vendaGetSessao(Venda pVenda);

LinkedList* vendaCadastra(LinkedList* list, LinkedList* listSessao);

#endif /* SRC_VENDA_H_ */
