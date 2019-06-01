/*
 * Ingresso.c
 *
 *  Created on: 31 de out de 2018
 *      Author: sorriso
 */

#include "../def/Ingresso.h"

#include <stdio.h>
#include <stdlib.h>

#include "../def/Constante.h"
#include "../def/LinkedList.h"
#include "../def/Peca.h"

Ingresso ingressoEmpty() {
	Ingresso vIngresso;
	vIngresso.alunoRedePublica = 0;
	vIngresso.crianca2A12 = 0;
	vIngresso.desconto = 0.00;
	vIngresso.idoso = 0;
	vIngresso.poltrona = 0;
	vIngresso.professorRedePublica = 0;
	vIngresso.valorUnitario = 0.00;
	vIngresso.venda = NULL;

	return vIngresso;
}

int ingressoIsNull(Ingresso pIngresso) {
	if (&pIngresso == NULL) {
		return 1;
	}

	return 0;
}

int ingressoIsMeiaEntrada(Ingresso pIngresso) {
	if (!ingressoIsNull(pIngresso)) {
		return pIngresso.idoso || pIngresso.crianca2A12
				|| pIngresso.professorRedePublica;
	}

	return 0;
}

int ingressoGratis(Ingresso pIngresso) {
	if (!ingressoIsNull(pIngresso)) {
		return sessaoIsTercaFeira(pIngresso.venda) && pIngresso.alunoRedePublica;
	}

	return 0;
}

double ingressoCalculaDesconto(Ingresso pIngresso) {
	if (ingressoIsMeiaEntrada(pIngresso)) {
		return pIngresso.valorUnitario / 2;

	} else if (ingressoGratis(pIngresso)) {
		return pIngresso.valorUnitario;
	}

	return 0;
}

Venda* ingressoGetVenda(Ingresso pIngresso) {
	if (!ingressoIsNull(pIngresso)) {
		return pIngresso.venda;
	}

	return NULL ;
}

int ingressoGetPoltrona(Ingresso pIngresso) {
	if (!ingressoIsNull(pIngresso)) {
		return pIngresso.poltrona;
	}

	return 0;
}

double ingressoGetValorUnitario(Ingresso pIngresso) {
	if (!ingressoIsNull(pIngresso)) {
		return pIngresso.valorUnitario;
	}

	return 0.00;
}

double ingressoGetValorDesconto(Ingresso pIngresso) {
	if (!ingressoIsNull(pIngresso)) {
		return pIngresso.desconto;
	}

	return 0.00;
}

Ingresso ingressoNew(Venda pVenda, int pPoltrona, int pIdoso, int pCrianca2a12,
		int pProfessorRedePublica, int pAlunoRedePublica) {
	Ingresso vIngresso = ingressoEmpty();

	if (!vendaIsNull(pVenda)) {
		vIngresso.venda = &pVenda;
		vIngresso.poltrona = pPoltrona;
		vIngresso.valorUnitario = pecaGetValorIngresso(pVenda->sessao->peca);
		vIngresso.idoso = pIdoso;
		vIngresso.crianca2A12 = pCrianca2a12;
		vIngresso.professorRedePublica = pProfessorRedePublica;
		vIngresso.alunoRedePublica = pAlunoRedePublica;
		vIngresso.desconto = ingressoCalculaDesconto(vIngresso);
		return vIngresso;
	}

	return vIngresso;
}

