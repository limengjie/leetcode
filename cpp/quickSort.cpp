#include <iostream>
#include <string>

using namespace std;

void show(int num[], int n) {
	cout << "{";
	for (int i = 0; i < n; ++i) {
		if (i != 0)
			cout << ", ";
		cout << num[i];
	}
	cout << "}\n";
}


void exch(int arr[], int p0, int p1) {
	int tmp;
	tmp = arr[p0];
	arr[p0] = arr[p1];
	arr[p1] = tmp;

}


void quickSort(int arr[], int lo, int hi) {
	if (hi <= lo) return;

	int i = lo + 1, j = hi;
	int pivot = arr[lo];

	//partition
	while (true) {//while the ptrs don't cross
		while (arr[i] < pivot) {
			++i;
			if (i >= hi) break;
		}
		while (arr[j] > pivot) {
			//arr[j] > pivot is redundant
			//because arr[lo] == pivot, anyway
			--j;
			if (j <= lo) break;
		}

		//check if ptr cross
		if (i >= j) break;

		//exchange
		exch(arr, i, j);
	}
	exch(arr, lo, j);

	//show(arr, 4);

	//recursion
	quickSort(arr, lo, j - 1);
	quickSort(arr, j + 1, hi);
}






//int main() {
	//int num[] = { -1, 2, 1, -4};

	//quickSort(num, 0, 3);

	//show(num, 4);
//}

