#include <iostream>
#include "linkedList.h"

using namespace std;

List rotateList(List list, int k) {
	if (list.getHead() == nullptr)//empty list
		return list;

	Node * prevNode = list.getHead();
	Node * currNode = prevNode->getNext();
	int len = 1;
	//get the length of the list 
	while (currNode != nullptr) {
		++len;
		prevNode = currNode;
		currNode = currNode->getNext();
	}
	//connect the head and the tail
	prevNode->setNext(list.getHead());

	cout << "len = " << len << endl;

	//find the position for new head node
	int newHeadPos = len - (k % len);
	//find the new head and tail
	int pos = 0;
	prevNode = list.getHead();
	currNode = prevNode->getNext();
	while (pos != newHeadPos - 1) {
		prevNode = currNode;
		currNode = currNode->getNext();
		++pos;
	}
	cout << "new head = " << currNode->getVal();
	cout << ", new tail = " << prevNode->getVal() << endl;
	//set new head and tail
	list.setHead(currNode);
	list.setTail(prevNode);

	//break the list
	prevNode->setNext(nullptr);
	
	return list;
}
	
	


int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	List l = buildList(vec);

	List res = rotateList(l, 2);

	res.show();

	return 0;
}
