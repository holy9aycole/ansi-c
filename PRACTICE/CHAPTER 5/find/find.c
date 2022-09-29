/********************************************************
 * find --	Programa que imprime lineas que cumplen un patron desde el 1er arg
********************************************************/
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000	/* longitud maxima de una linea */

int get_line (char *line, int max);

int main (int argc, char *argv[]) {
	char line[MAXLINE];	/* linea leida */
	long lineno;	/* numero de linea */
	int c;	/* cada una de las opciones pasadas al programa */
	char except;	/* 0: mostran lineas que cumplen patron, 1: mostrar lineas
					   que no cumplen el patron */
	char number;	/* 0: no mostrar numero de linea, 1: mostrar numero de
					   linea */
	int found;	/* numero de lineas encontradas que cumplen el patron */

	lineno = 0;
	except = number = found = 0;

	while (--argc > 0 && (*++argv)[0] == '-' ) {
		while ((c = *++argv[0]))
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: opcion ilegal '%c'\n", c);
					argc = 0;
					found = -1;
					break;
			}

	}
	if (argc != 1)
		printf("Uso: find [-x] [-n] <pattern>\n");
	else
		while (get_line(line, MAXLINE) > 0) {
			++lineno;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				++found;
			}
		}

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
