#include <stdio.h>
#include "./qsort.h"

/*
 * numcmp: compara s1 y s2 numericamente
 */
int numcmp (const char *s1, const char *s2) {
	double v1;	/* valor numerico del primer string */
	double v2;	/* valor numerico del segundo string */

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
