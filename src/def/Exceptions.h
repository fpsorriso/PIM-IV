#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

int throwExceptionWithParam(char* mensagem, void **params);

int throwException(char* mensagem);

int throwNullPointException();

int throwStackOverFlowException();

#endif /* _EXCEPTIONS_H_ */
