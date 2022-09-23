#include <stdio.h>
#include <string.h>
#include "./fold.h"

#define WIDTH_SIZE	79	/* Tamaño de cada linea procesada */
#define WORD_SIZE	100	/* Tamaño de cada palabra introducido por el usuario */

/*
 * fold: pliega lineas de entrada largas dentro de dos o más linea cortas
 * después del último caracter no espacio que ocurre antes de la columna
 * enésima (n-th) de la entrada
 */
void fold () {
	char word[WORD_SIZE];	/* palabra procesada */
	int len;	/* longitud de la palabra procesada */
	int counter;	/* contador de caracteres por linea */

	counter = 0;
	while ((len = word_procesing(word, WORD_SIZE)) != -1) {
		if (len > WORD_SIZE) {	/* la palabra en mas larga que la linea */
			printf("%s", word);
			counter = 0;	/* iniciamos una nueva linea */
		} else if (counter + len > WORD_SIZE) {
			/* la palabra no quepa en la linea: */
			printf("\n");
			printf("%s", word);
			counter = 0;	/* iniciamos una nueva linea */
		} else if (word[0] == '\n') {
			printf("\n");
			counter = 0;
		} else {	/* la palabra no quepa en la linea */
			counter += len;
			printf("%s", word);
		}
	}
}
