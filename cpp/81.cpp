#include <iostream>
#include <vector>

using namespace std;

void show2dvec(vector<vector<int>> res) {
	cout << "res:\n";
	for (size_t i = 0;  i < res.size(); ++i) {
		for (size_t j = 0; j < res[i].size(); ++j) 
			cout << res[i][j] << " ";
		cout << endl;
	}
}


void recurs(vector<int> & nums, int index, int elts, vector<vector<int>> & res, 
		vector<int> & path) {
	//index is the start index of for loop
	//elts is the number of elts in ea vec
	for (size_t i = index; i < nums.size() - elts + 1; ++i) {
		if (elts == 1) {//if get entire path
			res.push_back(path);
			return;
		}

		path.push_back(nums[i]);
		recurs(nums, i + 1, elts - 1, res, path);
		path.pop_back();
	}
}



vector<vector<int>> subsets(vector<int> & nums) {
	vector<vector<int>> res;
	//int vec_ind;//the index of the 2d vector
	//insert a void vec
	res.push_back(vector<int>());
	for (size_t elts = 1; elts <= nums.size(); ++elts) {
		vector<int> path;
		recurs(nums, 0, elts, res, path);
	}

	return res;
}

int main() {
	vector<int> nums = {1, 2, 3, 4};

	vector<vector<int>> res = subsets(nums);

	show2dvec(res);

	return 0;
}

