/********************************************************
 * character_counter -- Programa que cuenta la cantidad de carateres
 * introducidos por el usuario desde el teclado.
 *
 * Version	1.0.0
********************************************************/
#include <stdio.h>

int main() {
	long counter;	/* Contador de carateres */

	counter = 0;
	while (getchar() != EOF) {
		++counter;
	}

	printf("%ld\n", counter);

	return 0;
}
