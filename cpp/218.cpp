#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> & num, int target) {
			vector<vector<int> > res;

			if (num.size() < 3)
				return res;

			for (size_t a = 0; a < num.size() - 3; ++a) {
				size_t b = a + 1;
				size_t c = num.size() - 1;
				while (b < c) {
					if (num.at(a) + num.at(b) + num.at(c) < target)
						++b;
					else if (num.at(a) + num.at(b) + num.at(c) 
							> target)
						--c;
					else {// find the target
						res.push_back({num.at(a),
								num.at(b), num.at(c)});
						++b;
						--c;
					}
				}
			}

			//vector<int> vec1(3, 1);
			//vector<int> vec2(3, 2);
			//res.push_back(vec1);
			//res.push_back({1, 2, 3});

			return res;
		}
};

int main() {
	int target = 0;
	int num[] = {-4, -1, -1, 0, 1, 2};
	vector<int> orderedNum (num, num + 6);

	//vector<int> orderedNum = sort(num_vec);

	Solution solution;
	vector<vector<int> > result = solution.threeSum(orderedNum, target);

	if (result.size() == 0)
		cout << "No such pair.\n";
	else {
		int isFirst = 1;
		for (size_t i = 0; i < result.size(); ++i) {
			cout << "{";
			for (size_t j = 0; j < 3; ++j) {
				if (!isFirst)
					cout << ", ";
				cout << result.at(i).at(j);
				isFirst = 0;
			}
			cout << "}\n";
			isFirst = 1;
		}
	}

	return 0;
}
