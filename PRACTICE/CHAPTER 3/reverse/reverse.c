/********************************************************
 * reverse --	Programa que invierte un string
********************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINE 100	/* Tamaño del string */

char s[MAXLINE];	/* string a invertir */

int main () {
	void reverse (void);
	void reverse2 (char [], int, int);
	clock_t begin;	/* tiempo de inicio */
	clock_t end;	/* tiempo de cierre */
	double timestamp;	/* tiempo transcurrido (en milisegundos) */

	/* strcpy(s, "HOLA MUNDO"); */

	fgets(s, sizeof(s), stdin);

	begin = clock();
	/* reverse2(s, 0, strlen(s) - 1); */
	/* reverse2(s, 6, strlen(s) - 1); */
	reverse();
	end = clock();
	timestamp = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%s\n", s);
	printf("%f\n", timestamp);

	return 0;
}

#define swap(t, x, y) { \
	t = x; \
	x = y; \
	y = t; \
}

/*
 * reverse: invierte un string dado
 */
void reverse () {
	extern char s[MAXLINE];
	int c;	/* cada caracter del string */
	int i;	/*  */
	int j;	/*  */

	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		if (s[i] == '\n')	/* ignorar saltos de linea */
			continue;
		/* Cambiar posicion del caracter */
		swap(c, s[i], s[j]);
		/* c = s[i]; */
		/* s[i] = s[j]; */
		/* s[j] = c; */
	}
}

/*
 * reverse: invierte un string dado utilizando recursion
 *
 * Parameters:
 *		start	posicion de partida
 *		start	posicion de final
 */
void reverse2 (char string[], int start, int end) {
	int tmp;	/* variable temporal para cambiar caracter */

	if (start < end) {
		reverse2(string, start + 1, end - 1);
	}
	/* cambiar caracter */
	tmp = *(string + start);
	*(string + start) = *(string + end);
	*(string + end) = tmp;
}
