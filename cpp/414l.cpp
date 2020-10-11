#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

//int thirdMax(vector<int> & nums) {
	////this array is used to store the max 3 nums
	//list<int> max;
	////traverse the array
	//for (size_t i = 0; i < nums.size(); ++i) {
		////insert the num into list
		////find the pos for new num
		//auto it = max.begin();
		//for (; it != max.end(); ++it) {
			////don't store the identical elt
			//if (nums[i] == *it)
				//break;

			//if (nums[i] > *it) {
				//max.insert(it, nums[i]);
				//if (max.size() > 3) 
					//max.pop_back();
				//break;
			//}
		//}
		////if the list is not full
		//if (it == max.end() && max.size() < 3)
			//max.push_back(nums[i]);
	//}


	//////debug
	////for (auto it = max.begin(); it != max.end(); ++it) 
		////cout << *it << " ";
	////cout << endl;

	////return the result
	//if (max.size() == 0)//if nums.size() == 0
		//return -1;//assume all nums > 0
	//else if (max.size() < 3)
		//return max.front();
	//else {
		//return max.back();
	//}

//}

//optimal solution
//set is a container which is used to store unique elts
//it has ascending order by default
int thirdMax(vector<int> & nums) {
	set<int> top3;
	for (int num : nums) {
		top3.insert(num);
		if (top3.size() > 3)
			top3.erase(top3.begin());
	}

	return (top3.size() == 3) ? *top3.begin() : *top3.rbegin();
}

int main() {
	//vector<int> vec = {4,3, 2, 1};
	//vector<int> vec = {2, 1, 1};
	vector<int> vec = {1, 1, 1, 2, 2, 3, 4} ;
	//vector<int> vec ;
	
	int third = thirdMax(vec);

	cout << "3rd max = " << third << endl;

	return 0;
}



		



