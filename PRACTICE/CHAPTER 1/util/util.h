/********************************************************
 * Archivo de definición de la libreria util
********************************************************/

/*
 * get_line: lee la entrada del usuario linea por linea y devuelve la longitud
 * de la linea leida.
 *
 * Parameters:
 *		line	Array de caracteres donde escribir la linea leida.
 *		max		Cantidad máxima de caracteres a leer en cada linea.
 *
 * Return:
 *		tamaño de la linea leida
 */
int get_line (char line[], int max);

/*
 * trim: elimina espacios o tabulaciones existentes al inicio o final de una
 * cadena de caracteres
 *
 * Parameters:
 *		string -	cadena de caracteres a procesar
 */
char * trim (char string[]);

/*
 * trimleft: elimina espacios o tabulaciones existentes al inicio de una
 * cadena de caracteres
 *
 * Parameters:
 *		string -	cadena de caracteres a procesar
 */
char * trimleft (char string[]);


/*
 * trimright: elimina los espacios o tabulaciones existentes al final de una
 * cadena de caracteres
 *
 * Parameters:
 *		string -	cadena de caracteres a procesar
 */
char * trimright (char string[]);

/*
 * find_non_space: busca el primer caracter que no es un espacio, una
 * tabulcación o un salto de linea, dentro del string y retorna su posicion
 *
 * Parameters:
 *		line	string donde realizar la busqueda
 *		start	posicion de partida donde iniciar la busqueda
 *		end		posicion limite donde finalizar la busqueda
 *
 * Return:
 *		indice del caracter no espacio encontrado o -1 (Not Found).
 */
int find_non_space (char line[], int start, int end);
