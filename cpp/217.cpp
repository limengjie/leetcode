#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> & num, int target) {
			vector<int> res;
			unordered_map<int, int> index;

			//initialize the map, let the number be the key and the index be
			//the value
			for (size_t i = 0; i < num.size(); ++i)
				index[num[i]] = i;

			for (size_t i = 0; i < num.size(); ++i) {
				int gap = target - num.at(i);
				if (index.find(gap) != index.end()) {
					res.push_back(i);
					res.push_back(index[gap]);
					break;
				}
			}

			return res;
		}
};

int main() {
	int target = 17;
	int num[] = {2, 7, 11, 15};
	vector<int> num_vec (num, num + 4);

	Solution solution;
	vector<int> result = solution.twoSum(num_vec, target);

	if (result.size() == 0)
		cout << "No such pair.\n";
	else {
		for (size_t i = 0; i < result.size(); ++i) 
			cout << result.at(i) << " ";
		cout << endl;
	}


	return 0;
}
