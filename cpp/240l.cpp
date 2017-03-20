//search a 2D matrix
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, const int target) {
	int n = (int)matrix.size();
	int m = (int)matrix[0].size();

	int x = m - 1;
	int y = 0;

	while (x >= 0 && y < n) {
		if (matrix[y][x] == target) {
			cout << "target == " << matrix[y][x] << endl;
			return true;
		}
		else if (matrix[y][x] > target) {
			cout << matrix[y][x] << endl;
			--x;
		}
		else if (matrix[y][x] < target) {
			cout << matrix[y][x] << endl;
			++y;
		}
	}

	return false;
}

int main() {
	//build 2d vector
	vector<vector<int>> vec;
	int row[][5] = {
	    {1, 4, 7, 11, 15},
	    {2, 5, 8, 12, 19},
	    {3, 6, 9, 16, 22},
	    {10, 13, 14, 17, 24},
	    {18, 21, 23, 26, 30}
	};

	for (size_t i = 0; i < 5; ++i) {
		vector<int> tmp (row[i], row[i] + sizeof(row[i]) / sizeof(int));
		vec.push_back(tmp);
	}

	//print 2d vector
	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}

	bool res = searchMatrix(vec, 20);
	if (res)
		cout << "Target is found\n";
	else 
		cout << "not found\n";

	return 0;
}

