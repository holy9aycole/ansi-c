#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "./calculator.h"
#define OPERAND 1	/* operando */
#define SIMPLE_OPERATOR 2	/* operador simple */
#define COMPLEX_OPERATOR 3	/* operador complejo */

/*
 * getop: obtener el siguiente operador u operando numerico
 */
int getop (char s[]) {
	int i;	/* contador de caracteres */
	int c;	/* cada caracter leido */
	char flag;	/* indica si se ha leido un operando o un operador */

	/* flag = SIMPLE_OPERATOR; */
	while ((s[0] = c = getch()) == ' ' || c == '\t')	/* omitir espacios */
		;
	i = 0;
	s[1] = '\0';

	if (s[0] == '\n')	/* salto de linea */
		return '\n';

	switch (c) {	/* operadores simples */
		case '-':
		case '+':
		case '*':
		case '/':
		case '%':
		case '_':
			flag = SIMPLE_OPERATOR;
			s[++i] = c = getch();	/* obtener siguiente caracter */
			if (c == '*')	/* operador ** */
				return 'p';	/* pow (potencia) */
	}


	if (isalpha(c)) { /* la entrada es una palabra */
		flag = COMPLEX_OPERATOR;
		while (isalpha(s[++i] = c = getch()))
			;
	} else if (isdigit(c)) { /* la entrada es un numero. Tomar la parte entera */
		flag = OPERAND;	/* marcar como operando */
		while (isdigit(s[++i] = c = getch())) /* obtener las cifras enteras  */
			;
		if (c == '.')	/* tomar la parte fraccionaria o decimal del numero */
			while (isdigit(s[++i] = c = getch())) /* obtener las cifras decimales */
				;
	}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	if (flag == SIMPLE_OPERATOR)
		return s[0];
	else if (flag == COMPLEX_OPERATOR)
		return '?';
	else
		return NUMBER;
}
