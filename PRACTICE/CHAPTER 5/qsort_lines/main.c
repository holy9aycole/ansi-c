/********************************************************
 * qsort_lines --	Programa que toma una serie de lineas de texto y los ordena
 * alfabéticamente de menor a mayor
********************************************************/

#include <stdio.h>
#include <string.h>
#include "./qsort_lines.h"

#define MAXLINES 5000	/* Numero maximo de lineas a ser ordenadas */

char *linesptr[MAXLINES];	/* puntero a las lineas de texto */


int main (void) {
	int nlines;	/* numero de lineas leidas de la entrada */

	if ((nlines = readlines(linesptr, MAXLINES)) >= 0) {
		qsort(linesptr, 0, nlines - 1);
		writelines(linesptr, nlines);
		return 0;
	} else {
		printf("error: entrada demasiado grande para ordenar\n");
		return 1;
	}
}

