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
			if (vec.size() != 3) {
				cout << "ans is wrong\n";
				return false;
			}

			//only compare the last element 
			//because the array is sorted
			//the identical answer will only appear after the last
			//one
			vector<int> last = vecArry.back();
			for (size_t i = 0; i < 3; ++i) {
				if (last.at(i) != vec.at(i))
					return true;
			}

			return false;

		}

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
						vector <int> vec({num.at(a), 
								num.at(b), num.at(c)});
						if (uniqueVec(res, vec)) 
							res.push_back(vec);
						++b;
						--c;
					}
				}
			}

			return res;
		}
};

int main() {
	int target = 0;
	int num[] = {-1, 0, 1, 2, -1, -4};

	//sort array
	quickSort(num, 0, 6);
	//print sorted array
	cout << "ordered array:\n";
	for (size_t i = 0; i < 6; ++i)
		cout << num[i] << " ";
	cout << endl;

	vector<int> orderedNum (num, num + 6);



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
