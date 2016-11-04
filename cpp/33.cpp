#include <iostream>

using namespace std;

int myStoi(string str) {
	if (str.size() == 0) return 0;

	int sign = 1;
	int num = 0;
	size_t i = 0;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-') {
		++i;
		sign = -1;
	}

	for( ; i < str.size(); ++i) {
		//check if it is a num
		if (str[i] < '0' || str[i] > '9') {
			cout << "this is not a number\n";
			return 0;
		}

		num = num * 10 + (str[i] - '0');
		//check if the number overflows
		if (num < 0) {
			cout << "overflow\n";
			return 0;
		}
	}

	return num * sign;
}

int main() {
	string num_str = "-a2147483647";

	int n = myStoi(num_str);

	cout << "n = " << n << endl;

	return 0;
}

