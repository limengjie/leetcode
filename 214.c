#include <stdio.h>

/*Follow up for "search in rotated sorted array": What if duplicates are allowed?*/

int rttArySrch2(int * a, int first, int last, int tar) {
	int mid;

	while (first != last) {
		mid = (first + last) / 2;
		if (a[mid] == tar)
			return a[mid];
		else if (a[first] < a[mid]) {
			if (a[first] <= tar && a[mid] > tar) 
				last = mid;
			else 
				first = mid + 1;
		}
		else if (a[first] > a[mid]) {
			if (a[mid] < tar && a[last-1] >= tar)
				first = mid + 1;
			else
				last = mid;
		}
		else
			++first;
	}

	return -1;
}

int main () {
	int array[5] = {1, 1, 1, 4, 1};
	int ans, tar = 4, len = 5;

	ans = rttArySrch2(array, 0, len-1, tar);

	printf("The answer is %d.\n", ans);

	return 0;
}
		
