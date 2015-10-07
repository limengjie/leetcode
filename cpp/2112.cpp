#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int find_par_num(vector<int> &num) {
			// find the partition number's index
			int next;
			for (int prev = num.size() - 2; prev >= 0; --prev) {
				next = prev + 1;
				if (num.at(prev) < num.at(next))
					return prev;
			}

			return -1;
		}

		int find_chg_num(vector<int> &num, int par_num) {
			// find the change number's index
			for (int i = num.size() - 1; i >= 0; --i) {
				if (num.at(i) > par_num)
					return i;
			}

			return -1;
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

		void next_permutation(vector<int> &num) {
			//find the partition number 
			int par_index = find_par_num(num);
			cout << "partition index = " << par_index << endl;

			if (par_index >= 0) {// partition number exists
				//find the change number
				int chg_index = find_chg_num(num, num.at(par_index));
				cout << "change index = " << chg_index << endl;

				//swap two numbers
				swap_pos(num, par_index, chg_index);
				cout << "after swapping 2 numbers:" << endl;
				// print out the result
				for(size_t i = 0; i < num.size(); ++i) 
					cout << num.at(i) << endl;

				//reverse the rest of numbers
				reverse_rest(num, chg_index + 1);
				cout << "after reverse:" << endl;
				// print out the result
				for(size_t i = 0; i < num.size(); ++i) 
					cout << num.at(i) << endl;
			}
			else // no partition number, reverse all numbers
				reverse_rest(num, 0);



		}
};

int main() {
	Solution solution;

	int array[6] = {6, 8, 7, 4, 2, 3};
	vector<int> num(array, array + 6);
	
	solution.next_permutation(num);

	cout << "final result: " << endl;
	// print out the result
	for(size_t i = 0; i < num.size(); ++i) 
		cout << num.at(i) << endl;

	return 0;
}
