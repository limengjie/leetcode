#include <iostream>
#include <stack>

using namespace std;

int longValidParen(string & str) {
	int len = 0;//the # of valid pairs
	int longestLen = 0;
	stack<char> left;

	for (size_t i = 0; i < str.size(); ++i) {
		//if left is empty
		if (left.empty()) {
			if (str[i] == '(')
				left.push(str[i]);
			else
				len = 0;
		}
		else { //left is not empty
			if (str[i] == ')') {
				left.pop();
				//only count once in case we have "()("
				//we will not count 3
				++len;
				longestLen = (len > longestLen) ? len : longestLen;
			}
			else
				len = 0;
		}
	}

	return longestLen * 2;
}

int main() {
	string str0 = "()(())";
	string str1;

	int n = longValidParen(str1);

	cout << "the length = " << n << endl;

	return 0;
}


