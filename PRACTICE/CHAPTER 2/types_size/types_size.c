/********************************************************
 * types_size --	Programa que imprime por consola el rango (de bytes) de
 * los tipos básicos: char, short, int y long. Tanto con el modificador signed
 * como con el modificador unsigned
********************************************************/
#include <stdio.h>
#include <limits.h>

int main () {
	int integer = 45L;
	short short_integer = 10L;
	long long_integer = 4563L;
	char character = 'a';

	printf("integer: %lu, short: %lu, long: %lu, char: %lu", sizeof(integer),
			sizeof(short_integer), sizeof(long_integer), sizeof(character));

	printf("MIN INTEGER: %d, MAX INTEGER: %d\n", INT_MIN, INT_MAX);
}
