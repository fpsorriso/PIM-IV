/*
 * Ingresso.c
 *
 *  Created on: 31 de out de 2018
 *      Author: sorriso
 */


#include "../def/Ingresso.h"
#include "../def/LinkedList.h"
#include "../def/Sessao.h"

int ingresso_isNull(Ingresso *ingresso) {
	if (ingresso == NULL) {
		return 1;
	}

	return 0;
}

int ingresso_isMeiaEntrada(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return ingresso->idoso || ingresso->crianca2A12 || ingresso->professorRedePublica;
	}

	return 0;
}

int ingresso_gratis(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return sessao_isTercaFeira(&ingresso->venda) && ingresso->alunoRedePublica;
	}

	return 0;
}

double ingresso_calculaDesconto(Ingresso *ingresso) {
	if (ingresso_isMeiaEntrada(ingresso)) {
		return ingresso->valorUnitario / 2;

	} else if (ingresso_gratis(ingresso)) {
		return ingresso->valorUnitario;
	}

	return 0;
}

int ingresso_getId(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return ingresso->id;
	}

	return 0;
}

Venda* ingresso_getVenda(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return ingresso->venda;
	}

	return NULL;
}

int ingresso_getPoltrona(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return ingresso->poltrona;
	}

	return 0;
}

double ingresso_getValorUnitario(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return ingresso->valorUnitario;
	}

	return 0.00;
}

double ingresso_getValorDesconto(Ingresso* ingresso) {
	if (!ingresso_isNull(ingresso)) {
		return ingresso->desconto;
	}

	return 0.00;
}

Ingresso* ingresso_novo(int id, Venda* venda, int poltrona, int idoso, int crianca2a12, int professorRedePublica, int alunoRedePublica) {
	if (!venda_isNull(venda)) {
		Ingresso *ingresso = (Ingresso *) calloc(1, sizeof(Ingresso));

		if (ingresso == NULL) {
			throwStackOverFlowException();
		}

		ingresso->id = id;
		ingresso->venda = venda;
		ingresso->poltrona = poltrona;
		ingresso->valorUnitario = sessao_getValorIngresso(venda->sessao);
		ingresso->idoso = idoso;
		ingresso->crianca2A12 = crianca2a12;
		ingresso->professorRedePublica = professorRedePublica;
		ingresso->alunoRedePublica = alunoRedePublica;
		ingresso->desconto = ingresso_calculaDesconto(ingresso);
		return ingresso;
	}

	return NULL;
}


static comparable* ingresso_comparableId(Ingresso* ingresso, int id) {
	return ingresso_getId(ingresso) == id;
}
