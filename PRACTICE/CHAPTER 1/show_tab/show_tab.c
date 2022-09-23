/********************************************************
 * show_tab --	Programa que muestra las tabulaciones con el caracter \t,
 * los retrocesos (backspace) con \b y la barra invertida con \\
********************************************************/
#include <stdio.h>

int main () {
	int character;	/* caracter introducido */

	while ((character = getchar()) != EOF) {
		if (character == '\t') {
			/* si el caracter es una tabulacion: */
			printf("\\t");	/* se imprime \t */
		} else if (character == '\b') {
			/* si el caracter es un retroceso: */
			printf("\\b");	/* se imprime \b */
		} else if (character == '\\') {
			/* si el caracter es una barra invertida: */
			printf("\\\\");	/* se imprime \\ */
		} else {
			putchar(character);	/* los demas caracteres se imprimen tal cual */
		}
	}

	return 0;
}
