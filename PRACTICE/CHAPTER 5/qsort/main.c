/********************************************************
 * qsort --	Version mejorada del programa qsort_lines. Se permite ahora pasar
 * diferentes opciones al programa
********************************************************/

#include <stdio.h>
#include <string.h>
#include "./qsort.h"
#define MAXLINES 5000	/* #lineas máxima a ser ordernadas  */

char *lineptr[MAXLINES];	/* puntero al texto de lineas */

int main (int argc, char *argv[]) {
	int nlines;	/* numero de lineas leidas */
	int i, j;	/* contadores de bucle for para leer las opciones */
	char c;	/* cada opcion pasado al programa */
	int numeric = 0;	/* 1 ordenar numericamente */
	int reverse = 0;	/* 1 ordenar decrecientemente (inverso)  */
	int fold = 0;		/* 1 considerar mayuscula y minuscula igual (a == A) */

	for (i = 1; i < argc && argv[i][0] == '-'; ++i)
		for (j = 1; (c = argv[i][j]); ++j)
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				case 'f':
					fold = 1;
					break;
				default:
					printf("qsort: opcion ilegal '%c'\n", c);
					argc = -1;
					break;
			}

	if (argc == -1)
		printf("Uso: qsort [-n] [-r]\n");
	else if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines - 1,
				(int (*)(void *, void *))(numeric ? numcmp : fold ? strcasecmp
					: strcmp), reverse);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("entrada muy grande para ordenar\n");
		return 1;
	}
}
