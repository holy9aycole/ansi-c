/********************************************************
 * undcl --	Programa que convierte una descripcion en palabras a una
 * declaracion de, ej:
 * - x es una funcion que devuelve un puntero a un array de punteros de
 *   funciones que devuelven char (caracter)
 *   x () * [] * () char
 *   (*((*x)())[])
 *   char (*(*x())[])()
********************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100	/* Cantidad máxima de simbolos (o token) a analizar */
#define OUT 1000	/* Tamaño de la salida */

enum { NAME, PARENS, BRACKETS };

int gettoken (void);
int tokentype;	/* tipo del ultimo token */
char token[MAXTOKEN];	/* string del ultimo token */
char out[OUT];	/* string de salida */

/* convierte declaraciones en palabras */
int main (void) {
	int type;	/* tipo del token */
	char temp[OUT + MAXTOKEN];	/* string temporal */

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}
	return 0;
}

/* gettoken: devuelve el siguiente token desde la entrada.
 *
 * omite espacios y tabulaciones; un "token" es un nombre, un par de
 * parantesis, un para de corchetes quizás incluyendo un numero, o cualquier
 * otro caracter individual */
int gettoken (void) {
	int c;	/* ultimo caracter leido */
	char *p = token;

	while ((c = getchar()) == ' ' || c == '\t')	/* omitir espacios o tabs */
		;
	if (c == '(') {
		if ((c = getchar()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetc(c, stdin);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getchar()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getchar()); )
			*p++ = c;
		*p = '\0';
		ungetc(c, stdin);
		return tokentype = NAME;
	} else
		return tokentype = c;
}
