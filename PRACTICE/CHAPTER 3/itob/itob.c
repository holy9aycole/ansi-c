/********************************************************
 * itob --	Programa que convierte un numero entero a una representacion de
 * caracteres en la base especificada
********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 20	/* tamaño del string */

int main (int argc, char *argv[]) {
	int n;	/* numero entero a transformar */
	int b;	/* base en la que transformar el entero */
	char s[LENGTH];
	void itob (int, char [], int);

	if (argc == 2)	/* sin no se ha especificado la base */
		b = 2;	/* base = 2 (representacion binaria) */
	else if (argc == 3)
		b = atoi(argv[2]);
	else {
		fprintf(stderr, "Uso incorrecto\n"
						"\t Use: ./itob <entero> <base>\n");
		exit(1);
	}

	n = atoi(argv[1]);

	itob(n, s, b);

	printf("%d base %d: %s\n", n, b, s);

	return 0;
}

/*
 * itob: convierte un entero a un representacion de caracteres en la base
 * especificada.
 *
 * Parameters:
 *		n	numero entero
 *		s	cadena de caracteres donde guardar la representacion
 *		b	base utilizada para la convercion
 */
void itob (int n, char s[], int b) {
	int i;	/* indece de caracteres del string s */
	int sign;	/* signo del numero entero */
	int modulus;	/* resto de la division */
	void reverse (char []);
	void special_base (char [], int *, int);

	if ((sign = n) < 0)	/* si el numero entero es negativo */
		n = -n;	/* convertir a positivo */

	i = 0;
	do {
		if ((modulus = n % b) > 9)
			s[i++] = 'a' + (modulus - 10);
		else
			s[i++] = n % b + '0';
	} while ((n /= b) > 0);

	special_base(s, &i, b);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

/*
 * reverse: invierte un string dado
 */
void reverse (char s[]) {
	int c;	/* cada caracter del string */
	int i;	/*  */
	int j;	/*  */

	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		/* Cambiar posicion del caracter */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/*
 * special_base: añade prefijos para las base especiales.
 *
 * Parameters:
 *		s	string donde guardar el prefijo
 *		i	apuntador del indice del string
 *		b	base
 *
 * Uso:
 *   base 16 -> 0x
 *   base 8 -> o
 *
 */
void special_base (char s[], int * i, int b) {
	switch (b) {
		case 16:
			s[(*i)++] = '0';
			s[(*i)++] = 'x';
			break;
		case 8:
			s[(*i)++] = 'o';
			break;
		default:
			;	/* no hay prefijo definido */
	}
}
