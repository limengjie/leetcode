#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // max

using namespace std;

int lenLongestSubstr(string s) {
	//build a hashtable for saving the last
	//appearance of a char 
	unordered_map <char, int> dict;
	for (size_t i = 0; i < s.size(); ++i) {
		//if the char in string is not found,
		//insert it and initialize its value to -1
		if (dict.find(s[i]) == dict.end())
			dict[s[i]] = -1;
	}

	int longestLen = 0;
	int start = 0;
	for (size_t i = 0; i < s.size(); ++i) {
		if (dict[s[i]] >= start) {
			//update len
			longestLen = max((int)i - start, longestLen);
			//update start ptr
			start = dict[s[i]] + 1;
		}
		//update dict
		dict[s[i]] = i;
	}

	return max(longestLen, (int) s.size() - start);
}


int main() {
	//string s = "pwwkew";
	string s = "abcabcbb";
	//string s = "bbbbc";

	int len = lenLongestSubstr(s);

	cout << len << endl;

	return 0;
}



