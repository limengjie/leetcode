//Group Anagrams
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> //sort

using namespace std;

string sort_str(string & str) {
	string res = str;

	sort(res.begin(), res.end());

	return res;
}
	
vector<vector<string>> groupAnagrams(vector<string> & strs) {
	vector<vector<string>> res;
	//map_entry.first is the sorted string
	//map_entry.second is the index in 2D vec
	unordered_map<string, int> str_map;


	for (size_t i = 0; i < strs.size(); ++i) {
		//sort the str 1st
		string sorted_str = sort_str(strs[i]);

		//find this str in map
		int vec_ind;
		auto it = str_map.begin();
		for ( ; it != str_map.end(); ++it) {
			//if anagram is found
			if (it->first == sorted_str) {
				//add the new str to the vec 
				vec_ind = it->second;
				res[vec_ind].push_back(strs[i]);
				break;
			}
		}
		if (it == str_map.end()) {//if not found
			//this is the 1st str of its group
			//store the new anagram
			vector<string> new_row;
			new_row.push_back(strs[i]);
			res.push_back(new_row);
			//get the vector index(map_entry.second)
			vec_ind = res.size() - 1;
			//create the new map entry
			str_map[sorted_str] = vec_ind;
		}
	}

	return res;
}

int main() {
	vector<string> strs = {"eatt", "ttea", "tan", "atte", "nat", "bat"};

	vector<vector<string>> res = groupAnagrams(strs);
	
	//show 2d vector
	cout << "res:\n";
	cout << "[\n";
	for (size_t i = 0; i < res.size(); ++i) {
		for (size_t j = 0; j < res[i].size(); ++j) {
			if (j == 0) 
				cout << "   [";
			cout << res[i][j];
			if (j != res[i].size() - 1)
				cout << ", ";
		}
		cout << "]";
		if (i == res.size() - 1)
			cout << "\n]\n";
		else
			cout << ",\n";
	}

	return 0;
}

				





