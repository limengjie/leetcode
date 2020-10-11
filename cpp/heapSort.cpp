#include <iostream>
#include "pQ.h"

using namespace std;

void reverse(int array[], int cur, int n, PQ<int> & pq) {
	//use recursion to get an inverse array
	if (cur < n)
		reverse(array, cur + 1, n, pq);
	else
		return;

	array[cur] = pq.delMax();
}
	

void heapSort(int array[], int n) {
	//convert array to priority queue
	PQ<int> pq(array, n);
	
	for (int i = 0; i < n; ++i) {
		array[i] = pq.delMax();
	}
	
//	reverse(array, 0, n, pq);
}
	
	

int main() {
	int array[] = {1, 9, 8, 7, 2, 5};

	heapSort(array, 6);
	
	for (int i = 0; i < 6; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}
	
	
