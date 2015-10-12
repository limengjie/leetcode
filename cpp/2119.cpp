#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> grayCode (size_t n) {
			//init a new vec with one elt 0
			vector<int> ans(1);

			//assert n >= 0
			if (n < 1) return ans;

			size_t i = 0;
			while (i < n) {
				//compute 2^n
				int add = 1 << i;

				//copy previous array and add 2^n
				vector<int> temp(ans);
				auto  rit = temp.rbegin();
				for (; rit != temp.rend(); ++rit) {
					ans.push_back(*rit + add);
				}

				++i;
			}

			return ans;
		}
};

int main() {
	Solution solution;

	vector<int> ans = solution.grayCode(3);


	cout << "result:\n";
	for (size_t i = 0; i < ans.size(); ++i) 
		cout << ans.at(i) << endl;

	return 0;
}



