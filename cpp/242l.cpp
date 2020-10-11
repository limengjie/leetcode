#include <iostream>
#include <string>
#include <algorithm> // sort

using namespace std;

bool validAnagram(string s, string t) {
	string sorted_s, sorted_t;
	sorted_s = s;
	sorted_t = t;

	sort(sorted_s.begin(), sorted_s.end());
	sort(sorted_t.begin(), sorted_t.end());

	return sorted_s == sorted_t;
}

int main() {
	string s = "anagram";
	string t = "rngaaam";

	bool isAnagram = validAnagram(s, t);

	if (isAnagram)
		cout << "valid anagram\n";
	else
		cout << "invalid \n";

	return 0;
}


