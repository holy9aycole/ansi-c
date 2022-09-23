/********************************************************
 * print_words --	Programa que imprime la entrada del usuario en una
 * palabra por linea.
********************************************************/
#include <stdio.h>

#define IN 1	/* dentro de una palabra */
#define OUT 0	/* fuera de una palabra */

int main () {
	int character;	/* caracter introducido */
	int flag;	/* bandera que indica si esta dentro o fuera de una palabra */

	flag = OUT;
	while ((character = getchar()) != EOF) {
		if (character == ' ' || character == '\t')
			flag = OUT;
		else if (flag == OUT) {
			flag = IN;	/* dentro de una palabra */
			putchar('\n');	/* separar cada palabra */
		}

		if (flag == IN) {	/* dentro de una palabra */
			putchar(character);	/* se imprime los caracteres de la palabra */
		}
	}

	return 0;
}
