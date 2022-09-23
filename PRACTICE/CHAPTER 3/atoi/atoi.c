/********************************************************
 * atoi: convierte un string s a un entero. Versionn 2
********************************************************/
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100	/* tamaño de una linea */

int main () {
	int atoi (char []);

	char line[MAXLINE];	/* linea procesada */
	int integer;	/* numero entero obtenido */

	fgets(line, sizeof(line), stdin);
	integer = atoi(line);

	printf("%d\n", integer);

	return 0;
}

int atoi (char string[]) {
	int i;	/* contador de bucle */
	int n;	/* acumulador de producto */
	int sign;	/* signo del entero */

	for (i = 0; isspace(string[i]); ++i)	/* omitir espacios en blanco */
		;
	sign = (string[i] == '-') ? -1 : 1;
	if (string[i] == '-' || string[i] == '+')	/* omitir signo */
		++i;
	for (; isdigit(string[i]) == 0; ++i)	/* omitir letras */
		;
	for (n = 0; isdigit(string[i]); ++i)
		n = 10 * n + (string[i] - '0');

	return sign * n;
}
