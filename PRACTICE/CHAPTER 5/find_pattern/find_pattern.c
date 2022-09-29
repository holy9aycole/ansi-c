/********************************************************
 * find_pattern --	Programa que busca un patrón de letras dentro de un
 * conjunto de lineas. version 2
********************************************************/
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000	/* longitud máxima por linea de entrada */

int get_line (char line[], int max);
int strindex (char source[], char searchfor[]);
int strrindex (char source[], char searchfor[]);

int main (int argc, char *argv[]) {
	char line[MAXLINE];
	int found;	/* indica si se ha encontrado o no el patron en una linea */

	if (argc != 2)
		printf("Usa: ./find <patron>\n");
	else
		while (get_line(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				++found;
			}

	return found;
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
