/********************************************************
 * Archivo de implementacion de la libreria util
********************************************************/
#include <stdio.h>
#include <string.h>
#include "util.h"

/*
 * get_line: lee la entrada del usuario linea por linea y devuelve la longitud
 * de la linea leida.
 */
int get_line (char line[], int max) {
	int character;	/* caracter introducido por el usuario */
	int i;	/* contador de bucle */

	i = 0;
	while (i < max - 1 && (character = getchar()) != EOF && character != '\n') {
		line[i] = character;
		++i;
	}
	if (character == '\n') {
		line[i] = character;
		++i;
	}
	line[i] = '\0';

	return i;
}

/*
 * trim: elimina espacios o tabulaciones existentes al inicio o final de una
 * cadena de caracteres
 */
char * trim (char string[]) {
	return trimright(trimleft(string));
}

/*
 * trimleft --	elimina los espacios o tabulaciones existentes al inicio de
 * una cadena de caracteres
 */
char * trimleft (char string[]) {
	while (string[0] == ' ' || string[0] == '\t')
		++string;

	return string;
}

/*
 * trimright --	elimina los espacios o tabulaciones existentes al final de
 * una cadena de caracteres
 */
char * trimright (char string[]) {
	int i;	/* contando de bucle */

	for (i = strlen(string) -1; i >= 0; --i)
		if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
			break;

	string[i + 1] = '\0';

	return string;
}

/*
 * find_non_space: busca el primer caracter que no es un espacio, una
 * tabulcación o un salto de linea, dentro del string y retorna su posicion
 */
int find_non_space (char line[], int start, int end) {
	int i;	/* contador de bucle */

	for (i = start; i < end; ++i) {
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break;
	}

	if (i == end)	/* se ha terminado el bucle: caracter no encontrado */
		return -1;
	else
		return i;
}
