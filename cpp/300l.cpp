//longest increasing subsequence
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> //min

using namespace std;

int lengthOfLIS(vector<int> & num, int n, unordered_map<int, int> dict) {
	if (dict.find(n) != dict.end())
		return dict[n];

	if (n <= 1)
		return 1;

	//get the max subsequence
	int maxLen = 0;
	for (int i = 0; i < n - 1; ++i) {
		int len = 0;
		if (num[i] < num[n - 1]) 
			len = lengthOfLIS(num, i + 1, dict);
		if (len > maxLen) {
			maxLen = len;
		}
	}

	dict[n] = maxLen + 1;

	return maxLen + 1;
}

int main() {
	vector<int> array = {10, 9, 2, 5, 3, 7, 101, 18};
	unordered_map<int, int> dict;

	int res = lengthOfLIS(array, (int)array.size(), dict);

	cout << res << endl;

	return 0;
}

