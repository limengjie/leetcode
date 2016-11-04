#include <iostream>

using namespace std;

string addBin(string a, string  b) {
	string res;

	//check if there is a empty string
	if (a.size() == 0 || b.size() == 0)
		return "empty string";

	auto arit = a.rbegin();
	auto brit = b.rbegin();
	int na, nb, carry = 0, sum;
	while (arit != a.rend() || brit != b.rend()) {
		//get na nb
		if (arit != a.rend()) {
			//check if na is a valid number
			if (*arit < '0' || *arit > '1') {
				return "not a valid binary number";
			}
			na = *arit - '0';
			++arit;
		}
		else
			na = 0;
		if (brit != b.rend()) {
			//check if nb is a valid number
			if (*brit < '0' || *brit > '1') {
				return "not a valid binary number";
			}
			nb = *brit - '0';
			++brit;
		}
		else
			nb = 0;

		//add them up
		sum = na + nb + carry;
		carry = sum / 2;
		sum %= 2;

		//save the res
		res.insert(res.begin(), sum + '0');
	}
	//if carry is not 0
	if (carry)
		res.insert(res.begin(), carry + '0');
		
	return res;
}

int main() {
	//string a = "110110";
	string a;
	//string b = "1011001000";
	string b;

	string res = addBin(a, b);

	cout << "res = " << res << endl;

	return 0;
}
