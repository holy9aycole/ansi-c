/********************************************************
 * strend --	Programa que indica si un string t aparece al final del string
 * s
********************************************************/
#include <stdio.h>
#include <string.h>

int main (void) {
	int strend (char *, char *);

	char *s = "dentro de unos meses seremos grandes investigadores";
	char *t = "grandes investigadores ";

	printf("%d\n", strend(s, t));

	return 0;
}

int strend (char *s, char *t) {
	int s_len;	/* longitud del string s */
	int t_len;	/* longitud del string t */

	s_len = strlen(s);
	t_len = strlen(t);

	/* Desde la posicion final, mover s tantos caracteres como caracteres tenga
	 * el string t */
	s += (s_len - t_len);
	while (*s++ == *t++)
		if (*t == '\0')
			return 1;

	return 0;
}
