#include <ctype.h>

/*
 * atof: convierte una cadena de caracteres en un numero double
 *
 * Parameters:
 *		s	cadena de caracteres
 *
 * Return:
 *		numero decimal (double)
 */
double atof (const char s[]) {
	double val;	/* el numero sin el punto decimal (561) */
	double power;	/* potencia en base 10 (10) */
	int i;	/* contador de caracteres */
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


	return sign * val / power;
}
