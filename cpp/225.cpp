#include <iostream>
#include "linkedList.h"

using namespace std;

//List rmDupList2(List list) {
	//List res;
	//if (list.getHead() == nullptr) 
		//return res;

	////Node * prevNode = list.getHead();
	////Node * currNode = prevNode->getNext();
	//Node * prevNode = nullptr;
	//Node * currNode = list.getHead();
	////if there is only one node
	//if (currNode == nullptr) {
		//res.append(prevNode->getVal());
		//return res;
	//}
	//Node * nextNode = currNode->getNext();

	////compare three contiguous nodes to determine 
	////if the middle one is distinct or not
	//while (currNode != nullptr) {
		//int prev = (prevNode == nullptr) ? -2 : prevNode->getVal();
		//int curr = currNode->getVal();
		//int next = (nextNode == nullptr) ? -1 : nextNode->getVal();
		//cout << "prev = " << prev;
		//cout << ", cur = " << curr;
		//cout << ", next = " << next << endl;
		//if (curr != prev && curr != next) {
				////save the result
				//res.append(curr);
		//}
		////update the nodes
		//prevNode = currNode;
		//currNode = nextNode;
		//if (nextNode != nullptr)
			//nextNode = nextNode->getNext();
	//}
	////update the tail
	//res.setTail(prevNode);

	//return res;
//}

//in place
Node * rmDupList2(Node * head) {
	Node dummy(-1);
	dummy._pNext = head;
	Node * last = &dummy;
	Node * prev = &dummy;
	Node * cur = dummy._pNext;
	Node * next = cur == nullptr ? nullptr : cur->_pNext;

	for (; cur; 
	cur = cur->_pNext, prev = prev->_pNext, 
	next = next == nullptr ? nullptr : next->_pNext) {
		//if three node in a row are different,
		//add the middle one to the new list
		int prev_val = prev->_val;
		int cur_val  = cur->_val;
		int next_val = next == nullptr ? -1 : next->_val;
		if (prev_val != cur_val && cur_val != next_val) {
			last->_pNext = cur;
			last = cur;
		}
	}
	last->_pNext = nullptr;

	return dummy._pNext;
}


int main() {
	vector<int> vec = {1, 2, 3, 3, 3, 3, 4};
	//vector<int> vec = {1, 2, 2};
	List l = buildList(vec);

	Node * res = rmDupList2(l.getHead());
	showNode(res);

	return 0;
}
