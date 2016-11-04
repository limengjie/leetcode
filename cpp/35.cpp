//longest palindromic substr
#include <iostream>

using namespace std;

//brute force
string longestPalindrome(string str) {
	int start = -1;
	int longestLen = 1;
	int len;

	int l; 
        size_t r;
	for (size_t i = 0; i < str.size(); ++i) {
		len = 1;
		//explore left and right at the same time
		l = i - 1;
		r = i + 1;
		while (l >= 0 && r <= str.size()) {
			if (str[l] == str[r]) {
				//update ptr
				--l;
				++r;
				//update length
				len += 2;
				//update the longest length
				if (len > longestLen) {
					longestLen = len;
					start = i - (len - 1) / 2;
				}
			}
			else
				break;
		}
	}

	//palindrome is not found
	if (start == -1) return string();

	return str.substr(start, longestLen);
}

int main() {
	string s = "1234aba4321";

	string lp = longestPalindrome(s);

	cout << lp << endl;

	return 0;
}


