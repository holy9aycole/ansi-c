/********************************************************
 * atof --	Programa que convierte una array de carateres de numeros en un
 * numero decimal (double).
 *
********************************************************/
#include <stdio.h>
#include <ctype.h>

#define LENGTH 100	/* Tamaño de cada linea */

/* Calculadora basica */
int main (void) {
	char s[LENGTH];	/* linea de entrada */
	double sum;	/* acumulador */
	int get_line (char [], int);
	double atof (char []);

	sum = 0;
	while (get_line(s, LENGTH) > 0)  {
		printf("%g\n", sum = atof(s));
	}

	return 0;
}

/*
 * atof: convierte una cadena de caracteres en un numero double
 *
 * Procedimiento: 56.1 = 561 / 10
 *
 * Parameters:
 *		s	cadena de caracteres
 *
 * Return:
 *		numero decimal (double)
 */
double atof (char s[]) {
	double val;	/* el numero sin el punto decimal (561) */
	double power;	/* potencia en base 10 (10) */
	int i;	/* contador de caracteres */
	int notation_sign;	/* signo de la notacion */
	int notation_number;	/* numero de la notacion */
	int sign;	/* signo del numero */

	for (i = 0; isspace(s[i]); ++i)	/* omitir espacios en blanco */
		;
	sign = (s[i] == '-') ? -1 : 1;	/* tomar el signo del numero */
	if (s[i] == '+' || s[i] == '-')	/* saltar la posicion del signo */
		++i;
	for (val = 0.0; isdigit(s[i]); ++i)	/* obtener la parte entera del numero */
		val = val * 10 + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; isdigit(s[i]); ++i) {	/* obtener la parte decimal */
		val = val * 10 + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e') {
		++i;	/* saltar la posicion de 'e' (la notacion) */
		notation_sign = (s[i] == '-') ? -1 : 1;	/* signo que sigue a la 'e' */
		++i;	/* saltar la posicion del signo */
		/* tomar el numero de la notacion */
		for (notation_number = 0; isdigit(s[i]); ++i)
			notation_number = notation_number * 10 + (s[i] - '0');
		if (notation_sign < 0)
			for (; notation_number > 0 ; --notation_number)
				power *= 10.0;
		else
			for (; notation_number > 0 ; --notation_number)
				power /= 10.0;
	}

	return sign * val / power;
}

/*
 * get_line: procesa la entrada del usuario linea por linea
 *
 * Parameters:
 *		s		string donde guardar la linea
 *		lim		longitud maxima a de cada linea
 *
 * Return:
 *		longitud de la linea procesada
 */
int get_line (char s[], int lim) {
	int i;	/* contador de bucle for */
	int c;	/* cada caracter insertado */

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}
