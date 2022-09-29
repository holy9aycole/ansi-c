/********************************************************
 * dcl --	Programa que convierte una declaracion de C en una descripcion, ej:
 * - char **argv
 *		argv: puntero a un puntero de caracter
 * - int (*daytab)[13]
 *		daytab: puntero a un array de 13 enteros
 * - int *daytab[13]
 *		daytab: array de 13 punteros a enteros
********************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100	/* Cantidad máxima de simbolos (o token) a analizar */
#define OUT 1000	/* Tamaño de la salida */

enum { NAME, PARENS, BRACKETS };

void dcl (void);
void dirdcl (void);

int gettoken (void);
int tokentype;	/* tipo del ultimo token */
char token[MAXTOKEN];	/* string del ultimo token */
char name[MAXTOKEN];	/* nombre de identificador */
char datatype[MAXTOKEN];	/* tipos de datos = char, int, etc. */
char out[OUT];	/* string de salida */

/* convierte declaraciones en palabras */
int main (void) {
	while (gettoken() != EOF) {		/* el primer token de linea */
		strcpy(datatype, token);	/* es un tipo de dato */
		out[0] = '\0';
		dcl();	/* analizar (parsear) el resto de linea */
		if (tokentype != '\n')
			printf("error de sintaxis\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* dcl: parsear una declaracion */
void dcl (void) {
	int ns;	/* cantidad de '*' */
	for (ns = 0; gettoken() == '*';)	/* contar *'s' */
		++ns;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: pasea una declaracion directa */
void dirdcl (void) {
	int type;	/* tipo del token */

	if (tokentype == '(') {	/* (dcl) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME)	/* nombre de variable */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)	/* () -> parantesis de una funcion */
			strcat(out, " function returnig");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
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
