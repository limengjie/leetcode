#include <iostream>
#include <stack> //stack


using namespace std;

bool isValid(string & s) {
	stack<char> brackets;
	string left = "([{";
	string right = ")]}";

	for (auto it = s.begin(); it != s.end(); ++it) {
		if (brackets.empty()) {//if stack is empty 
			//if it is a valid left char
			if (left.find(*it) != string::npos)
				brackets.push(*it);
			else {
				cout << "left\n";
				return false;
			}
		}
		else { // stack is not empty
			char l = brackets.top();
			if (l == left[right.find(*it)]) //if it can match the left char in stack
				brackets.pop();
			else {
				cout << "right\n";
				return false;
			}
		}
	}

	return brackets.empty(); //check if stack is empty!!!
}


int main() {
	string str0 = "()[]{}";
	string str1 = "()[]{}(";
	string str2 = "()[{[}(";
	string str3 = "()}{[}(";
	string str4;

	if (isValid(str4))
		cout << "valid string\n";
	else
		cout << "invalid\n";

	return 0;
}
