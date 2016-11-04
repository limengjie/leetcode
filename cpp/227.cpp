#include <iostream>
#include "linkedList.h"

using namespace std;

List rmKth(List list, int k) {
	if (list.getHead() == nullptr) return list;

	//get the length of the list
	Node * prevNode = list.getHead();
	Node * currNode = prevNode->getNext();
	int len = 1;
	while (currNode != nullptr) {
		++len;
		currNode = currNode->getNext();
	}

	//find the positions for kth and (k-1)th nodes
	int pos = len - (k % len);
	currNode = prevNode->getNext();
	int index = 1;
	while (index != pos) {
		prevNode = currNode;
		currNode = currNode->getNext();
		++index;
	}
	//rm the kth and link (k-1)th and (k+1)th
	prevNode->setNext(currNode->getNext());
	//if rm the last node, update the tail
	if (pos == len - 1)
		list.setTail(prevNode);

	return list;
}


int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	List l = buildList(vec);

	List res = rmKth(l, 1);

	res.show();

	return 0;
}
