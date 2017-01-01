//word ladder #91 #92
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

//recursively find the target string,
//from the end string trace back to the start string

void showUSet(const unordered_set<string> & uset) {
	cout << "elts in set:\n";
	for (auto it = uset.begin(); it != uset.end(); ++it) 
		cout << *it << " ";
	cout << endl;
}

bool convertible(const string & s0, const string & s1) {
	//if the difference is only one char, 
	//these two strings are convertible
	if (s0.size() != s1.size())
		return false;

	if (s0.empty() && s1.empty())
		return false;

	int diff = 0;
	for (size_t i = 0; i < s0.size(); ++i) {
		if (s0[i] != s1[i]) 
			++diff;
	}

	return (diff == 1) ? true : false;
}

//int recurFind(const string & start, const string & end,
		//int cur_lvl, unordered_set<string> & notVisited) { 
	////if target string is found
	//if (convertible(end, start)) {
		//cout << "reach the end\n";
		//cout << start << endl;
		//return cur_lvl;
	//}

	////remove the target string first
	//notVisited.erase(start);
	//if (notVisited.empty())
		//return 0;

	////recursively try every possible path
	//int min_lvl = 0;
	//int level = 0;//possible level
	//auto it = notVisited.begin();
	//for (; it != notVisited.end(); ++it) {
		//if (convertible(*it, start)) {
			//level = recurFind(*it, end, cur_lvl + 1, notVisited);
			//if (level > 0) {
				//if (min_lvl == 0) 
					//min_lvl = level;
				//else
					//min_lvl = (level < min_lvl) ? level : min_lvl;
			//}
		//}
	//}

	//if (level) cout << start << endl;
	//showUSet(notVisited);
	//notVisited.insert(start);
	//return min_lvl;
//}


int ladderLen(const string & start, const string & end,
		unordered_set<string> & dict) {
	unordered_set<string> notVisited(dict);
	int level = 1;
	int n_cur_lvl = 1;//the # of elts at current level
	int n_next_lvl = 0;//the # of elts at next level

	//initialization
	queue<string> next_q;//visiting order
	next_q.push(end);

	unordered_set<string> removed;
	while (!next_q.empty()) {
		showUSet(notVisited);
		cout << "=======================\n";
		cout << "level " << level << endl;
		cout << "=======================\n";
		//get the 1st elt from queue
		string str = next_q.front();
		next_q.pop();
		cout << str << endl;

		//target string is found
		if (convertible(str, start)) {
			return level;
		}

		auto it = notVisited.begin();
		cout << "children:\n";
		removed.clear();
		for (; it != notVisited.end() && !notVisited.empty(); ++it) {
			if (convertible(str, *it)) {
				//if it is convertible,
				//push it in queue and remove it from notVisited set
				next_q.push(*it);
				removed.insert(*it);
				++n_next_lvl;
				cout << "(convertible)";
			}
			cout << "\t" << *it << endl;
		}
		//update not visited set
		//it costs too much space and time
		//should be optimized
		for (auto it = removed.begin(); it != removed.end(); ++it) 
			notVisited.erase(*it);
		//update the # of elt at ea level
		--n_cur_lvl;
		if (n_cur_lvl == 0) { 			
			n_cur_lvl = n_next_lvl;
			n_next_lvl = 0;
			++level;
		}
	}

	return 0;
}

vector<vector<string>> traceBack(const vector<string> & last_str,
		unordered_map<string, string> & parent, const string & start) {
	vector<vector<string>> res;
	for (size_t i = 0; i < last_str.size(); ++i) {
		vector<string> row;//one of solutions
		string str = last_str[i];
		while (str != start) {
			row.push_back(str);
			str = parent[str];
		}
		res.push_back(row);
	}

	return res;
}


vector<vector<string>> findLadders(const string & start, const string & end,
		unordered_set<string> & dict) {
	vector<vector<string>> res;
	vector<string> last_str;
	unordered_map<string, string> parent;
	unordered_set<string> notVisited(dict);
	//int level = 1;
	//int n_cur_lvl = 1;//the # of elts at current level
	//int n_next_lvl = 0;//the # of elts at next level

	//initialization
	queue<string> next_q;//visiting order
	next_q.push(end);

	unordered_set<string> removed;
	while (!next_q.empty()) {
		//showUSet(notVisited);
		//cout << "=======================\n";
		//cout << "level " << level << endl;
		//cout << "=======================\n";
		//get the 1st elt from queue
		string str = next_q.front();
		next_q.pop();
		cout << str << endl;

		//target string is found
		if (convertible(str, start)) {
			parent[str] = start;
			last_str.push_back(str);
		}

		cout << "children:\n";
		auto it = notVisited.begin();
		removed.clear();
		for (; it != notVisited.end() && !notVisited.empty(); ++it) {
			if (convertible(str, *it)) {
				//if it is convertible,
				//push it in queue and remove it from notVisited set
				next_q.push(*it);
				removed.insert(*it);
				//++n_next_lvl;
				parent[*it] = str;
				cout << "(convertible)";
			}
			cout << "\t" << *it << endl;
		}
		//update not visited set
		//it costs too much space and time
		//should be optimized
		for (auto it = removed.begin(); it != removed.end(); ++it) 
			notVisited.erase(*it);
		////update the # of elt at ea level
		//--n_cur_lvl;
		//if (n_cur_lvl == 0) { 			
			//n_cur_lvl = n_next_lvl;
			//n_next_lvl = 0;
			//++level;
		//}
	}

	res = traceBack(last_str, parent, start);

	return res;
}
	
int main() {
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot", "dog", "dot", "lot", "log"};

	//int len = ladderLen(start, end, dict);
	//cout << "len = " << len << endl;
	//
	vector<vector<string>> ladders = findLadders(start, end, dict);

	cout << "ladders:\n";
	for (size_t i = 0; i < ladders.size(); ++i) {
		for (size_t j = 0; j < ladders[0].size(); ++j) {
			cout << ladders[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
