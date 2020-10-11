#include <iostream>
#include <string>

using namespace std;

int main () {
	string str;
	char a = (char)65;
	char b = (char)66;
	char c = (char)67;

	str.push_back((char)NULL);
	str.push_back(a);
	str.push_back(b);
	str.push_back(c);
	str.push_back((char)NULL);

	cout << str << endl;

	return 0;
}
