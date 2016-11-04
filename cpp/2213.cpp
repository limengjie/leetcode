#include <iostream>
#include "linkedList.h"

using namespace std;

void reorderList(List & list) {
	if (list.getHead() == nullptr) return;

	//get the length and median node
	Node * currNode = list.getHead();
	Node * medianNode = list.getHead();
	Node * prevMidNode = nullptr;
	int is_mv_med = 1;
	while (currNode != nullptr) {
		//slow ptr medianNode proceed 1 step
		//after currNode proceed 2 steps
		is_mv_med *= -1;
		if (is_mv_med > 0) {
			prevMidNode = medianNode;
			medianNode = medianNode->getNext();
		}
		currNode = currNode->getNext();
	}

	//if the # of nodes <= 2
	if (prevMidNode == nullptr) 
		return;
	//divide the list into 2 parts
	prevMidNode->setNext(nullptr);
	//reverse the 2nd part
	Node * prevNode = nullptr;
	Node * nextNode;
	currNode = medianNode;
	while (currNode != nullptr) {
		cout << "curr = " << currNode->getVal() << endl;
		nextNode = currNode->getNext();
		currNode->setNext(prevNode);
		prevNode = currNode;
		currNode = nextNode;
	}
	Node * head2node = prevNode;

	////debug
	//cout << "median = " << medianNode->getVal() << endl;
	//currNode = medianNode;
	//while (currNode != nullptr) {
		//cout << currNode->getVal() << "\t";
		//currNode = currNode->getNext();
	//}
	//cout << endl;

	//merge two lists
	Node * curr1 = list.getHead();
	Node * curr2 = head2node;
	Node * oldPrev = nullptr;
	Node * curr1Next;
	Node * curr2Next;
	while (curr1 != nullptr && curr2 != nullptr) {
		curr1Next = curr1->getNext();
		curr2Next = curr2->getNext();
		//link node
		if (oldPrev != nullptr)
			oldPrev->setNext(curr1);
		curr1->setNext(curr2);

		//update node ptrs
		oldPrev = curr2;
		curr1 = curr1Next;
		curr2 = curr2Next;
	}
	while (curr1 != nullptr) {
		oldPrev->setNext(curr1);
		oldPrev = curr1;
		curr1 = curr1->getNext();
	}
	//set  tail
	list.setTail(oldPrev);
}


int main() {
	vector<int> vec = {1, 2, 3, 4, 5, 6};
	//vector<int> vec = {1, 3} ;
	List l = buildList(vec);

	reorderList(l);

	l.show();

	return 0;
}

