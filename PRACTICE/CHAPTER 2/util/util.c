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
	int len;	/* longitud de la cadena de caracteres a procesar */

	len = strlen(string) - 1;
	for (i = 0; string[len - i] == ' ' || string[len - i] == '\t'; ++i) {
		string[len - i] = '\0';
	}

	return string;
}

/*
 * atoi: convierte una cadena de caracteres a entero
 */
int atoi (const char s[]) {
	int i;	/* contador de bucle for */
	int n;	/* acumulador */

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = n * 10 + (s[i] - '0');
	}

	return n;
}


/*
 * squeeze: elimina cualquier caracter del string s1 que aparezca en el string
 * s2
 */
void squeeze (char s1[], char s2[]) {
	int i;	/* contador de bucle for */
	int j;	/* indice de caracteres del array s1 */
	int k;	/* indice de caracteres del array s2 */
	int len_s2;	/* longitud del string s2 */

	len_s2 = strlen(s2);
	for (i = j = 0; s1[i] != '\0'; ++i) {
		for (k = 0; s2[k] != '\0'; ++k) {
			/* si el caracter de s1 es igual al caracter de s2, rompemos el
			 * bucle */
			if (s1[i] == s2[k])
				break;
		}
		/* validamos si el bucle se ha roto precipitadamente o ha llegado al
		 * final */
		if (k == len_s2) /* el bucle a terminado su ejecucion de manera normal*/
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}


/*
 * substring: elimina el string s2 dentro del string s1
 */
int substring (char s1[], char s2[]) {

	return 0;
}
