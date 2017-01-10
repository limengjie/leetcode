//word break
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

bool isNext(string s, string t) {
	if (s.empty() || t.empty() || s.size() < t.size())
		return false;

	for (size_t i = 0; i < t.size(); ++i) {
		if (s[i] != t[i])
			return false;
	}

	return true;
}



bool wordBreak(string s, vector<string> & wordDict) {
	//initialize the queue
	queue<int> indices;
	//push the 1st index 0
	indices.push(0);

	//use BFS to find if there is a way 
	while (!indices.empty()) {
		//get the front elt from queue
		int nextInd = indices.front();
		indices.pop();

		//compare string with wordDict
		string rest = s.substr(nextInd);
		for (size_t i = 0; i < wordDict.size(); ++i) {
			if (isNext(rest, wordDict[i])) {
				int newNextInd = nextInd + wordDict[i].size();
				//if all the words are found
				if (newNextInd == s.size())
					return true;
				indices.push(newNextInd);
			}
		}
	}

	return false;
}

int main() {
	vector<string> dict = {"lee", "leet", "code"};
	string s = "leetcode";

	bool isWB = wordBreak(s, dict);

	if (isWB)
		cout << "word break\n";
	else
		cout << "no\n";

	return 0;
}

