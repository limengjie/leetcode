#include <iostream>
#include <vector>

using namespace std;

extern void quickSort(int *, int, int);

class Solution {
	public:
		bool uniqueVec(vector<vector<int> >vecArry, vector<int> vec) {
			//if there is only 1 or no element
			if (vecArry.size() <= 1)
				return true;

			//check the new ans's size
			if (vec.size() != 4) {
				cout << "ans is wrong\n";
				return false;
			}

			//only compare the last element 
			//because the array is sorted
			//the identical answer will only appear after the last
			//one
			vector<int> last = vecArry.back();
			for (size_t i = 0; i < 4; ++i) {
				if (last.at(i) != vec.at(i))
					return true;
			}

			return false;

		}

		vector<vector<int> > fourSum(vector<int> & num, int target) {
			vector<vector<int> > res;

			if (num.size() < 4)
				return res;

			for (size_t a = 0; a < num.size() - 4; ++a) {
				for (size_t b = a + 1; b < num.size() - 3; ++b) {
					size_t c = b + 1;
					size_t d = num.size() - 1;
					while (c < d) {
						if (num.at(a) + num.at(b) + num.at(c)
								+ num.at(d) < target)
							++c;
						else if (num.at(a) + num.at(b) 
								+ num.at(c) +num.at(d) 
								> target)
							--d;
						else {// find the target
							vector<int> vec({num.at(a), 
									num.at(b), 
									num.at(c),
									num.at(d)});
							if (uniqueVec(res, vec)) 
								res.push_back(vec);
							++c;
							--d;
						}
					}
				}
			}

			return res;
		}
};

int main() {
	int target = 0;
	int num[] = {-1, 0, 1, 0, -2, 2};

	//sort array
	quickSort(num, 0, 6);
	//print sorted array
	cout << "ordered array:\n";
	for (size_t i = 0; i < 6; ++i)
		cout << num[i] << " ";
	cout << endl;

	vector<int> sortedNum (num, num + 6);



	Solution solution;
	vector<vector<int> > result = solution.fourSum(sortedNum, target);

	if (result.size() == 0)
		cout << "No such pair.\n";
	else {
		int isFirst = 1;
		for (size_t i = 0; i < result.size(); ++i) {
			cout << "{";
			for (size_t j = 0; j < 4; ++j) {
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
