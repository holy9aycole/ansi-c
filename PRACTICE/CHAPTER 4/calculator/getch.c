#include <stdio.h>
#define BUFSIZE 100	/* tamaño del bufer */

static char buf[BUFSIZE];	/* bufer para ungetch */
static int bufp;	/* siguiente posicion libre en buf */

/*
 * getch: lee un caracter de la entrada o del bufer
 */
int getch (void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * ungetch: escribe un caracter en el bufer
 */
void ungetch (int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: demasiados caracteres\n");
	else
		buf[bufp++] = c;
}
