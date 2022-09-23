/********************************************************
 * itoa --	Programa que convierte un numero entero a una cadena de caracteres
********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 11	/* Tamaño de la cadena de caracteres */
#define MAXLINE 100	/* Tamaño del string */

int main (int argc, char *argv[]) {
	int n;	/* numero a convertir */
	char s[MAX_STRING + 1];	/* cadena de caracteres donde guardar la convercion */
	int i;	/* contador para iterear las entradas del usuario */
	int width;	/* tamaño minimo de los numeros */
	void itoa (int, char []);
	void itoma (int, char [], int);

	if (argc < 3) {
		fprintf(stderr, "Uso incorrecto\n"
						"\t Use: ./itoa <width> <numero> [<numero>] ...\n");
		exit(1);
	}

	width = atoi(argv[1]);
	printf("%s\n", argv[2]);
	for (i = 2; i < argc; ++i) {
		n = atoi(argv[i]);
		itoma(n, s, width);
		printf("%s\n", s);
	}

	return 0;
}

/*
 * itoa: convierte un numero entero en un array de caracteres
 *
 * Parameters:
 *		n	numero entero
 *		s	array de caracteres
 */
void itoa (int n, char s[]) {
	int i;	/* contador de bucle */
	int sign;	/* signo del numero entero */
	void reverse (char []);

	if ((sign = n) < 0)	/* guardar el signo del numero */
		n = -n;	/* hacer que n sea positivo */

	i = 0;
	do {	/* generar digitos en orden reverso */
		s[i++] = n % 10 + '0';	/* obtener siguiente digito */
	} while ((n /= 10) > 0);	/* eliminarlo */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

/*
 * itoma: convierte un numero entero en un array de caracteres de un tamaño
 * mínimo de width, los espacios vacios a la izquierda serán llenados con
 * espacios en blanco si es necesario.
 */
void itoma (int n, char s[], int width) {
	int i;	/* contador de bucle */
	int sign;	/* signo del numero entero */
	void reverse (char []);

	if ((sign = n) < 0)	/* guardar el signo del numero */
		n = -n;	/* hacer que n sea positivo */

	i = 0;
	do {	/* generar digitos en orden reverso */
		s[i++] = n % 10 + '0';	/* obtener siguiente digito */
	} while ((n /= 10) > 0);	/* eliminarlo */

	if (sign < 0)
		s[i++] = '-';

	for (; i < width; ++i)	/* llenar con espacios en blanco */
		s[i] = ' ';

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
