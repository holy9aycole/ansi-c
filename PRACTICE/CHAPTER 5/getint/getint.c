/********************************************************
 * getint -- Programa que convierte una cadena de caracteres a un numero entero
********************************************************/
#include <stdio.h>
#include <ctype.h>

#define SIZE 3	/* Tamaño del array */

int main (void) {
	int array[SIZE];	/* array de enteros */
	int n;	/* indice del array */
	int getint (int *);

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n)
		;

	printf("array = { %d", array[0]);
	for (n = 1; n < SIZE; ++n)
		printf(", %d", array[n]);

	printf(" }\n");

	return 0;
}

/*
 * getint: convierte una cadena de caracteres a un numero entero
 *
 * Parameters:
 *		pn		puntero donde guardar el numero
 */
int getint (int *pn) {
	int c;	/* cada caracter leido */
	int sign;	/* signo del numero */

	*pn = 0;	/* valor por defecto */

	while (isspace(c = getchar()))	/* saltar espacios */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetc(c, stdin);	/* no es un numero */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getchar();

	if (!isdigit(c)) {
		ungetc(c, stdin);	/* no es un numero */
		return 0;
	}

	for (; isdigit(c); c = getchar())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetc(c, stdin);

	return c;
}
