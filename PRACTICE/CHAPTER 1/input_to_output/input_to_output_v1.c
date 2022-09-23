#include <stdio.h>

int main () {
	/* copiar entrada a salida; 1era version */

	int character;	/* Caracter leido */

	character = getchar();
	while (character != EOF) {
		putchar((character = getchar()) != EOF);
	}

	return 0;
}
