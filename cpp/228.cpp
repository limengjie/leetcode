#include <iostream>
#include "linkedList.h"

using namespace std;

List swapPair(List list) {
	if (list.getHead() == nullptr) return list;

	Node * firstNode = list.getHead();
	Node * secondNode = firstNode->getNext();
	Node * oldFirstNode = nullptr;
	Node * nextNode;

	if (secondNode != nullptr)
		list.setHead(secondNode);

	while (firstNode != nullptr && secondNode != nullptr) {
		//swap
		nextNode = secondNode->getNext();
		firstNode->setNext(secondNode->getNext());
		secondNode->setNext(firstNode);
		if (firstNode) cout << "first = " << firstNode->getVal() << endl;
		if (secondNode) cout << "second = " << secondNode->getVal() << endl;
		if (oldFirstNode)
			oldFirstNode->setNext(secondNode);

		//update nodes
		oldFirstNode = firstNode;
		cout << "oldFirstNode = " << oldFirstNode->getVal() << endl;
		firstNode = nextNode;
		if (firstNode != nullptr)
			secondNode = firstNode->getNext();
		else//reach the end of the list
			list.setTail(secondNode->getNext()); //set the old first node as the tail

	}
	////update oldFirst node
	//oldFirstNode->setNext(firstNode);
	

	return list;
}

int main() {
	//vector<int> vec = {1, 2, 3, 4, 5, 6};
	vector<int> vec ;
	List l = buildList(vec);

	List res = swapPair(l);

	res.show();

	return 0;
}
