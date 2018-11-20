/*
 * Ingresso.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _INGRESSO_H_
#define _INGRESSO_H_

#include "Venda.h"

struct ingresso {
	int id;
	Venda* venda;
	int poltrona;
	double valorUnitario;
	double desconto;
	int idoso; //1 - True| 0 - False
	int crianca2A12; //1 - True| 0 - False
	int professorRedePublica; //1 - True| 0 - False
	int alunoRedePublica; //1 - True| 0 - False
};

typedef struct ingresso Ingresso;

int ingresso_isNull(Ingresso *ingresso);

int ingresso_isMeiaEntrada(Ingresso* ingresso);

int ingresso_gratis(Ingresso* ingresso);

double ingresso_calculaDesconto(Ingresso *ingresso);

int ingresso_getId(Ingresso* ingresso);

Venda* ingresso_getVenda(Ingresso* ingresso);

int ingresso_getPoltrona(Ingresso* ingresso);

double ingresso_getValorUnitario(Ingresso* ingresso);

double ingresso_getValorDesconto(Ingresso* ingresso);

Ingresso* ingresso_novo(int id, Venda *venda, int poltrona, int idoso, int crianca2a12, int professorRedePublica, int alunoRedePublica);

#endif /* _INGRESSO_H_ */
