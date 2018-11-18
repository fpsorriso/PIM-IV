/*
 * Venda.c
 *
 *  Created on: 27 de out de 2018
 *      Author: sorriso
 */

#include <time.h>

#include "Ingresso.h"

struct itemVenda {
	Ingresso ingresso;
	struct itemVenda *proximo;
};

typedef struct itemVenda ItemVenda;

struct venda {
	int id;
	time_t dataCriacao;
	Sessao* sessao;
	struct itemVenda *itemVenda;
};

typedef struct venda Venda;

int isVendaNula(Venda *venda) {
	if (venda == NULL) {
		return 1;
	}

	return 0;
}

Venda *criarVenda(int id, Sessao *sessao) {
	Venda *venda = (Venda *) calloc(1, sizeof(Venda));

	if (venda == NULL) {
		throwStackOverFlowWithParam();
	}

	venda->id = id;
	venda->dataCriacao = time(NULL);
	venda->sessao = sessao;

	return venda;
}

int getVendaId(Venda *venda) {
	if (!isVendaNula(venda)) {
		return venda->id;
	}

	return 0;
}

Sessao *getSessao(Venda *venda) {
	if (!isVendaNula(venda)) {
		return &venda->sessao;
	}

	return NULL;
}

void setSessao(Venda *venda, Sessao *sessao) {
	if (!isVendaNula(venda)) {
		venda->sessao = sessao;
	}
}

int equalsVenda(Venda *venda, Venda *outraVenda) {
	if (!isVendaNula(venda) && !isVendaNula(outraVenda)) {
		return venda->id == outraVenda->id;
	}

	return isVendaNula(venda) && isVendaNula(outraVenda);
}

ItemVenda* removePrimeiroItemVenda(ItemVenda* head) {
	if (head == NULL) {
		return NULL;
	}

	ItemVenda *primeiro = head;
	head = head->proximo;
	primeiro->proximo = NULL;
	/* is this the last node in the list */
	if (primeiro == head) {
		head = NULL;
	}

	free(primeiro);
	return head;
}

ItemVenda* removeUltimoItemVenda(ItemVenda* head) {
	if (head == NULL) {
		return NULL;
	}

	ItemVenda *atual = head;
	ItemVenda *anterior = NULL;

	while (atual->proximo != NULL) {
		anterior = atual;
		atual = atual->proximo;
	}

	if (anterior != NULL) {
		anterior->proximo = NULL;
	}

	/* if this is the last node in the list*/
	if (atual == head) {
		head = NULL;
	}

	free(atual);

	return head;
}

ItemVenda* removeItemVenda(ItemVenda* head, ItemVenda* nd) {
	/* if the node is the first node */
	if (nd == head) {
		head = removePrimeiroItemVenda(head);
		return head;
	}

	/* if the node is the last node */
	if (nd->proximo == NULL) {
		head = removeUltimoItemVenda(head);
		return head;
	}

	/* if the node is in the middle */
	ItemVenda* atual = head;

	while (atual != NULL) {

		if (atual->proximo = nd) {
			break;
		}

		atual = atual->proximo;
	}

	if (atual != NULL) {
		ItemVenda* tmp = atual->proximo;
		atual->proximo = tmp->proximo;
		tmp->proximo = NULL;
		free(tmp);
	}
	return head;
}

ItemVenda* inserirItemVenda(Ingresso* ingresso, ItemVenda* proximo) {
	if (!isIngressoNulo(ingresso)) {
		ItemVenda* novo = (ItemVenda*) calloc(1, sizeof(ItemVenda));

		if (novo == NULL) {
			throwStackOverFlowWithParam();
		}

		novo->ingresso = *ingresso;
		novo->proximo = proximo;

		return novo;
	}

	return NULL;
}

int totalItensVenda(ItemVenda *head) {
	ItemVenda *atual = head;
	int c = 0;

	while (atual != NULL) {
		c++;
		atual = atual->proximo;
	}

	return c;
}

void liberarListaItensVenda(ItemVenda *head) {
	ItemVenda *atual, *tmp;

	if (head != NULL) {
		atual = head->proximo;
		head->proximo = NULL;

		while (atual != NULL) {
			tmp = atual->proximo;
			free(atual);
			atual = tmp;
		}
	}
}

ItemVenda* procurarItemVendaPorIngresso(ItemVenda* head, Ingresso* ingresso) {
	ItemVenda *atual = head;

	while (atual != NULL) {
		if (equalsIngresso(&atual->ingresso, ingresso)) {
			return atual;
		}

		atual = atual->proximo;
	}
	return NULL;
}
