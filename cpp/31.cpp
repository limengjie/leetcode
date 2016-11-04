//valid palindrome

#include <iostream>

using namespace std;

bool is_alphanumeric(char c) {
	//if c is a number
	if (c >= 48 && c <= 57)
		return true;

	//if c is a letter in Upper case
	if (c >= 65 && c <= 90)
		return true;

	//if c is a letter in lower case
	if (c >= 97 && c <= 122)
		return true;

	return false;
}

bool is_same_char(char a, char b) {
	if (a == b)
		return true;

	if (a - b == 32 || b - a == 32)
		return true;

	return false;
}


bool validPalindrome(string s) {
	auto it = s.begin();
	auto rit = s.rbegin();

	while (it != s.end() && rit != s.rend()) {
		if (!is_same_char(*it, *rit)) {
			if (is_alphanumeric(*it) && is_alphanumeric(*rit))
				return false;
			if (!is_alphanumeric(*it))
				++it;
			if (!is_alphanumeric(*rit))
				++rit;
		}
		else {//they are identical
			++it;
			++rit;
		}
	}

	return true;
}


int main () {

	string str0;
	string str1 = ")( ^1#$";
	string str2 = "A man, a plan, a canal : panama";

	if (validPalindrome(str1))
		cout << "valid\n";
	else
		cout << "no\n";

	return 0;
}
