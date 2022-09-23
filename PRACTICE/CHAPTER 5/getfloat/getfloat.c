/********************************************************
 * getfloat -- Programa que convierte una cadena de caracteres a un numero
 * flotante
********************************************************/
#include <stdio.h>
#include <ctype.h>

#define SIZE 3	/* Tamaño del array */

int main (void) {
	double array[SIZE];	/* array de numeros flotantes */
	int n;	/* indice del array */
	int getfloat (double *);

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; ++n)
		;

	printf("array = { %g", array[0]);
	for (n = 1; n < SIZE; ++n)
		printf(", %g", array[n]);

	printf(" }\n");

	return 0;
}

/*
 * getfloat: convierte una cadena de caracteres a un numero flotante
 *
 * Parameters:
 *		pn		puntero donde guardar el numero
 */
int getfloat (double *pn) {
	int c;	/* caracter leido */
	int sign;	/* signo del numero */
	int power;	/* potencia de base 10 (cantidad de decimales del numero) */

	*pn = 0.0;	/* valor por defecto */

	power = 1;

	while (isspace(c = getchar()))	/* saltar espacios */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {	/* no es un numero */
		ungetc(c, stdin);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getchar();

	if (!isdigit(c)) {
		ungetc(c, stdin);
		return 0;
	}

	for (; isdigit(c); c = getchar())	/* parte entera */
		*pn = 10 * *pn + (c - '0');

	if (c == '.') {
		c = getchar();
		for (power = 1; isdigit(c); c = getchar()) {	/* parte decimal */
			*pn = 10 * *pn + (c - '0');
			power *= 10;
		}
	}

	*pn = (*pn / power) * sign;
	if (c != EOF)
		ungetc(c, stdin);

	return c;
}
