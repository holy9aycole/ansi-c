/********************************************************
 * wc -- Programa que cuenta la cantidad de lineas, palabras y caracteres
 * desde la entrada del usuario
********************************************************/
#include <stdio.h>

#define IN	1	/* dentro de una palabra */
#define OUT 0	/* fuera de una palabra */

int main () {
	/* contador de caracteres, palabras y lineas */
	int character_counter, word_counter, line_counter;
	int flag;	/* bandera que indica si se esta dentro o fuera de una palabra */
	int character;	/* caracter introducido */

	character_counter = word_counter = line_counter = 0;
	flag = OUT;

	while ((character = getchar()) != EOF) {
		++character_counter;	/* se incrementa la cantidad de caracteres */
		if (character == '\n')
			++line_counter;	/* se incrementa la cantidad de lineas */
		if (character == ' ' || character == '\t' || character == '\n')
			flag = OUT;	/* fuera de una palabra */
		else if (flag == OUT) {
			flag = IN;	/* dentro de una palabra */
			++word_counter;	/* se incrementa la cantidad de palabras */
		}
	}

	printf("%d %d %d\n", line_counter, word_counter, character_counter);

	return 0;
}
