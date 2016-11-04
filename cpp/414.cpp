#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

int evalRPN(vector<string> & str_num) {
	stack<int> stk;
	int operands[2] = {0, 0};
	string operators = "+-*/";

	for (size_t i = 0; i < str_num.size(); ++i) {
		//if it is an operator
		if (strstr(operators.c_str(), str_num[i].c_str())) {
			//get operands
			int j = 0;
			while (!stk.empty() && j < 2) {
				operands[j++] = stk.top();
				stk.pop();
			}
			//calculate
			if (str_num[i] == "+") 
				stk.push(operands[1] + operands[0]);
			else if (str_num[i] == "-") 
				stk.push(operands[1] - operands[0]);
			else if (str_num[i] == "*") 
				stk.push(operands[1] * operands[0]);
			else if (str_num[i] == "/") 
				stk.push(operands[1] / operands[0]);

			//reset operands
			for (size_t k = 0; k < 2; ++k) 
				operands[k] = 0;

		}
		//if it is a str_number
		else {
			//get number
			int num = 0;
			for (size_t k = 0; k < str_num[i].size(); ++k) {
				int n = str_num[i][k] - '0';
				if (n < 0 || n > 9) {
					cout << "wrong number\n";
					return 0;
				}
				num = num * 10 + n;
			}

			stk.push(num);
		}
	}

	if (stk.empty()) 
		return 0;
	else
		return stk.top();
}

int main() {
	//vector<string> str = {"21", "9", "+", "10", "*"};
	vector<string> str = {"21o", "9", "+", "10", "*"};

	int ans = evalRPN(str);

	cout << "ans = " << ans << endl;

	return 0;
}


