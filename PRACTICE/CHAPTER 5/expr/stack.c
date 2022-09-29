#include <stdio.h>
#include "./expr.h"
#define MAXVAL 100	/* profundidad máxima del stack */

static int sp = 0;	/* siguiente posicion libre del stack */
static double val[MAXVAL];	/* valores del stack */

/*
 * push: añadir (o empujar) un valor dentro del stack
 */
void push (double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack lleno, no se puede añadir %g\n", f);
}

/*
 * pop: tomar un valor del stack
 */
double pop (void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack vacio\n");
		return 0.0;
	}
}
