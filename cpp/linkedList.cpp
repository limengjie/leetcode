#include <iostream>
#include "linkedList.h"

using namespace std;

List::List() {
	_pHead = nullptr;
	_pTail = nullptr;
}

List::List(int v) {
	_pHead = new Node(v);
	_pTail = _pHead;
}

//List::List(Node * n) {
	//if (n == nullptr) {
		//_pHead = nullptr;
		//_pTail = nullptr;

		//return;
	//}
	//else {
		//_pHead = new Node(n->getVal());
	//}

	//Node * prev = _pHead;
	//Node * cur = _pHead->getNext();
	//while (cur) {
		//cout << "cur = " << cur->getVal() << endl;
		//prev = cur;
		//cur = cur->_pNext;
	//}
	//_pTail = prev;
//}

void List::append(int n) {
	//create a new node
	Node * pNode = new Node(n);

	//if it is the 1st elt
	if (_pHead == nullptr) {
		_pHead = pNode;
		_pTail = pNode;

		return;
	}

	//update old tail's next
	_pTail->setNext(pNode);

	//update tail
	_pTail = pNode;
}

void List::show() const {
	if (_pHead == nullptr) {
		cout << "empty list\n";
		return;
	}

	Node * pNode = _pHead;
	while (pNode != nullptr) {
		cout << pNode->getVal();
		if (pNode->getNext() != nullptr)
			cout << " -> ";
		pNode = pNode->getNext();
	}
	cout << endl;
}
		
List buildList(vector<int> vec) {
	if (vec.size() == 0) return List();
	List list(vec[0]);

	for (size_t i = 1; i < vec.size(); ++i) 
		list.append(vec[i]);

	return list;
}

void showNode(Node * res) {
	if (res) {
		int i = 0;
		for (Node * cur = res; cur; cur = cur->_pNext) {
			//prevent infinite loop
			++i;
			if (i > 100) {
				cout << "infinite loop\n";
				break;
			}
			cout << cur->_val;
			if (cur->_pNext)
				cout << "->";
		}
		cout << endl;
	}
}

	
//int main() {
	//vector<int> V = {1, 3, 2, 4, 5, 6};

	//List l = buildList(V);

	//l.show();

	//return 0;
//}
