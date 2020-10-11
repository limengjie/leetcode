#include <iostream>
#include <string>
#include <algorithm> //sort

using namespace std;

bool validAnagram(string s, string t) {
	string sorted_s, sorted_t;
	sorted_s = s;
	sorted_t = t;

	sort(sorted_s.begin(), sorted_s.end());
	sort(sorted_t.begin(), sorted_t.end());

	return sorted_s == sorted_t;
}


vector<int> findAnagrams(string s, string p) {
	vector<int> res;

	//if the pattern is longer than the string
	if (p.size() > s.size() || p.empty())
		return res;

	//bool valid = false;
	//char prev;
	for (size_t i = 0; i < s.size() - p.size() + 1; ++i) {
		//if last substr is a valid anagram,
		//only need to check the next char
		//if (valid) {
			//if (prev == s[last_pos])
				//res.push_back(i);
		//}
		//else {
			string sub_str = s.substr(i, p.size());
			//cout << sub_str << endl;
			if (validAnagram(sub_str, p)) {
					//valid = true;
					//prev = s[i];
					res.push_back(i);
			}
			//else {
				//valid = false;
			//}
		//}
	}

	return res;
}

int main () {
	string s = "cbaebabacd";
	string p = "abc";

	vector<int> res = findAnagrams(s, p);

	for (size_t i = 0; i < res.size(); ++i) 
		cout << res[i] << " ";
	cout << endl;

	return 0;
}



