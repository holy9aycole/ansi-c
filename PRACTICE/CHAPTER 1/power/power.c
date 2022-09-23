/********************************************************
 * power -- Programa que calcula una expresion exponencial
********************************************************/
#include <stdio.h>

int power (int base, int unsigned exponent);

int main () {
	int unsigned i;	/* contandor del bucle for */

	for (i = 0; i < 10; ++i) {
		printf("%6d %6d %6d\n", i, power(2, i), power(-3, i));
	}

	return 0;
}

/*
 * power: funcion que calcula la expresion exponencial dado una base entera y
 * un exponente entero positivo.
 *
 * Parameters:
 *		base		numero base de la expresion exponencial
 *		exponent	numero exponente de la expresion exponencial
 *
 *	Return:
 *		el resultado de la expresion exponencial
 */
int power (int base, int unsigned exponent) {
	int i;	/* contador de bucle for */
	int product;	/* producto acumulador de la base */

	product = 1;
	for (i = 1; i <= exponent; ++i) {
		product *= base;
	}

	return product;
}
