#include <iostream>

using namespace std;

void insSort(int A[], int n) {
	for (int i = 0; i < n; ++i) {
		int min = i;
		for (int j = i; j < n; ++j) {
			if (A[j] < A[min])
				min = j;
		}

		//exchange position
		int tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
	}
}

int main() {
	int num[] = {1, 5, 9, 8, 7, 6, 2, 3, 4};

	insSort(num, 9);

	for (int i = 0; i < 9; ++i)
		cout << num[i] << "\t";
	cout << endl;

	return 0;
}
