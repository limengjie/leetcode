#include <iostream>
#include "linkedList.h"

using namespace std;

List partList(List list, int x) {
	vector<int> less, ge;
	List res;

	Node * pNode = list.getHead();
	while (pNode != nullptr) {
		//split the list
		int v = pNode->getVal();
		if (v < x)
			less.push_back(v);
		else
			ge.push_back(v);

		//update the node
		pNode = pNode->getNext();
	}

	//merge the list
	for (size_t i = 0; i < less.size(); ++i) 
		res.append(less[i]);
	for (size_t i = 0; i < ge.size(); ++i)
		res.append(ge[i]);
	
	return res;
}

int main() {
	vector<int> vec = {1, 4, 3, 2, 5, 2};
	List l = buildList(vec);

	List res = partList(l, 3);

	res.show();

	return 0;
}
