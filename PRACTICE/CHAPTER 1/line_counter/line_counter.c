/********************************************************
 * line_counter --	Programa que cuenta la cantidad de lineas
 * de una entrada de texto.
********************************************************/
#include <stdio.h>

int main() {
	int counter;	/* Contador de lineas */
	int character;	/* Cada caracter introducido */

	counter = 0;	/* inicaliamos el contador */
	while ((character = getchar()) != EOF) {
		if (character == '\n') ++counter;
	}
	printf("%d\n", counter);

	return 0;
}
