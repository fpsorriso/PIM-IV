/*
 * Venda.c
 *
 *  Created on: 27 de out de 2018
 *      Author: sorriso
 */

#include "../def/Venda.h"
#include "../def/Ingresso.h"

#include <time.h>
#include "../def/Constante.h"

int venda_isNull(Venda *venda) {
	if (venda == NULL) {
		return 1;
	}

	return 0;
}

int venda_getId(Venda *venda) {
	if (!venda_isNull(venda)) {
		return venda->id;
	}

	return 0;
}

Venda* venda_getVenda(Venda *venda) {
	if (!venda_isNull(venda)) {
		return &venda->sessao;
	}

	return NULL;
}

void venda_setSessao(Venda *venda, Sessao *sessao) {
	if (!venda_isNull(venda)) {
		venda->sessao = sessao;
	}
}

static comparable* venda_comparableId(Venda* venda, int id) {
	return venda_getId(venda) == id;
}

Venda* venda_novo(int id, Sessao *sessao) {
	Venda *venda = (Venda *) calloc(1, sizeof(Venda));

	if (venda == NULL) {
		error(0, _ERROR_CODE_MEMORIA_INSUFICIENTE, _ERROR_CODE_MEMORIA_INSUFICIENTE);
		return NULL;
	}

	venda->id = id;
	venda->dataCriacao = time(NULL);
	venda->sessao = sessao;

	return venda;
}

LinkedList* venda_adicionarIngresso(Venda* venda) {
	if (!venda_isNull(venda)) {
		int idade = 0;
		int professorRedePublica = 0;
		int alunoRedePublica = 0;
		int novoIdIngresso = linkedList_count(venda->ingressos) + 1;
		int poltrona = 0;
		char opcao = '\0';

		do {
			opcao = '\0';
			printf("\nInforme a idade do espectador: ");
			scanf("%d", &idade);

			if (idade == 0) {
				printf(_EXCEPTION_CAMPO_OBRIGATORIO, "Idade do espectador");
				printf(_MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &opcao);
			}

		} while (opcao == 's');

		printf("\n\u00E9 professor da rede publica (s/n)?");
		scanf("%s", &opcao);
		professorRedePublica = opcao == 's';

		printf("\n\u00E9 aluno da rede publica (s/n)?");
		scanf("%s", &opcao);
		alunoRedePublica = opcao == 's';

		Ingresso* ingresso = ingresso_novo(novoIdIngresso, venda, poltrona, idade >= _IDADE_IDOSO,
				idade >= _IDADE_CRIANCA_MINIMO && idade <= _IDADE_CRIANCA_MAXIMO, professorRedePublica, alunoRedePublica);

		return linkedList_put(ingresso, venda->ingressos);
	}

	return NULL;
}

LinkedList* venda_cadastra(LinkedList* listVenda, LinkedList* listSessao) {
	Sessao* sessao = NULL;
	Venda* venda = NULL;
	int idSessao = 0;
	int novoIdVenda = linkedList_count(listVenda) + 1;
	char opcao = '\0';

	if (listSessao == NULL) {
		error(0, _ERROR_CODE_NULL_POINT, _EXCEPTION_NULL_POINT, "A sess\u00E3o");
		return listVenda;
	}

	do {
		sessao = NULL;
		idSessao = 0;
		opcao = '\0';

		printf("Informe o c\u00F3digo da Sess\u00E3o:\n");
		scanf("%d", &idSessao);

		if (idSessao == 0) {
			linkedList_foreach(listSessao, sessao_simplePrint);
		} else {
			Sessao* sessao = sessao_busca(listSessao, idSessao);
			if (sessao_isNull(sessao)) {
				printf("N\u00E3o foi poss\u00EDvel encontrar a Sess\u00E3o com id %d. %s", idSessao, _MENSAGEM_INFORMAR_NOVAMENTE);
				scanf("%s", &opcao);
				idSessao = 0;
			}
		}

	} while (idSessao == 0 && strcasecmp(opcao, 's'));

	venda = venda_novo(novoIdVenda, sessao);

	do {
		opcao = '\0';
		venda->ingressos =venda_adicionarIngresso(venda);
		printf("\nAdicionar outro ingresso (s/n)?");
		scanf("%s", &opcao);
	} while (strcasecmp(opcao, 's'));

	if (linkedList_count(venda->ingressos) == 0) {
		error(0, 10000, "Nenhuma venda de ingresso foi realizada, a venda atual ser\u00E1 cancelada.");
		return listVenda;
	}

	return linkedList_put(venda, listVenda);
}
