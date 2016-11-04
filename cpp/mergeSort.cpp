#include <iostream>

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

void merge(int A[], int lo, int hi, int aux[]) {
	//copy array
	for (int i = lo; i <= hi; ++i) {
		aux[i] = A[i];
	}
		
	int mid = (lo + hi) / 2;
	int left = lo, right = mid + 1;
	int cur = lo;

	while (cur <= hi) {
		if (left > mid)
			A[cur++] = aux[right++];
		else if (right > hi)
			A[cur++] = aux[left++];
		else if (aux[left] < aux[right])
			A[cur++] = aux[left++];
		else // aux[left] >= aux[right]
			A[cur++] = aux[right++];
	}
}

void mergeSort(int A[], int lo, int hi, int aux[]) {
	if (lo == hi)
		return;

	int mid = (lo + hi) / 2;

	//divede
	mergeSort(A, lo, mid, aux);
	mergeSort(A, mid+1, hi, aux);
	
	//conquer
	merge(A, lo, hi, aux);
}

//int main() {
	//int num[] = { -1, 2, 1, -4};
	//int aux[4];

	//show(num, 4);
	//mergeSort(num, 0, 3, aux);

	//show(num, 4);
//}
