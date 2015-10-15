#include <iostream>
#include <vector>
#include <numeric> //accumulate

using namespace std;

class Solution {
	public:
		int candy(const vector<int> &rating) {
			vector<int> count(rating.size());
			//from left to right
			int inc = 1;
			for (size_t i = 1; i < rating.size(); ++i) {
				if (rating.at(i) > rating.at(i-1))
					++inc;
				else
					inc = 1;
				count.at(i) = max(inc, count.at(i));
				cout << i << ": count = " << count.at(i) << endl;
			}

			//from right to left
			inc = 1;
			for (int i = rating.size() - 2; i >= 0; --i) {
				if (rating.at(i) > rating.at(i+1))
					++inc;
				else
					inc = 1;
				count.at(i) = max(inc, count.at(i));
				cout << i << ": count = " << count.at(i) << endl;
			}
					
			int tot = 0;
			for (size_t i = 0; i < count.size(); ++i) 
				tot += count.at(i);

			return tot;

		}
};

int main() {
	int r[] = {3, 2, 4, 1, 5, 6};
	vector<int> rating(r, r+6);

	Solution solution;

	int count = solution.candy(rating);
	cout << "Count = " << count << endl;


	return 0;
}
