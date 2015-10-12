#include <iostream>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

class Solution {
	public:
		int fact(int n) {
			int ans = 1;

			for (int i = 1; i < n + 1; ++i) {
				ans *= i;
			}

			return ans;
		}

		vector<int> get_array(int n) {
			vector<int> vec;

			for (int i = 1; i < n + 1; ++i) 
				vec.push_back(i);

			return vec;
		}

		void swap_pos(vector<int> &num, int i, int j) {
			int temp = num.at(i);
			num.at(i) = num.at(j);
			num.at(j) = temp;
		}

		void reverse_rest(vector<int> &num, int begin) {
			int back = num.size() - 1;
			int front = begin;

			while (front < back) {
				swap_pos(num, front, back);
				++front;
				--back;
			}
		}

		void kth_permut(vector<int> &num, int k, int pos) {
			if (pos > num.size() - 1) return;

			int rmndr, qtnt;

			sort(num.begin() + pos, num.end());
			qtnt  = k / fact(num.size() - pos - 1);
			rmndr = k % fact(num.size() - pos - 1); 

			cout << "pos = " << pos << endl;
			cout << "quotient = " << qtnt << endl;
			cout << "remainder = " << rmndr << endl;

			if (rmndr == 0) { 
				//swap current pos with qtnt_th elt after pos,
				//reverse the rest
				swap_pos(num, pos, pos + qtnt - 1);
				reverse_rest(num, pos + 1);
				return;
			}
			else if (qtnt >= 1)
				swap_pos(num, pos, pos + qtnt);
			//sort the rest of numbers
			sort(num.begin() + pos + 1, num.end());

			//print 
			cout << "{";
			for (size_t i = 0; i < num.size(); ++i) 
				cout << num.at(i) << " ";
			cout << "}" << endl;


			kth_permut(num, rmndr, pos + 1);
		}

		vector<int> permutSeq(int n, int k) {
			vector<int> num;

			//assert 0 < n < 9
			if (n > 9 or n < 1)
				return num;
			//assert k < n!
			int f = fact(n);
			if (k <= 0 or k > f)
				return num;

			//generate a sorted array
			num = get_array(n);

			kth_permut(num, k, 0);

			return num;
		}
};

int main() {
	Solution solution;

	vector<int> vec = solution.permutSeq(5, 23);

	cout << "result: \n";
	cout << "{";
	for (size_t i = 0; i < vec.size(); ++i) 
		cout << vec.at(i) << " ";
	cout << "}" << endl;

	return 0;
}
