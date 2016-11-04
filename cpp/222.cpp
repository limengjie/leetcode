#include <iostream>
#include "linkedList.h"

using namespace std;

//List reverseList(List list, int m, int n) {
	//if (m > n) {//exchange m n
		//int tmp = m;
		//m = n;
		//n = tmp;
	//}

	////cout << "save the results from pos m to n\n";
	////save the results from pos m to n
	//vector<int> values;
	//int i = 0;
	//Node * prevNode = nullptr;
	//Node * nextNode = nullptr;
	//Node * pNode = list.getHead();
	//int v;
	//while (i <= n && pNode != nullptr) {
		////get the previous node and change its next ptr later
		//if (i == m - 1)
			//prevNode = pNode;
		////save the results from pos m to n
		//if (i >= m)  {
			//v = pNode->getVal();
			//values.push_back(v);
		//}
		////update the node and index
		//pNode = pNode->getNext();
		//++i;
	//}
	//if (i < m) // m > length of the linked list
		//return list;

	////get next node
	//nextNode = pNode;

	////cout << "link to the new sublist\n";
	////link to the new sublist
	////update the tail to use append funct later
	//list.setTail(prevNode);
	//if (m == 0)
		//list.setHead(nullptr);


	////cout << "append the reversed list\n";
	////append the reversed list
	//for (auto rit = values.rbegin(); rit != values.rend(); ++rit) {
		//list.append(*rit);
	//}
	////append the rest of the list
	//pNode = nextNode;
	//while (pNode != nullptr) {
		//v = pNode->getVal();
		//list.append(v);
		////update the node
		//pNode = pNode->getNext();
	//}
	//return list;
//}

//In place
Node * reverseList(Node * head, int m, int n) {
	if (m > n) {
		int temp = m;
		m = n;
		n = temp;
	}

	//get the (m-1)th node
	Node dummy(-1);
	dummy._pNext = head;
	Node * mHead = &dummy;
	for (int i = 0; i < m - 1 && mHead != nullptr; ++i) {
		mHead = mHead->_pNext;
	}

	//cout << "mHead = " << mHead->_val << endl;

	//check if the m is out of the range
	if (mHead == nullptr) return head;

	//reverse
	Node * cur = mHead->_pNext;
	Node * nTail = cur;
	Node * oldNext;
	for (int i = m; i < n + 1 && cur != nullptr; ++i) {
		cout << "cur = " << cur->_val << endl;
		//insert the node in front of the list
		oldNext = cur->_pNext;
		cur->_pNext = mHead->_pNext;
		mHead->_pNext = cur;
		//update nodes
		cur = oldNext;
	}
	//link to the rest of the nodes
	nTail->_pNext = cur;

	return dummy._pNext;
}

int main() {
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6};

	List l = buildList(vec);

	Node * res = reverseList(l.getHead(), 2, 40);

	cout << "show new list: \n";
	showNode(res);

	return 0;
}
