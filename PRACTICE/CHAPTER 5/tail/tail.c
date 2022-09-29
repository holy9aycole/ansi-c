/********************************************************
 * tail --	Muestra las 10 o n ultimas lineas de una entrada de texto
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100	/* numero maximo de lineas a leer */
#define LEN 100	/* longitud maxima de una linea */

int readlines (char *lineptr[], int nlines);
void writelines (char *lineptr[], int nlines, int n);

int main (int argc, char *argv[]) {
	int nlines;	/* cantidad de lineas leidas */
	char *lineptr[MAXLINE];
	int number;	/* cantidad de lineas a mostrar */

	number = (argc == 2 && (*++argv)[0] == '-') ? atoi(++argv[0]) : 10;

	if ((nlines = readlines(lineptr, MAXLINE)) > 0) {
		writelines(lineptr, nlines, number);
	} else {
		printf("error: demasiadas lineas a procesar\n");
		return -1;
	}
}

/* readlines: leer de la entrada del usuario lineas de texto */
int readlines (char *lineptr[], int max) {
	char line[LEN];	/* linea leida */
	int len;	/* longitud de la linea leida */
	char *p;	/* puntero a la linea leida */
	int nlines;	/* numero de lineas leidas */
	int get_line (char line[], int max);

	nlines = 0;
	while ((len = get_line(line, LEN)) > 0) {
		if (len >= LEN || (p = malloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines: imprime por la salida estandar las n ultimas lineas */
void writelines (char *lineptr[], int nlines, int n) {
	lineptr += nlines - 1;

	for (;nlines > 0 && n > 0; --nlines, --n)
		printf("%s\n", *lineptr--);
}

/*
 * get_line: procesa la entrada del usuario linea por linea
 *
 * Parameters:
 *		s		string donde guardar la linea
 *		max		longitud maxima a de cada linea
 * Return:
 *		longitud de la linea procesada
 */
int get_line (char *s, int max) {
	char *tmp;	/* puntero al incio de s */

	tmp = s;
	for (; max - 1 > 0 && (*s = getchar()) != EOF && *s != '\n'; ++s, --max)
		;
	if (*s == '\n') {
		--max;
		++s;
	}

	*s = '\0';

	return s - tmp;
}
