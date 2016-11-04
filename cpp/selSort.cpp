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


void exch(int arr[], int p0, int p1) {
	int tmp;
	tmp = arr[p0];
	arr[p0] = arr[p1];
	arr[p1] = tmp;

}


void selSort(int A[], int n) {
        for (int i = 0; i < n; ++i) {
                int j = i;

                //trace back and compare
                while (j > 0) {
                        if (A[j] < A[j - 1]) {
                                exch(A, j, j - 1);
                                --j;
                        }
			else 
				break;
                }
        }
}

int main() {
	int num[] = { -1, 2, 1, -4};

	selSort(num, 4);

	show(num, 4);
}
