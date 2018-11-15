/*
 * Venda.c
 *
 *  Created on: 27 de out de 2018
 *      Author: sorriso
 */

#include <time.h>

#include "Sessao.c"

struct itemVenda {
	Ingresso ingresso;
	struct itemVenda *proximoItem;
}

typedef struct itemVenda ItemVenda;

struct venda {
	int id;
	time_t dataCriacao;
	Sessao sessao;
	ItemVenda itens;
};

typedef struct venda Venda;


int isVendaNula(Venda venda) {
	return venda == NULL;
}

Venda *criarVenda(int id, Sessao *sessao) {
	Venda venda = (Venda *) malloc(sizeof(Venda));
	venda.id = id;
	venda.dataCriacao = &time(NULL);
	venda.sessao = sessao;

	return (Venda *) venda;
}

int getId(Venda *venda) {
	if (!isVendaNula(venda)) {
		return venda->id;
	}

	return 0;
}

Sessao getSessao(Venda *venda) {
	if (!isVendaNula(venda)) {
		return venda->sessao;
	}

	return NULL;
}

void setSessao(Venda *venda, Sessao *sessao) {
	if (!isVendaNula(venda)) {
		venda->sessao = &sessao;
	}
}
