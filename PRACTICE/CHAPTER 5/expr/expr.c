/********************************************************
 * expr --	fork del programa expr de UNIX con el formato reverse Polish
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "./expr.h"
#include <math.h>

int main (int argc, char *argv[]) {
	/* segundo operando. Para el caso que no se aplique conmutacion de
	 * operandos: resta (-) y division (/) */
	double op2;

	if (argc < 3) {
		printf("Uso: expr <operand> [operand] <operator>\n");
		return -1;
	}
	/* else: */
	while (--argc > 0) {
		if (atoi(*++argv) != 0 || isdigit((*argv)[0])) {	/* operando */
			push(atof(*argv));
		} else	/* operador */ {
			/* operadores complejos */
			if (strcmp(*argv, "**") == 0) {
				op2 = pop();
				push(pow(pop(), op2));
			} else if (strcmp(*argv, "sin") == 0)
				push(sin(pop() * M_PI / 180));
			else if (strcmp(*argv, "cos") == 0)
				push(cos(pop() * M_PI / 180));
			else if (strcmp(*argv, "tan") == 0)
				push(tan(pop() * M_PI / 180));
			else
				switch ((*argv)[0]) {	/* operadores simples */
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
					default:
						printf("error: comando desconocido '%s'\n", *argv);
						break;
				}
		}
	}

	push(op2 = pop());
	printf("------------\n");
	printf("\t%.8g\n", op2);

	return 0;
}
