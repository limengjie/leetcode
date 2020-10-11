//1st unique char in a str

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//traverse twice,
//in the first traverse, count the times of appearence,
//in the second travere, get the position
int firstUniqChar(string & str) {
	unordered_map<char, int> times;

	for (size_t i = 0; i < str.size(); ++i) {
		auto it = times.find(str[i]);
		if (it == times.end()) //first time appear
			times[str[i]] = 1;
		else
			++times[str[i]];
	}

	for (size_t i = 0; i < str.size(); ++i) {
		if (times[str[i]] == 1)
			return i;
	}

	return -1;
}

int main() {
	string str = "loveleetcode";

	int pos = firstUniqChar(str);

	cout << "pos = " << pos << endl;

	return 0;
}
