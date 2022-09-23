#include <stdio.h>
#include <string.h>

#define MAXLEN 1000	/* longitud maxima para cada linea de entrada */

static int get_line (char *, int);
static char * alloc (int);

/*
 * readlines: leer lineas de entrada
 */
int readlines (char *linesptr[], int maxlines) {
	int len;	/* longitud de la linea leida */
	int nlines;	/* cantidad de lineas leidas */
	char *p;
	char line[maxlines];	/* linea leida */

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';	/* eliminar salto de linea */
			strcpy(p, line);
			linesptr[nlines++] = p;
		}
	}

	return nlines;
}

/*
 * get_line: leer una linea de la entrada
 *
 * Parameters:
 *		s	puntero que apunta a la linea
 *		max	tamaño máximo de la linea
 *
 * Return:
 *		longitud de la linea leida
 */
static int get_line (char *s, int max) {
	char *start;	/* posicion inicial de s */

	start = s;
	for (; max - 1 > 0 && (*s = getchar()) != EOF && *s != '\n'; ++s, --max)
		;
	if (*s == '\n') {
		--max;
		++s;
	}

	*s = '\0';

	return s - start;
}



#define ALLOCSIZE 10000	/* Tamaño del espacio disponible */

static char allocbuf[ALLOCSIZE];	/* almacenamiento para alloc */
static char *allocp = allocbuf;		/* siguiente posicion libre */

/*
 * alloc: reserva un espacio de n bytes
 *
 * Parameters:
 *		n	cantidad de bytes ha reservar
 *
 * Return:
 *		puntero a la cadena de bytes
 */
static char * alloc (int n) {	/* devuelve un puntero de n caracteres */
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* el espacio llega */
		allocp += n;
		return allocp - n;	/* inicio del espacio reservado */
	} else	/* no queda suficiente espacio */
		return 0;
}

/*
 * afree: libera el espacio reservado al que apunta el puntero p
 *
 * Parameters:
 *		p	puntero
 */
static void afree (char *p) {	/* liberar el almacenamiento apuntado por p */
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
