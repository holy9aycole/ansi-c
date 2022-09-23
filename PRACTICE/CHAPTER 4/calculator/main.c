/********************************************************
 * calculator --	Programa que simula una calculadora de las operaciones
 * matematicas basicas (+, -, *, /) utilizando la notación polaca inversa
 * (reverse polish notation) tal que la operacion
 *		(1 - 2) * (4 + 5)
 * quedaria asi
 *		1 2 - 4 5 + *
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "./calculator.h"

#define MAXOP 100	/* tamaño máximo de operandos y operadores */


int main (void) {
	int type;	/* tipo de operador */
	/* segundo operando. Para el caso que no se aplique conmutacion de
	 * operandos: resta (-) y division (/) */
	double op2;
	char s[MAXOP];	/* entrada del usuario */

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:	/* se ha insertado un operando (un numero) */
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: divisor cero\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: divisor cero\n");
				break;
			case '_':	/* Imprimir el elemento en la cima del stack */
				push(op2 = pop());
				break;
			case 'p':	/* potencia */
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '\n':
				push(op2 = pop());
				printf("------------\n");
				printf("\t%.8g\n", op2);
				break;
			case '?':	/* Operadores complejos */
				if (strcmp(s, "sin") == 0) {
					push(sin(pop() * M_PI / 180));
					break;
				} else if (strcmp(s, "cos") == 0) {
					push(cos(pop() * M_PI / 180));
					break;
				} else if (strcmp(s, "cos") == 0) {
					push(cos(pop() * M_PI / 180));
					break;
				} else if (strcmp(s, "tan") == 0) {
					push(tan(pop() * M_PI / 180));
					break;
				} else
					;/* CAER A DEFAULT */
			default:
				printf("error: comando desconocido '%s'\n", s);
				break;
		}
	}
	return 0;
}
