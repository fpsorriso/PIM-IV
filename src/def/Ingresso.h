/*
 * Ingresso.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#ifndef _INGRESSO_H_
#define _INGRESSO_H_
#include "Venda.h"

typedef struct {
	Venda* venda;
	int poltrona;
	double valorUnitario;
	double desconto;
	int idoso; //1 - True| 0 - False
	int crianca2A12; //1 - True| 0 - False
	int professorRedePublica; //1 - True| 0 - False
	int alunoRedePublica; //1 - True| 0 - False
} Ingresso;

int ingressoIsNull(Ingresso pIngresso);

int ingressoIsMeiaEntrada(Ingresso pIngresso);

int ingressoGratis(Ingresso pIngresso);

double ingressoCalculaDesconto(Ingresso pIngresso);

int ingressoGetPoltrona(Ingresso pIngresso);

double ingressoGetValorUnitario(Ingresso pIngresso);

double ingressoGetValorDesconto(Ingresso pIngresso);

Ingresso ingressoNew(Venda pVenda, int pPoltrona, int pIdoso, int pCrianca2a12,
		int pProfessorRedePublica, int pAlunoRedePublica);

Venda* ingressoGetVenda(Ingresso pIngresso);

#endif /* _INGRESSO_H_ */
