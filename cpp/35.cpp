//longest palindromic substr
//don't forget palindrome might have even # of letters
#include <iostream>

using namespace std;

//brute force
int expand(string str, int left, int right) {
	int len = 0;

	while (left >= 0 && right < str.size()) {
		if (str[left] == str[right]) {
			//update length
			if (left == right) 
				++len;
			else
				len += 2;
			//update ptr
			--left;
			++right;
		}
		else
			break;
	}

	return len;
}

string longestPalindrome(string str) {
	int start = -1; //start position
	int longestLen = 1;
	int odd_len, even_len;

	for (size_t i = 0; i < str.size() - 2; ++i) {
		//get len
		even_len = expand(str, i, i + 1); //if palindrome is even
		odd_len = expand(str, i, i); //if palindrome is odd
		
		if (even_len > longestLen) {
			//update len
			longestLen = even_len;
			//update start pos
			start = i - (even_len / 2 - 1);
		}
		if (odd_len > longestLen) {
			//update len
			longestLen = odd_len;
			//update start pos
			start = i - odd_len / 2;
		}
	}

	//palindrome is not found
	if (start == -1) return string();

	return str.substr(start, longestLen);
}

int main() {
	string s = "2234aa4321 5";

	string lp = longestPalindrome(s);

	cout << lp << endl;

	return 0;
}


