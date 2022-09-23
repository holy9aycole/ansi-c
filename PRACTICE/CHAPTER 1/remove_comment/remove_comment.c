#include <stdio.h>
#include "./remove_comment.h"

Comment_State comment_state = STATE_CLOSE;	/* estado del comentario: abierto o cerrado */

/*
 * find_comment: encuentra la posicion de inicio y final de un comentario en una
 * linea dada.
*/
Comment find_comment (char line[]) {
	int i;	/* contador de bucle */
	int c;	/* cada caracter de la linea */
	Comment comment;	/* posicion inicial y final de un comentario */

	comment.start = UNDEFINED;	/* posicion indefinida */
	comment.end = UNDEFINED;	/* posicion indefinida */

	for (i = 0; (c = line[i]) != '\0'; ++i) {
		if (c == '/' && line[i + 1] == '*') {
			comment_state = STATE_OPEN;
			comment.start = i;
		} else if (c == '*' && line[i + 1] == '/') {
			comment.end = i + 1;
			comment_state = STATE_CLOSE;
		}
	}

	if (comment.start == UNDEFINED && comment.end == UNDEFINED &&
			comment_state == STATE_OPEN) {
		/* Si el estado del comentario esta en abierto, impuesto por la linea
		 * anterior, eliminar toda la linea actual: */
		comment.start = 0;
		return comment;
	}

	return comment;
}


/*
 * remove_string: elimina la cadena de caracteres que se encuentra entre
 * la posicion start y la posicion end.
 */
int remove_string (char line[], int start, int end) {
	int i;	/* contador de bucle */
	int j;	/* indice del la linea */

	for (i = j = 0; line[i] != '\0'; ++i) {
		if (i >= start && i <= end)
			continue;

		line[j++] = line[i];
	}

	line[j] = '\0';

	return j;	/* longitud de la nueva linea */
}
