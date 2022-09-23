/********************************************************
 * trim --	Toma una linea de entrada y elimina los espacios o tabulaciones
 * al inicio y al final de la linea
********************************************************/
#include <stdio.h>
#include "../util/util.h"

#define MAXLINE 1000	/* tamaño máximo de una linea */
#define TRIM_START 1	/* eliminando espacios al inicio de linea */
#define TRIM_END -1		/* eliminando espacios al final de linea */

int main () {
	char line[MAXLINE];	/* linea insertada por el usuario */
	int len;		/* longitud de la linea actual */
	char *trim_line;	/* linea con los espacios removidos al inicio y final */

	while ((len = get_line(line, MAXLINE)) > 0) {
		/* trim_line = trim(line); */
		trim_line = trimright(line);
		printf("%s", trim_line);
	}

	return 0;
}
