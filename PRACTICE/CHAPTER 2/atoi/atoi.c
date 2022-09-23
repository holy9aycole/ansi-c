/********************************************************
 * atoi --	Programa que convierte una cadena de caracteres a numero entero
********************************************************/
#include <stdio.h>
#include "../util/util.h"

#define STRING_LENGTH 100	/* tamaño máxima del string */

int main () {
	int character;	/* caracter introducido */
	char string[STRING_LENGTH];	/* cadena de caracteres */
	int i;	/* contador de bucle */
	int integer;	/* numero entero procesado de la cadena */

	i = 0;
	while ((character = getchar()) != EOF && character != '\n') {
		string[i] = character;
		++i;
	}

	integer = atoi(string);

	printf("%d\n", integer);
}
