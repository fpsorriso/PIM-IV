/*
 * Venda.c
 *
 *  Created on: 27 de out de 2018
 *      Author: sorriso
 */

#include "../def/Venda.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../def/Constante.h"
#include "../def/Ingresso.h"

int vendaIsNull(Venda pVenda) {
	if (&pVenda == NULL) {
		return 1;
	}

	return 0;
}

int vendaGetId(Venda pVenda) {
	if (!vendaIsNull(pVenda)) {
		return pVenda.id;
	}

	return 0;
}

Venda vendaNew(int pId, Sessao *pSessao) {
	Venda vVenda;

	vVenda.id = pId;
	vVenda.dataCriacao = time(NULL);
	vVenda.sessao = pSessao;

	return vVenda;
}

int isIdoso(int pIdade) {
	return pIdade >= _IDADE_IDOSO;
}

int isCrianca(int pIdade) {
	return pIdade >= _IDADE_CRIANCA_MINIMO && pIdade <= _IDADE_CRIANCA_MAXIMO;
}

int buscarPoltronaLivre(LinkedList* pListVenda, Sessao pSessao) {
	int vVendas = linkedListCount(pListVenda);


	if ( vVendas > 0) {
//		linkedListForeach(pListVenda, );
	}
}



LinkedList* vendaAdicionarIngresso(Venda pVenda, int pPoltrona) {
	if (!vendaIsNull(pVenda)) {
		int vIdade = 0;
		int pProfessorRedePublica = 0;
		int pAlunoRedePublica = 0;
		char vOpcao = '\0';

		do {
			vOpcao = '\0';
			printf("\nInforme a idade do espectador: ");
			scanf("%d", &vIdade);

			if (vIdade == 0) {
				printf(_EXCEPTION_CAMPO_OBRIGATORIO, "Idade do espectador");
				printf(_MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &vOpcao);
			}

		} while (vOpcao == 's');

		printf("\n\u00E9 professor da rede publica (s/n)?");
		scanf("%s", &vOpcao);
		pProfessorRedePublica = vOpcao == 's' ? 1 : 0;

		printf("\n\u00E9 aluno da rede publica (s/n)?");
		scanf("%s", &vOpcao);
		pAlunoRedePublica = vOpcao == 's'? 1 : 0;

//		Ingresso vIngresso = ingressoNew(pVenda, pPoltrona, isIdoso(vIdade),
//				isCrianca(vIdade), pProfessorRedePublica, pAlunoRedePublica);

		Ingresso* vIngressoPoint = (Ingresso*) calloc(1, sizeof(Ingresso));


		return linkedListPut(vIngressoPoint, pVenda.ingressos);
	}

	return NULL ;
}

LinkedList* vendaCadastra(LinkedList* listVenda, LinkedList* listSessao) {
	int novoIdVenda = linkedListCount(listVenda) + 1;
	Sessao* vSessao;
	int vIdSessao;
	char vOpcao = '\0';

	if (listSessao == NULL) {
		printf(_EXCEPTION_NULL_POINT, "A sess\u00E3o");
		return listVenda;
	}

	do {
		vSessao = NULL;
		vIdSessao = 0;
		vOpcao = '\0';

		printf("Informe o c\u00F3digo da Sess\u00E3o:\n");
		scanf("%d", &vIdSessao);

		if (vIdSessao == 0) {
			linkedListForeach(listSessao, sessaoPrint);

		} else {
			vSessao = sessaoFind(listSessao, vIdSessao);

			if (vSessao == NULL) {
				printf(
						"N\u00E3o foi poss\u00EDvel encontrar a Sess\u00E3o com id %d. %s",
						vIdSessao, _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &vOpcao);
				vIdSessao = 0;
			}
		}

	} while (vIdSessao == 0 && strcasecmp(vOpcao, 's') == 0);

	Venda vVenda = vendaNew(novoIdVenda, vSessao);

	do {
		vOpcao = '\0';
		int vPoltronaLivre = buscarPoltronaLivre(listVenda, vSessao);

		if (vPoltronaLivre > 0) {
		vVenda.ingressos = vendaAdicionarIngresso(vVenda, vPoltronaLivre);
		printf("\nAdicionar outro ingresso (s/n)?");
		scanf("%s", &vOpcao);
		} else {
			printf("Sess\u00E3o de %s, esta esgotada.", sessaoGetDataHoraStr(vSessao->dataHora));
			break;
		}

	} while (strcasecmp(vOpcao, 's') == 0);

	if (linkedListCount(vVenda.ingressos) == 0) {
		printf("%s","Nenhuma venda de ingresso foi realizada, a venda atual ser\u00E1 cancelada.");
		return listVenda;
	}

	return linkedListPut(&vVenda, listVenda);
}
