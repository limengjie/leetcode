//count the # of islands
#include <iostream>
#include <vector>

using namespace std;

//wrong
////if there is 1 over or on the left hand side of the current node
////don't increase the # of islands
//int islands(vector<vector<int>> & grid) {
	//int number = 0;
	//int * up = new int[grid[0].size()];
	//int prev = 0;
	////initialize up
	//for (size_t i = 0; i < grid[0].size(); ++i) 
		//up[i] = 0;

	//for (size_t i = 0; i < grid.size(); ++i) {
		//for (size_t j = 0; j < grid[0].size(); ++j) {
			////find new island
			//if (prev == 0 && up[j] == 0 && grid[i][j] == 1)
				//++number;
			////update
			//prev = grid[i][j];
			//up[j] = grid[i][j];
		//}
	//}
	//return number;
//}

void reset(vector<vector<int>> & grid, int i, int j) {
	//if out of bounds, return
	if (i < 0 || i >= grid.size())
		return;
	if (j < 0 || j >= grid[0].size())
		return;
	//if it reaches water, return
	if (grid[i][j] == 0)
		return;

	//recursively reset connected 1s as 0s
	grid[i][j] = 0;
	reset(grid, i - 1, j);
	reset(grid, i + 1, j);
	reset(grid, i, j - 1);
	reset(grid, i, j + 1);
}
	
	
int islands(vector<vector<int>> & grid) {
	int num = 0;
	for (size_t i = 0; i < grid.size(); ++i) {
		for (size_t j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 1) {
				++num;
				reset(grid, i, j);
			}
		}
	}

	return num;
}


int main() {
	//build 2d vector
	vector<vector<int>> vec;
	int row[][5] = {
	    {1, 1, 1, 0, 0},
	    {0, 0, 1, 0, 0},
	    {1, 1, 1, 0, 0},
	    {0, 0, 0, 1, 1}
	};

	for (size_t i = 0; i < 4; ++i) {
		vector<int> tmp (row[i], row[i] + sizeof(row[i]) / sizeof(int));
		vec.push_back(tmp);
	}

	//print 2d vector
	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}

	int n = islands(vec);
	cout << "The # of islands is " << n << endl;

	//print 2d vector
	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}

	return 0;
}
	




