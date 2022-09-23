/********************************************************
 * longest_line	--	Programa que obtiene un texto (una cadena de lineas)
 * e imprime la linea más larga
********************************************************/
#include <stdio.h>

#define MAX_CHARACTER 1000	/* caracteres máximo de una linea */

int get_line (char line[], int maxline);
void copy (char to[], char from[]);

int main () {
	int len;	/* tamaño de la linea actual */
	int max;	/* tamaño máximo visto hasta ahora */
	char line[MAX_CHARACTER];	/* linea actual */
	char longest[MAX_CHARACTER];	/* linea más larga visto hasta ahora */

	max = 0;
	while ((len = get_line(line, MAX_CHARACTER)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)	/* si hay alguna linea */
		printf("%s\n", longest);

	return 0;
}

/*
 * get_line --	lee una linea de la entrada del usuario y devuelve su longitud
 *
 * Parameters:
 *		line -	variable donde se guarda la linea leída
 *		maxline -	tamaño máximo que ha de tener una linea
 *
 *	Return:
 *		la longitud de la linea leída
 */
int get_line (char line[], int maxline) {
	char character;	/* caracter introducido */
	int i;	/* contador del bucle */

	for (i = 0;
		i < maxline - 1 && (character = getchar()) != EOF && character != '\n';
		++i) {
		line[i] = character;
	}

	if (character == '\n') {
		line[i] = character;
		++i;
	}

	line[i] = '\0';

	return i;
}

/*
 * copy --	copia un array de caracteres 'from' a un array de caracteres 'to'
 *
 * Parameters:
 *		to -	array de caracteres destino
 *		from -	array de caracteres fuente
 */
void copy (char to[], char from[]) {
	int i;	/* contador de bucle */

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
