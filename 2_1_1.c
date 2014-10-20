/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  10/18/2014 07:46:22 PM
 *
 *    Description:  remove duplicates from sorted array
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void * b) {
	return *(int *)a - *(int *)b;
}

int rmDup(int * array, int size) {
	int i, ptr = 0, n_sz = 1;

	for (i = 1; i < size; i++) {
		if (array[ptr] != array[i]) {
			array[ptr+1] = array[i];
			ptr += 1;
			n_sz++;
		}
	}
	/*array[n_sz+1] = '\0';*/

	return n_sz;
}

main () {
	int i, len = 10;
	int array[10] = {7, 1, 2, 3, 4, 5, 7, 1, 7, 8};
	qsort(array, len, sizeof(int), cmp);
	len = rmDup(array ,len);
	for (i = 0; i < len; i++) 
		printf("%d \t", array[i]);
	printf("\n Length of array is %d\n", len);
	
}
