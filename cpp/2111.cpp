#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int rmElt(int * A, int n, int elt) {
			int index = 0;
			for (int i = 0; i < n; ++i) {
				if (A[i] != elt)
					A[index++] = A[i];
			}

			return index;
		}
};

int main() {
	int target = 1;
	int num[] = {-1, 0, 1, 0, -2, 2};
	int n;

	Solution solution;
	n = solution.rmElt(num, 6, target);

	//print result 
	cout << "new array:\n";
	for (int i = 0; i < n; ++i)
		cout << num[i] << " ";
	cout << endl;

	return 0;
}
