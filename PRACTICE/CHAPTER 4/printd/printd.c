/********************************************************
 * printd --	Programa que convierte un numero decimal en una cadena de
 * caracteres
********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10	/* Tamaño máximo por linea */

int main (void) {
	char line[LENGTH];	/* linea de entrada */
	void printd (int);

	while (1) {
		fgets(line, sizeof(line), stdin);

		if (line[0] == 'q' || line[0] == 'Q')
			break;

		printd(atoi(line));
		printf("\n");
	}

	return 0;
}

/*
 * printd: convierte un numero decimal en un string
 *
 * Parameters:
 *		n	numero a convertir
 */
void printd (int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}
