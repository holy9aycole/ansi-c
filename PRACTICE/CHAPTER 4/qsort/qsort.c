/********************************************************
 * qsort --	Programa que implementa el algoritmo qsort para ordenar una arrar
 * de numeros enteros
********************************************************/
#include <stdio.h>

#define LENGTH 10	/* cantidad de elementos del array */

int main (void) {
	int v[LENGTH] = { 3, 5, 1, 25, 31, 4, 13, 2, 11, 12 };
	void qsort (int [], int, int);
	void printarray (int [], int);

	printarray(v, LENGTH);	/* antes de ordenar */
	qsort(v, 0, LENGTH - 1);
	printarray(v, LENGTH);	/* despues de ordenar */

	return 0;
}

/*
 * qsort: ordena v[left] ... v[right] en orden creciente
 *
 * Parameters:
 *		v		array de numeros enteros
 *		left	posicion inicial del array
 *		right	posicion final del array
 */
void qsort (int v[], int left, int right) {
	int i;	/* contador de bucle */
	int last;	/*  */
	void swap (int v[], int i, int j);

	if (left >= right)	/* si el array contiene menos de dos elementos: */
		return;	/* no hacer nada */
	swap(v, left, (left + right) / 2);	/* mover el elemento de la mitad a v[0] */
	last = left;
	for (i = left + 1; i <= right; ++i) /*  */
		if (v[i] < v[left])
			swap(v, ++last, i);

	swap(v, left, last);	/*  */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/*
 * swap: intercambia v[i] y v[j]
 */
void swap (int v[], int i, int j) {
	int temp;	/* variable temporal */

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*
 * printarray: imprimir los elementos de un array
 *
 * Parameters:
 *		v	array a imprimir
 *		n	tamaño del array
 */
void printarray (int v[], int n) {
	int i;	/* contador de bucle */

	printf("{ %d", v[0]);
	for (i = 1; i < n; ++i) {
		printf(", %d", v[i]);
	}
	printf(" }\n");
}
