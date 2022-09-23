/********************************************************
 * htoi --	Programa para convertir una cadena de dígitos hexadecimales a su
 * valor equivalente en entero (decimal).
 *
 * Uso:
 *		./htoi <hex> [<hex>]
********************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int digit;	/* valor entero de cada caracter hexadecimal */
	int i;	/* contador de bucle for */
	int decimal;	/* equivalencia en decimal del numero hexadecimal */
	int n_hex;	/* cantidad de numeros hexadecimales a procesar */
	char *hex;	/* numero hexadecimal a procesar en cada momento */

	int digit_hex (int hex);

	if (argc < 2) {
		fprintf(stderr, "Mala entrada\n"
						" Use: %s <hex> [<hex>]\n", argv[0]);
		exit(1);
	}


	for (n_hex = argc - 1; n_hex > 0; --n_hex) {
		hex = argv[n_hex];
		decimal = 0;
		for (i = 0; hex[i] != '\0'; ++i) {
			digit = digit_hex(hex[i]);
			decimal += digit * pow(16, i);
		}

		printf("%s -> %d\n", hex, decimal);
	}

	return 0;
}

/*
 * digit_hex: devuelve el valor entero de un caracter hexadecimal
 *
 * Parameters:
 *		hex -	caracter hexadecimal
 *
 * Return:
 *		valor entero del caracter
 *
 * Uso:
 *		digit_hex('1') -> 1
 *		digit_hex('8') -> 8
 *		digit_hex('a') -> 10
 *		digit_hex('F') -> 15
 */
int digit_hex (int hex) {
	int digit;	/* valor entero del caracter hexadecimal */

	switch (hex) {
		case 'a':
		case 'A':
			digit = 10;
			break;
		case 'b':
		case 'B':
			digit = 11;
			break;
		case 'c':
		case 'C':
			digit = 12;
		case 'd':
		case 'D':
			digit = 13;
		case 'e':
		case 'E':
			digit = 14;
			break;
		case 'f':
		case 'F':
			digit = 15;
			break;
		default: /* 1, 2, 3, 4, 5, 6, 7, 8, 9 */
			digit = hex - '0';
	}

	return digit;
}
