#include <iostream>
#include "linkedList.h"

using namespace std;

List rmDupList(List list) {
	List res;
	if (list.getHead() == nullptr) 
		return res;

	Node * prevNode = list.getHead();
	Node * pNode = prevNode->getNext();
	res.append(prevNode->getVal());
	while (pNode != nullptr) {
		cout << "prev = " << prevNode->getVal();
		cout << ", cur = " << pNode->getVal() << endl;
		if (pNode->getVal() != prevNode->getVal()) {
				//link two nodes
				prevNode->setNext(pNode);
				//save the result
				res.append(pNode->getVal());
				//update prev node
				prevNode = pNode;
		}
		//update the current node
		pNode = pNode->getNext();
	}
	//update the tail
	res.setTail(prevNode);

	return res;
}

int main() {
	vector<int> vec = {1, 2, 2,  3, 3, 3, 3};
	List l = buildList(vec);

	List res = rmDupList(l);

	res.show();

	return 0;
}
