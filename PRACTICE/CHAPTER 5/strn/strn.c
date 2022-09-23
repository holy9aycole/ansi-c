/********************************************************
 * strn --	Programa que implementa las funciones strncpy, strncat, strncmp
********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
	void strn_cpy (char *, char *, int);
	void strn_cat (char *, char *, int);
	int strn_cmp (char *, char *, int);

	char *s;	/* string fuente */
	char *t;	/* string target */

	t = "Hola";

	s = malloc(100);

	strn_cpy(s, t, 4);
	printf("%s\n", s);

	strn_cat(s, " mundo ", 7);
	printf("%s\n", s);

	printf("%d\n", strn_cmp(s, "Hola mundo donghua", 11));
	printf("%s\n", s);

	return 0;
}

void strn_cpy (char *s, char *t, int n) {
	while ((*s++ = *t++)) {
		--n;
		if (n < 0)
			return;
	}
}

void strn_cat (char *s, char *t, int n) {
	while (*s != '\0')
		++s;
	while ((*s++ = *t++)) {
		--n;
		if (n < 0)
			return;
	}
}

int strn_cmp (char *s, char *t, int n) {
	while (*s == *t) {
		--n;
		if (n <= 0 || *t == '\0')
			return 0;
		++s;
		++t;
	}

	return *s - *t;
}
