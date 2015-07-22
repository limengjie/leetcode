/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  04/02/2015 09:06:12 PM
 *
 *    Description:  remove duplicates from sorted array 2
 *		    duplicates are allowed at most twice
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <stdlib.h> // qsort

#define LEN 10

int cmp(const void * pa, const void * pb) {
	return *(int *)pa - *(int *)pb;
}

int rmDup2(int * a, int size) {
	int i, ptr = 0, dup = 0;
	int n = 0;

	for(i = 2; i < size; ++i) {
		if (a[ptr] != a[i]) { 
			a[ptr + 2] = a[i];
			ptr++;
		}
	}
	n = ptr + 2;

	return n;
}

main () {
	int array[LEN] = {16, 2, 5, 7, 1, 15, 15, 15, 7, 3};
	qsort(array, LEN, sizeof(int), cmp);
	int n = rmDup2(array, LEN);


	
	int i;
	for(i = 0; i < n; ++i)
		printf("%d\t", array[i]);
	printf("\n there are %d elements.\n", n);

	return 0;
}

