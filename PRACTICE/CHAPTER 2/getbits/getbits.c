/********************************************************
 * getbits --	Programa que obtiene n bits desde la posicion p
********************************************************/
#include <stdio.h>

int main () {
	unsigned getbits (unsigned);
	unsigned getnbits (unsigned, int, int);

	printf("15 -> %u\n", getnbits(15, 4, 3));

	return 0;
}

/*
 * getbits: obtiene los n bits desde la posicion p de una numero entero
 * positivo
 *
 * Parameters:
 *		x	numero entero positivo
 *		p	posicion de inicio
 *		n	cantidad de bits a obtener
 *
 * Return:
 *		n bits desde la posicion p
 */
unsigned getnbits (unsigned x, int p, int n)  {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

/*
 * getbits: obtiene los bits de un numero positivo
 *
 * Parameters:
 *		x	numero entero positivo
 *
 * Return:
 *		bits del numero positivo
 */
unsigned getbits (unsigned x) {
	return (~0) & x;
}
