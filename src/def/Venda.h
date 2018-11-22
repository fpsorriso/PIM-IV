/*
 * Venda.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef SRC_VENDA_H_
#define SRC_VENDA_H_

#include "../def/LinkedList.h"
#include "../def/Sessao.h"

struct venda {
	int id;
	time_t dataCriacao;
	Sessao* sessao;
	LinkedList* ingressos;
};

typedef struct venda Venda;

int venda_isNull(Venda *venda);

Venda* venda_novo(int id, Sessao *sessao);

int venda_getId(Venda *venda);

Sessao* venda_getSessao(Venda *venda);

LinkedList* venda_cadastra(LinkedList* list, LinkedList* listSessao);

#endif /* SRC_VENDA_H_ */
