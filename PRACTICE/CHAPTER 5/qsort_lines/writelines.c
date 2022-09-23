#include <stdio.h>

/*
 * writelines: escribir lineas de texto en la salida estandar
 *
 * Parameters:
 *		linesptr	lineas de texto
 *		nlines		cantidad de lineas de texto
 */
void writelines (char *linesptr[], int nlines) {
	int i;	/* contador de bucle */
	for (i = 0; i < nlines; ++i)
		printf("%s\n", linesptr[i]);
}
