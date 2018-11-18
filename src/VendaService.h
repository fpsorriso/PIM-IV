struct vendaRealizada {
	Venda* venda;
	struct vendaRealizada *proximo;
};

typedef struct vendaRealizada VendaRealizada;

VendaRealizada* criaListaVendaRealizada(Venda* venda, VendaRealizada* proximaVenda) {
	if (!isVendaNula(venda)) {
		VendaRealizada *novaVendaRealizada = (VendaRealizada *) calloc(1, sizeof(VendaRealizada));
		novaVendaRealizada->venda = *venda;
		novaVendaRealizada->proximo = proximaVenda;
		return novaVendaRealizada;
	}

	return NULL;
}

int isListaVazia(VendaRealizada* lista) {
	if (isVendaNula(&lista->venda) && lista->proximo == NULL) {
		return 1;
	}

	return 0;
}

VendaRealizada* removePrimeiraVendaRealizada(VendaRealizada* head) {
	if (head == NULL) {
		return NULL;
	}

	VendaRealizada *primeiro = head;
	head = head->proximo;
	primeiro->proximo = NULL;

	/* is this the last node in the list */
	if (primeiro == head) {
		head = NULL;
	}

	free(primeiro);
	return head;
}

VendaRealizada* removeUltimaVendaRealizada(VendaRealizada* head) {
	if (head == NULL) {
		return NULL;
	}

	VendaRealizada *atual = head;
	VendaRealizada *anterior = NULL;
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

VendaRealizada* removeVendaRealizada(VendaRealizada* head, VendaRealizada* nd) {
	/* if the node is the first node */
	if (nd == head) {
		head = removePrimeiraVendaRealizada(head);
		return head;
	}

	/* if the node is the last node */
	if (nd->proximo == NULL) {
		head = removeUltimaVendaRealizada(head);
		return head;
	}

	/* if the node is in the middle */
	VendaRealizada* cursor = head;
	while (cursor != NULL) {
		if (cursor->proximo = nd) {
			break;
		}

		cursor = cursor->proximo;
	}

	if (cursor != NULL) {
		VendaRealizada* tmp = cursor->proximo;
		cursor->proximo = tmp->proximo;
		tmp->proximo = NULL;
		free(tmp);
	}

	return head;
}

void liberaListaVendasRealizadas(VendaRealizada *head) {
	VendaRealizada *atual, *tmp;

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

int totalVendasRealizada(VendaRealizada *head) {
	VendaRealizada *atual = head;
	int c = 0;
	while (atual != NULL) {
		c++;
		atual = atual->proximo;
	}
	return c;
}

VendaRealizada* realizaVenda(VendaRealizada* headVendasRealizadas, ListaSessao* listaSessoes) {

	printf("");
	buscar
	int idVenda = totalVendasRealizada(headVendasRealizadas) + 1;
	criarVenda(idVenda, );
	return criaListaVendaRealizada();

}
