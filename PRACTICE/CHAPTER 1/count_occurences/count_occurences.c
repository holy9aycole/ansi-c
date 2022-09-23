/********************************************************
 * count_occurences --	Programa que cuenta la cantidad de ocurencias de
 * cada digito, de caracteres de espacio (espacio, tabulacion, salto de linea),
 * y todos otros caracteres
********************************************************/
#include <stdio.h>

#define DIGIT_NUMBER 10	/* numero de digitos */

int main () {
	int character;	/* caracter introducido */
	int space_counter;	/* contador de espacio */
	int other_counter;	/* contador de otros caracteres */
	int digit_counter[10];	/* contador de digitos */
	int i;	/* contador de bucle for */

	space_counter = other_counter = 0;
	for (i = 0; i < 10; ++i) digit_counter[i] = 0;

	while ((character = getchar()) != EOF) {
		if (character >= '0' && character <= '9')
			++digit_counter[character - '0'];
		else if (character == ' ' || character == '\t' || character == '\n')
			++space_counter;
		else
			++other_counter;
	}

	printf("Digitos =");
	for (i = 0; i < DIGIT_NUMBER; ++i) printf(" %d", digit_counter[i]);
	printf(", Espacios = %d, Otros = %d\n", space_counter, other_counter);

	return 0;
}
