/********************************************************
 * expand --	Programa que expande notaciones cortas como a-z a su
 * equivalencia completa abc..xyz
********************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100		/* Tamaño de string */
#define EXPAND	1	/* la notacion puede ser expandida */
#define NON_EXPAND 0	/* la notacion no puede ser expandida */

int main (int argc, char *argv[]) {
	void text_procesing (char [], char []);
	char s1[MAXLINE];;
	char s2[MAXLINE * 2];

	if (argc != 2) {
		fprintf(stderr, "MALA ENTRADA:\n"
						"\tUse: expand <notacion corta>\n");
		exit(1);
	}

	strcpy(s1, argv[1]);

	text_procesing(s1, s2);


	printf("%s\n", s2);

	return 0;
}

/*
 * expand: expande notaciones cortas como a-z dentro del string s1 a su
 * equivalencia completa abc...xyz en el string s2
 *
 * Parameters:
 *		operand1	caracter de partida
 *		operand2	caracter final
 *		operator	operador (-)
 *		string		string donde guardar la secuencia de expansion
 *		i			indice desde donde guardar la secuencia es el string
 */
void expand (int operand1, int operand2, int operator, char string[], int *i) {
	int flag;	/* indica si la notacion puede ser expandido o no */
	int c;	/* cada caracter de la lista completa de operand1...operand2 */

	flag = NON_EXPAND;
	if (isdigit(operand1) && isdigit(operand2))
		flag = 1;
	else if (isalpha(operand1) && isalpha(operand2))
		flag = 1;
	else
		;	/* flag = 0 (valor por defecto) */

	if (flag == 0) {	/* no se expanden los caracteres */
		string[(*i)++] = operand1;
		string[(*i)++] = operator;
		string[(*i)++] = operand2;
	} else if (operand1 < operand2) {	/* se expanden los caracteres */
		for (c = operand1; c <= operand2; ++c, ++*i)
			string[*i] = c;
	} else {	/* se expanden los caracteres */
		for (c = operand1; c >= operand2; --c)
			string[*i] = c;
	}
}

void text_procesing (char s1[], char s2[]) {
	void expand (int, int, int, char[], int *);
	char shorthand[3];	/* shorthand */
	int i;	/* contador de caracteres del string s1 */
	int j;	/* contador de caracteres del string s2 */
	int k;	/* contador de caracteres del string shorthand */

	j = 0;
	k = 0;
	for (i = 0; s1[i] != '\0'; ++i) {
		if (k == 2) {	/* k == 2 (operand1 y operator ya esta definidos) */
			shorthand[k++] = s1[i];	/* guardar operand2 */
			/* expand shorthand */
			expand(shorthand[0], shorthand[2], shorthand[1], s2, &j);
			k = 0;	/* iniciar con otro shorthand */
		}
		else if (s1[i] == '-' && k == 1)  /* k == 1 (operand1 ya esta definido) */
			shorthand[k++] = s1[i]; /* guardar operator */
		else if (s1[i + 1] == '-')	/* el siguiente caracter es - */
			shorthand[k++] = s1[i];	/* guardar operand1 */
		else	/* asignar directamente a s2 */
			s2[j++] = s1[i];
	}
}
