/*
 * Ingresso.c
 *
 *  Created on: 31 de out de 2018
 *      Author: sorriso
 */

#include <stdbool.h>

#include "Sessao.h"

struct ingresso {
	int id;
	Sessao* sessao;
	int poltrona;
	double valorUnitario;
	double desconto;
	int idoso; //1 - True| 0 - False
	int crianca2A12; //1 - True| 0 - False
	int professorRedePublica; //1 - True| 0 - False
	int alunoRedePublica; //1 - True| 0 - False
};

typedef struct ingresso Ingresso;

int isIngressoNulo(Ingresso *ingresso) {
	if (ingresso == NULL) {
		return 1;
	}

	return 0;
}

int equalsIngresso(Ingresso *ingresso, Ingresso *outroIngresso) {
	if (!isIngressoNulo(ingresso) && !isIngressoNulo(outroIngresso)) {
		return ingresso->id == outroIngresso->id;
	}

	return isIngressoNulo(ingresso) && isIngressoNulo(outroIngresso);
}

double calcularDesconto(Ingresso *ingresso) {
	if (!isIngressoNulo(ingresso) && ingresso->valorUnitario > 0) {
		if (ingresso->idoso || ingresso->crianca2A12
				|| ingresso->professorRedePublica) {
			return ingresso->valorUnitario / 2;
		}

		if (sessao_isTercaFeira(&ingresso->sessao) && ingresso->alunoRedePublica) {
			return ingresso->valorUnitario;
		}
	}

	return 0;
}

Ingresso *criarIngresso(int id, Sessao *sessao, int poltrona, int idoso,
		int crianca2a12, int professorRedePublica, int alunoRedePublica) {
	if (!sessao_isNull(sessao)) {
		Ingresso *ingresso = (Ingresso *) calloc(1, sizeof(Ingresso));

		if (ingresso == NULL) {
			throwStackOverFlowWithParam();
		}

		ingresso->id = id;
		ingresso->sessao = sessao;
		ingresso->poltrona = poltrona;
		ingresso->valorUnitario = sessao->valorIngresso;
		ingresso->idoso = idoso;
		ingresso->crianca2A12 = crianca2a12;
		ingresso->professorRedePublica = professorRedePublica;
		ingresso->alunoRedePublica = alunoRedePublica;
		ingresso->desconto = calcularDesconto(ingresso);
		return ingresso;
	}

	return NULL;
}

