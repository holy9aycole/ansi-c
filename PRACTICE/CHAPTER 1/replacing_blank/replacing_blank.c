/********************************************************
 * replacing_blank --	Programa que reemplaza cada cadena de uno o mas
 * espacios por un solo espacio
********************************************************/
#include <stdio.h>

#define SPACE 1			/* dentro de una cadena de espacio */
#define NON_SPACE 0		/* fuera de una cadena de espacio */

int main () {
	int character;	/* caracter introducido */
	short flag;		/* bandera que se enciende cuando se encuentra un espacio */

	flag = NON_SPACE;

	while ((character = getchar()) != EOF) {
		/* si se encuentra un espacio y la bandera esta encendida: */
		if (character == ' ' && flag == SPACE) {
			continue;	/* se omite el espacio en la salida */
		}
		/* si se encuentra un espacio y la bandera esta apagada: */
		else if (character == ' ' && flag == NON_SPACE) {
			flag = 1;	/* se enciende la bandera */
			putchar(character);	/* se imprime el espacio en la salida */
		}
		/* se se encuentra un caracter diferente de espacio: */
		else if (character != ' ') {
			flag = NON_SPACE;	/* se apaga la bandera */
			putchar(character);	/* se imprime el caracter */
		}
	}

	return 0;
}
