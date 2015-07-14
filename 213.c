/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  10/19/2014 08:21:40 AM
 *
 *    Description:  Search in rotated sorted array
 *
 * ===========================================================================
 */

#include <stdio.h>

int rttArySrch(int * a, int first, int last, int tar) {
	int mid;

	while (first != last) {
		mid = (first + last)/2;
		if (tar == a[mid])
			return a[mid];
		else if (a[mid] > a[last]) {
			if (tar < a[mid] && tar > a[first]) {
				last = mid;
				printf("0:last = %d\n", last);
			}
			else {
				first = mid + 1;
				printf("1:first = %d\n", first);
			}
		}
		else if (a[mid] < a[last]) {
			if (tar > a[mid] && tar < a[last]) {
				first = mid + 1;
				printf("2;first = %d\n", first);
			}
			else {
				last = mid;
				printf("3:last = %d\n", last);
			}
		}
	}
	return -1;
}

main () {
	int i, ans, tar, len = 10;
	int array[10] = {4, 5, 6, 7, 8, 9, 0, 1, 2, 3};

	tar = 9;
	ans = rttArySrch(array,0, len -1, tar);
	printf("The answer is %d\n", ans);
}
