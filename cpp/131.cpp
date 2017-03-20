//Triangle
//
#include <iostream>
#include <vector>
//#include <unordered_map>
//#include <utility> //pair
#include <algorithm> //min()

using namespace std;

//recursion
//int minPath(int i, int j, vector<vector<int>> tri) {
	//if (i == tri.size() - 1) 
		//return min(tri[i][j], tri[i][j + 1]);

	//int minSteps = min(minPath(i + 1, j, tri), minPath(i + 1, j + 1, tri)) + tri[i][j];

	//return minSteps;
//}

//with memoization
int minPath(int i, int j, vector<vector<int>> tri, vector<vector<int>> res) {
	if (i > tri.size() - 1) {
		if (res[i][j] != -1)
			return res[i][j];
	}

	if (i == tri.size() - 1) 
		return min(tri[i][j], tri[i][j + 1]);

	int minSteps = min(minPath(i + 1, j, tri, res), minPath(i + 1, j + 1, tri, res)) 
		+ tri[i][j];
	res[i][j] = minSteps;

	return minSteps;
}

int main() {
	vector<vector<int>> triangle = {
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3}
	};

	//use 2d vector for memoization
	vector<vector<int>> res;
	//initialize the 2d vector
	for (size_t i = 0; i < triangle.size() - 1; ++i) {
		vector<int> row;
		for (int j = 0; j < i + 1; ++j) {
			row.push_back(-1);
		}
		res.push_back(row);
	}

	////print 
	//for (size_t i = 0; i < res.size(); ++i) {
		//for (size_t j = 0; j < res[i].size(); ++j) {
			//cout << res[i][j] << " ";
		//}
		//cout << endl;
	//}



	int min_steps = minPath(0, 0, triangle, res);

	cout << "min steps = " << min_steps << endl;

	return 0;
}
