/********************************************************
 * blank_counter --	Programa que cuenta la cantidad de espacios,
 * tabulaciones y saltos de linea desde la entrada del usuario.
********************************************************/
#include <stdio.h>

int main () {
	/* Contador de espacios, tabulaciones y saltos de linea */
	int blank_counter, tab_counter, newline_counter;

	int character;	/* caracter introducido */

	/* inicializamos los contadores */
	blank_counter = 0;
	tab_counter = 0;
	newline_counter = 0;

	while ((character = getchar()) != EOF) {
		if (character == ' ')
			++blank_counter;
		else if (character == '\t')
			++tab_counter;
		else if (character == '\n')
			++newline_counter;
	}
	putchar('\n');
	printf("Espacio: %d, Tabulaciones: %d, Saltos de linea: %d\n",
			blank_counter, tab_counter, newline_counter);

	return 0;
}
