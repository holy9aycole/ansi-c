/********************************************************
 * squeeze --	Programa que elimina cualquier caracter del string s1
 * que coincida con un caracter del string s2
********************************************************/
#include <stdio.h>
#include "../util/util.h"

int main () {

	void squeeze (char s1[], char s2[]);

	char s1[] = "Hola mundo donghua";
	char s2[] = "mundo";

	squeeze(s1, s2);

	printf("%s\n", s1);

	return 0;
}
