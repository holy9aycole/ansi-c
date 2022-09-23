/********************************************************
 * entab --	Programa reemplaza cadena de espacios por el mínimo número de
 * tabulaciones (tabs) y espacios para guardar el mismo espaciado.
********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* cantidad de caracteres por linea */

int main (int argc, char *argv[]) {
	int TABSTOP; /* cantidad de espacio que hay en cada parada de tab */
	int character;	/* caracter introducido */
	int i;	/* contador de caracteres por linea */
	int j;	/* espacio sobrante para alcalzar la siguiente parada de tab */
	char line[MAXLINE];	/* linea procesada desde la entrada */
	int n_spaces;	/* numero de espacios en blanco encontrados */
	int screenshot_j;	/* captura del estado de j al encontrar un espacio */

	TABSTOP = (argc == 2 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 4;

	i = 0;
	n_spaces = 0;
	while ((character = getchar()) != EOF) {
		j = TABSTOP - (i % TABSTOP);
		if (character == '\n') {
			line[i] = '\0';
			printf("%s\n", line);	/* imprimir la linea procesada */
			/* RESET: */
			i = 0;
			n_spaces = 0;
		} else if (character == ' ') {
			line[i] = character;
			++n_spaces;	/* mas 1 espacio encontrado */
			if (n_spaces == 1)
				screenshot_j = j;

			if (n_spaces == screenshot_j) {
				/* volver al indice del primer espacio de la serie */
				i -= (n_spaces - 1);
				line[i] = '\t';	/* reemplazar tab por espacio */
				n_spaces = 0;	/* resetear el numero de espacios a cero */
			}
			++i;
		} else {
			line[i] = character;
			n_spaces = 0;	/* resetear numero de encontrados */
			++i;
		}
	}

	return 0;
}
