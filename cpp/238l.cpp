//product of array except self
#include <iostream>
#include <vector>

using namespace std;

vector<int> productES(vector<int> & array) {
	//store the factorial
	int len = (int)array.size();
	int * fac_front = new int[len];
	//int * fac_back = new int[len];
	vector<int> res;
	for (size_t i = 0; i < array.size(); ++i) 
		res.push_back(0);

	//traverse the array in order,
	//get the factorial
	int fac = 1;
	fac_front[0] = 1;
	for (int i = 1; i < len; ++i) {
		fac *= array[i - 1];
		fac_front[i] = fac;
	}

	//traverse the array in inverse order
	fac = 1;
	for (int i = len - 1; i >= 0; --i) {
		//get the inverse factorial
		if (i != len - 1) 
			fac *= array[i + 1];

		res[i] = fac * fac_front[i];
	}

	return res;
}

int main() {
	vector<int> vec = {1, 2, 3, 4};

	vector<int> res = productES(vec);

	for (size_t i = 0; i < res.size(); ++i) 
		cout << res[i] << " ";
	cout << endl;

	return 0;
}






	

