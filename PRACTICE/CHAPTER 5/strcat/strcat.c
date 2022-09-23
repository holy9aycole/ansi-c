/********************************************************
 * strcat --	Programa que simula el funcionamiento de strcat
********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
	void str_cat (char *, char *);
	char *s;	/* puntero del string fuente */
	char *t;	/* puntero del string a concatenar */

	s = malloc(50);

	t = "World";

	str_cat(s, "Hello ");
	str_cat(s, t);
	printf("%s\n", s);

	free(s);

	return 0;
}

void str_cat (char *s, char *t) {
	while (*s != '\0')
		s++;

	while ((*s++ = *t++) != '\0')
		;
}
