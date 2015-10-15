#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int gasStation(vector<int> &gas, vector<int> &cost) {
			size_t pos;
			for (size_t i = 0; i < gas.size(); ++i) {
				//select start point
				int sum = 0;
				for (size_t j = 0; j < gas.size(); ++j) {
					pos = i + j;
					if (pos > gas.size() - 1)
						pos -= gas.size();
					cout << "pos = " << pos << endl;
					//finish single loop
					sum += gas[pos] - cost[pos];
					cout << " sum = " << sum << endl;
					if (sum  < 0) 
						break;
					//if found solution
					if (j == gas.size() - 1)
						return i;
				}
			}
			return -1;
		}

};

int main() {
	int g[] = {2, 5, 6, 7, 8, 5};
	int c[] = {3, 4, 9, 8, 7, 2};

	vector<int>  gas(g, g+6);
	vector<int> cost(c, c+6);

	Solution solution;
	int start = solution.gasStation(gas, cost);
	if (start != -1) 
		cout << "start point is " << start << endl;

	return 0;
}
