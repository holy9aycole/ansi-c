/********************************************************
 * detab --	Programa que reemplaza tabulaciones (tabs) en la entrada
 * con el número apropiado de espacios en blanco entre paradas de tabs
********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* cantidad de caracteres por linea */

int main (int argc, char *argv[]) {
	int TABSTOP; /* cantidad de espacio que hay en cada parada de tab */
	int character;	/* caracter introducido */
	int i;	/* contador de bucle o contador de caracteres por linea  */
	char line[MAXLINE];	/* linea procesada desde la entrada */
	int j;	/* espacio sobrante para alcalzar la siguiente parada de tab */
	int k;	/* contador de bucle anidado para situar los espacios */

	TABSTOP = (argc == 2) ? atoi(argv[1]) : 4;

	i = 0;
	while ((character = getchar()) != EOF) {
		j = TABSTOP - (i % TABSTOP);
		if (character == '\n') {
			line[i] = '\0';
			i = 0;	/* resetear el contador para procesar una nueva linea */
			printf("%s\n", line);	/* imprimir la linea procesada */
		} else if (character == '\t') {
			for (k = 0; k < j; ++k) {
				line[i] = ' ';
				/* line[i] = '\\'; */
				++i;
			}

		} else {
			line[i] = character;
			++i;
		}
	}


	return 0;
}
