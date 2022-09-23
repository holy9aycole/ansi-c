#define NUMBER '0'	/* señal de que un numero ha sido encontrado */

/*
 * push: añadir (o empujar) un valor dentro del stack
 *
 * Parameters:
 *		f	valor a añadir
 */
void push (double);

/*
 * pop: tomar un valor del stack
 *
 * Return:
 *		último valor añadido al stack
 */
double pop (void);

/*
 * getop: obtener el siguiente operador u operando numerico
 *
 * Parameters:
 *		s	string donde guardar el operando
 *
 * Return:
 *		operando
 */
int getop (char []);

/*
 * getch: lee un caracter de la entrada o del bufer
 *
 * Return:
 *		caracter leido
 */
int getch (void);

/*
 * ungetch: escribe un caracter en el bufer
 *
 * Parameters:
 *		c	caracter a escribir
 */
void ungetch (int);
