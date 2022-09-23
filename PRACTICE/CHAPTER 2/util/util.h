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
 * trimleft --	elimina espacios o tabulaciones existentes al inicio de una
 * cadena de caracteres
 *
 * Parameters:
 *		string -	cadena de caracteres a procesar
 */
char * trimleft (char string[]);


/*
 * trimright --	elimina los espacios o tabulaciones existentes al final de una
 * cadena de caracteres
 *
 * Parameters:
 *		string -	cadena de caracteres a procesar
 */
char * trimright (char string[]);

/*
 * atoi: convierte una cadena de caracteres a entero
 *
 * Parameters:
 *		s -	cadena de caracteres
 *
 * Return:
 *		numero entero
 */
int atoi (const char s[]);

/*
 * squeeze: elimina cualquier caracter del string s1 que aparezca en el string
 * s2
 *
 * Parameters:
 *		s1 -	array de caracteres
 *		s2 -	array de caracteres
 */
void squeeze (char s1[], char s2[]);

/*
 * substring: elimina el string s2 dentro del string s1
 *
 * Parameters:
 *		s1 -	string s1
 *		s2 -	string s2
 *
 * Return:
 *		posicion donde inicia el match (coincidencia)
 */
int substring (char s1[], char s2[]);
