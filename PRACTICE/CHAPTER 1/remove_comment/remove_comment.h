#define UNDEFINED -1	/* Posicion indefinida */
#define STATE_OPEN 0	/* comentario abierto */
#define STATE_CLOSE 1	/* comentario cerrado */

typedef enum { SINGLE = 1, MULTILINE = 2 } Comment_Type;

/* Estado del comentario:
 * - abierto: solo se ha detectado la apertura del comentario
 * - cerrado: ya se ha detectado el cierre del comentario
 */
typedef int Comment_State;

typedef struct {
	int start;	/* posicion inicial */
	int end;	/* posicion final */


	/* indica si hay un caracter de escape para descartar el comentario */
	// int scape;
	/* tipo de comentario encontrado: una sola linea o multi lineal */
	// Comment_Type type;
} Comment;

/*
 * find_comment: encuentra la posicion de inicio y final de un comentario en una
 * linea dada.
 *
 * Parameters:
 *		line	linea a procesar
 *		max		tamaño máximo de linea
 *
 * Return:
 *		struct que contiene la posicion inicial y final del comentario
*/
Comment find_comment (char line[]);


/*
 * remove_string: elimina la cadena de caracteres que se encuentra entre
 * la posicion start y la posicion end.
 *
 * Parameters:
 *		line	linea a procesar
 *		start	posicion de inicio
 *		end		posicion final
 *
 * Return
 *		longitud de la nueva linea procesada
 */
int remove_string (char line[], int start, int end);
