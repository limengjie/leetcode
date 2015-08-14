#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	//partition
	while (i <= j) {
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			++i;
			--j;
		}
	}

	//recursion
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

//int main() {
	//int num[] = { -1, 2, 1, -4};

	//quickSort(num, 0, 3);

	//cout << "{";
	//for (size_t i = 0; i < 4; ++i) {
		//if (i != 0)
			//cout << ", ";
		//cout << num[i];
	//}
	//cout << "}\n";
//}

