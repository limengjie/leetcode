//letter combinations of phone num
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void DFS(string & digit, int index, vector<string> & res, string & str,
		unordered_map<char, string> & keyboard) {
		if (str.size() == digit.size()) {
			res.push_back(str);
			return;
		}

	char d = digit[index];
	for (size_t i = 0; i < keyboard[d].size(); ++i) {
		str += (char)(keyboard[d])[i];
		DFS(digit, index + 1, res, str, keyboard);
		str.erase(str.end() - 1);
	}

}

	


vector<string> letterCombinations(string & digit) {
	//create a map
	unordered_map <char, string> keyboard;
	keyboard['2'] = "abc";
	keyboard['3'] = "def";
	keyboard['4'] = "ghi";
	keyboard['5'] = "jkl";
	keyboard['6'] = "mno";
	keyboard['7'] = "pqrs";
	keyboard['8'] = "tuv";
	keyboard['9'] = "wxyz";

	vector<string> res;
	string str;

	DFS(digit, 0, res, str, keyboard);

	return res;
}

int main () {

	string digit = "23";
	vector<string> res = letterCombinations(digit);

	for (size_t i = 0; i < res.size(); ++i) 
		cout << res[i] << endl;

	return 0;
}


