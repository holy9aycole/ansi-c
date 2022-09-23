/********************************************************
 * find_pattern --	Programa que busca un patrón de letras dentro de un
 * conjunto de lineas
********************************************************/
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000	/* longitud máxima por linea de entrada */

int get_line (char line[], int max);
int strindex (char source[], char searchfor[]);
int strrindex (char source[], char searchfor[]);

char pattern[] = "ould";	/* patron de busqueda */

int main (void) {
	char line[MAXLINE];
	int found;	/* indica si se ha encontrado o no el patron en una linea */
	int index;	/* indice  */

	while (get_line(line, MAXLINE) > 0)
		/* if ((index = strindex(line, pattern)) >= 0) { */
		if ((index = strrindex(line, pattern)) >= 0) {
			printf("%s", line);
			printf("%d\n", index);
			++found;
		}

	return found;
}

/*
 * get_line: procesa la entrada del usuario linea por linea
 *
 * Parameters:
 *		s		string donde guardar la linea
 *		lim		longitud maxima a de cada linea
 *
 * Return:
 *		longitud de la linea procesada
 */
int get_line (char s[], int lim) {
	int i;	/* contador de bucle for */
	int c;	/* cada caracter insertado */

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/*
 * strindex: encuentra el string t dentro del string s
 *
 * Parameters:
 *		s	string fuente
 *		t	string a buscar
 *
 * Return:
 *		indice del string t en s, o -1 si no se encuentra
 */
int strindex (char s[], char t[]) {
	int i;	/* contador del string s */
	int j;	/* contador del string t */

	for (i = 0; s[i] != '\0'; ++i) {
		for (j = 0; t[j] != '\0' && t[j] == s[i + j]; ++j)
			;
		if (j > 0 && t[j] == '\0')
			return i;
	}

	return -1;
}

/*
 * strrindex: encuentra la ocurrencia, mas a la derecha, del string t en s
 *
 * Parameters:
 *		s	string fuente
 *		t	string a buscar
 *
 * Return:
 *		indice del string t en s, o -1 si no se encuentra
 */
int strrindex (char s[], char t[]) {
	int i;	/* contador del string s */
	int j;	/* contador del string t */
	int k;	/* contador del string t empezando en cero */

	for (i = strlen(s) - 1; i > 0; --i) {
		for (j = strlen(t) - 1, k = 0; j > 0 && t[j] == s[i - k]; --j, ++k)
			;
		if (j == 0)
			return i - k;
	}

	return -1;
}
