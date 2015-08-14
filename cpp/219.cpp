#include <iostream>
#include <vector>
#include <limits>

using namespace std;

extern void quickSort(int *, int, int);

class Solution {
	public:
		int abs(int num) {
			if (num < 0)
				return -num;
			
			return num;
		}
		//bool uniqueVec(vector<vector<int> >vecArry, vector<int> vec) {
			////if there is only 1 or no element
			//if (vecArry.size() <= 1)
				//return true;

			////check the new ans's size
			//if (vec.size() != 3) {
				//cout << "ans is wrong\n";
				//return false;
			//}

			////only compare the last element 
			////because the array is sorted
			////the identical answer will only appear after the last
			////one
			//vector<int> last = vecArry.back();
			//for (size_t i = 0; i < 3; ++i) {
				//if (last.at(i) != vec.at(i))
					//return true;
			//}

			//return false;

		//}

		vector<int> threeSumClosest(vector<int> & num, int target) {
			vector<int> res;
			int min_gap = numeric_limits<int>::max();

			if (num.size() < 3)
				return res;

			for (size_t a = 0; a < num.size() - 3; ++a) {
				int sum, gap;
				size_t b = a + 1;
				size_t c = num.size() - 1;
				while (b < c) {
					sum = num.at(a) + num.at(b) + num.at(c);
					gap = abs(sum - target);
					//update the answer
					if (gap < min_gap) {
						cout << "gap < min\n";
						min_gap = gap;
						while (!res.empty())
							res.pop_back();
						res.push_back(num.at(a));
						res.push_back(num.at(b));
						res.push_back(num.at(c));
					}

					//update the pointer
					if (sum < target) {
						++b;

					}
					else if (sum > target) {
						--c;
					}
					else // sum == target
						return res;
				}
			}

			return res;
		}
};

int main() {
	int target = 1;
	int num[] = {-1, 2, 1, -4};

	//sort array
	quickSort(num, 0, 3);
	//print sorted array
	cout << "ordered array:\n";
	for (size_t i = 0; i < 4; ++i)
		cout << num[i] << " ";
	cout << endl;

	vector<int> orderedNum (num, num + 4);



	Solution solution;
	vector<int> result = solution.threeSumClosest(orderedNum, target);

	if (result.size() == 0)
		cout << "No such pair.\n";
	else {
		cout << "{";
		for (size_t j = 0; j < 3; ++j) {
			cout << result.at(j);
			if (j < 2)
				cout << ", ";
		}
		cout << "}\n";
	}

	return 0;
}
