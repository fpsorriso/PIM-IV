/*
 * Ingresso.c
 *
 *  Created on: 31 de out de 2018
 *      Author: sorriso
 */
#include<stdbool.h>

#include "Venda.c"

typedef struct ingresso {
	int id;
	Venda venda;
	int poltrona;
	double valorUnitario;
	double desconto;
	bool idoso;
    bool crianca2A12;
    bool professorRedePublica;
    bool alunoRedePublica;

} Ingresso;
