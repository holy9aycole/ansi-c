/********************************************************
 * alloc --	Programa que simula el uso de las librerias malloc y free
********************************************************/
#include <stdio.h>

int main (void) {
	char *test1;
	char *test2;
	char *test3;
	char * alloc (int);
	void afree (char *);

	test1 = alloc(500);
	test2 = alloc(500);
	test3 = alloc(1000000);

	printf("test1: %p\n", test1);
	printf("test2: %p\n", test2);
	printf("test3: %p\n", test3);

	return 0;
}

#define ALLOCSIZE 10000	/* Tamaño del espacio disponible */

static char allocbuf[ALLOCSIZE];	/* almacenamiento para alloc */
static char *allocp = allocbuf;		/* siguiente posicion libre */

/*
 * alloc: reserva un espacio de n bytes
 *
 * Parameters:
 *		n	cantidad de bytes ha reservar
 *
 * Return:
 *		puntero a la cadena de bytes
 */
char * alloc (int n) {	/* devuelve un puntero de n caracteres */
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* el espacio llega */
		allocp += n;
		return allocp - n;	/* inicio del espacio reservado */
	} else	/* no queda suficiente espacio */
		return 0;
}

/*
 * afree: libera el espacio reservado al que apunta el puntero p
 *
 * Parameters:
 *		p	puntero
 */
void afree (char *p) {	/* liberar el almacenamiento apuntado por p */
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
