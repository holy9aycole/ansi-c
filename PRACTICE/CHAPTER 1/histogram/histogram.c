/********************************************************
 * histogram --	Programa que toma una serie de palabras y dibuja un
 * histograma con de la longitud de las palabras.
********************************************************/
#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoyx(x, y) printf("\033[%d;%dH", (x), (y))

#define IN 1	/* dentro de una palabra */
#define OUT 0	/* fuera de una palabra */

#define MAX_WORD 10	/* numero maximo de palabras que se puede recibir */

char words[MAX_WORD][100];	/* array de palabras */

int main () {
	int character;	/* caracter introducido por el usuario */
	int i;	/* contador del bucle for */

	void draw_bar (char *, int);
	void get_words (char);

	clear();	/* limpiar la ventana de la consola */


	while ((character = getchar()) != EOF) {
		get_words(character);
	}

	int length = sizeof(words) / sizeof(words[0]);
	printf("LENGTH: %d", length);

	/* for (int i = 0; i < length; ++i) { */
		printf("WORD %s\n", words[0]);
	/* } */


	/* char *words[4] = {"Mango", "Naranja", "Papaya", "Perra"}; */

	/* for (i = 0; i < 4; ++i) { */
		/* draw_bar(words[i], i); */
	/* } */


	return 0;
}

/**
 * draw_bar --	Imprime una palabra dada en forma de barra para formar en
 * conjunto un histograma
 * @param word	palabra que representara en cada barra del histograma
 * @param index	contador que indica la posicion de la palabra que se esta
 * procesando. (0, 1, ..., n)
 */
void draw_bar (char * word, int index) {
	int i;	/* contador de bucle for */
	int xcord;	/* coodenada x */
	int base_ycord;	/* coodenada base de y */
	int capital_letter;	/* letra mayuscula */

	for (i = 0; word[i] != '\0'; ++i) {
		xcord = i * 4 + 1;
		base_ycord = 3 * (index + 1);

		gotoyx(base_ycord - (2 + index), xcord);
		printf(" ---\n");
		gotoyx(base_ycord- (1 + index), xcord);
		printf("| %c |\n", word[i]);
		gotoyx(base_ycord - (0 + index), xcord);
		printf(" ---\n");
	}
}

/**
 * get_words --	Forma una array de palabras a partir de un flujo de
 * caracteres introducidos por el usuario.
 * @param character	cada uno de los caracteres introducidos
 */
void get_words (char character) {
	int flag;	/* bandera que indica si esta dentro o fuera de una palabra */
	int word_index;	/* indice de cada palabra */
	int char_index;	/* indice de cada caracter de un palabra */

	word_index = char_index = 0;
	flag = OUT;
	if (character == ' ' || character == '\t') {
		flag = OUT;
		if (flag == IN) words[word_index - 1][char_index] = '\0';
	}
	else if (flag == OUT) {
		flag = IN;	/* dentro de una palabra */
		++word_index;	/* se incrementa el indice de palabra */
		char_index = 0;
		goto in;
	} else if (flag == IN) {
		in:	/* dentro de una palabra */
		/* if (char_index >= 100 || word_index >=MAX_WORD) */
			/* break; */
		/* else { */
		printf("Character: %c\n", character);
			words[word_index - 1][char_index] = character;
			++char_index;
		/* } */
	}

}
