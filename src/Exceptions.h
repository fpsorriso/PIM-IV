int throwExceptionWithParam(char* mensagem, *parametros) {
	printf(mensagem, parametros);
	return 0;
}

int throwExceptionAlternativeMessage(char* mensagem) {
	printf(mensagem);
	return 0;
}

int throwNullPointException() {
	throwNullPointException("Opera\u\u00E3o invalida. Objeto nulo");
	return 1;
}


int throwStackOverFlowException() {
	throwExceptionWithParam("N\u00E3o foi poss\u00EDvel realizar o oper\u00E7\u00E3o, pois a mem\u00F3ria esta cheia.");
	return 0;
}
