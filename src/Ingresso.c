/*
 * Ingresso.c
 *
 *  Created on: 31 de out de 2018
 *      Author: sorriso
 */

#include <stdbool.h>

#include "Sessao.c"

struct ingresso {
	int id;
	Sessao sessao;
	int poltrona;
	double valorUnitario;
	double desconto;
	bool idoso;
    bool crianca2A12;
    bool professorRedePublica;
    bool alunoRedePublica;
};

typedef struct ingresso Ingresso;
