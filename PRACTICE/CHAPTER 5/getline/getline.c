/********************************************************
 * getline --	Implementacion de la funcion getline haciendo uso de punteros
********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100	/* Tamaño del string */

int main (void) {
	char *s;	/* string que guarda la linea */
	int len;	/* longitud del string */
	int get_line (char *, int);

	s = malloc(LENGTH);

	len = get_line(s, LENGTH);

	printf("%d: %s\n", len, s);

	free(s);

	return 0;
}

int get_line (char *s, int max) {
	for (; max - 1 > 0 && (*s = getchar()) != EOF && *s != '\n'; ++s, --max)
		;
	if (*s == '\n') {
		--max;
		++s;
	}

	*s = '\0';

	return LENGTH - max;
}
