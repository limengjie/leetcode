#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int> & num) {
			unordered_map<int, bool> used;
			int longest = 0;

			for (auto i: num) used[i] = false;

			for (size_t i = 0; i < num.size(); ++i) {
				if (used[num[i]])
					continue;

				cout << "num[i] = " << num[i] << " :\n";

				used[num[i]] = true;
				int length = 1;

				for (int j = num[i] + 1; used.find(j) != used.end(); ++j) {
					used[j] = true;
					cout << j << " ";
					++length;
				}

				for (int j = num[i] - 1; used.find(j) != used.end(); --j) {
					used[j] = true;
					cout << j << " ";
					++length;
				}

				longest = (length > longest) ? length : longest;
				cout << endl;
				//if (longest < length)
					//longest = length;
				
			}

			return longest;
		}
};

int main () {
	//cout << "hello world\n";
	
	int myints[] = {100, 4, 200, 1, 3, 2};

	vector<int> vec (myints, myints + 6);

	Solution solution;

	int ans = solution.longestConsecutive(vec);

	cout << "longest = " << ans << endl;

	return 0;
}
