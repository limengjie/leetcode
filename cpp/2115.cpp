#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> find_left_max(const vector<int> &traps) {
			vector<int> max;
			auto it = traps.cbegin();
			int max_val = *it;
			//left most can not trap water
			max.push_back(0);

			for(; it != traps.cend() - 1; ++it) {
				if (*it > max_val)
					max_val = *it;
				max.push_back(max_val);
			}

			return max;
		}

		vector<int> find_right_max(const vector<int> &traps) {
	  		vector<int> max;
			auto it = traps.crbegin();
			int max_val = *it;
			//right most can not trap water
			max.push_back(0);

			for(; it != traps.crend() - 1; ++it) {
				if (*it > max_val)
					max_val = *it;
				max.insert(max.begin(), max_val);
			}

			return max;
		}

		//min function is built-in
		//int min(int a, int b) { return a <= b ? a : b; }

		int sum_vol(const vector<int> traps, const vector<int> &max_left, 
				const vector<int> &max_right) {
			int sum = 0;

			for (size_t i = 1; i < max_left.size() - 1; ++i) {
				int vol = min(max_left.at(i), max_right.at(i)) - traps.at(i);

				//cout << i << "; " << vol << endl;

				if (vol > 0)
					sum += vol;
			}

			return sum;
		}

		int trapWater(const vector<int> &traps) {
			vector<int> left_max  = find_left_max(traps);
			vector<int> right_max = find_right_max(traps);

			int res = sum_vol(traps, left_max, right_max);

			return res;
		}

};

int main() {
	Solution solution;

	int trap[] {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector<int> trap_vec(trap, trap + 12);

	

	cout << "result: \n";
	int volume = solution.trapWater(trap_vec);
	cout << "volume = " << volume << endl;
	//for (size_t i = 0; i < trap_vec.size(); ++i) 
		//cout << trap_vec.at(i) << " ";
	//cout << endl;

	return 0;
}
