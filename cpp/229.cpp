#include <iostream>
#include "linkedList.h"

using namespace std;

//List reverseKGroup(List list, int k) {
        //if (list.getHead() == nullptr || k < 2) return list;

        //vector<int> num;
        //List res;
        
        //Node * prevNode = list.getHead();
        //Node * currNode = prevNode->getNext();
        //num.push_back(prevNode->getVal());
        //int idx = 1;
        //while (currNode != nullptr) {
                ////update the index
                //++idx;
                ////save the result in vector temporarily
                //num.push_back(currNode->getVal());
                ////if have an entire group,
                ////append them in the list
                //if (idx == k) {
                        ////reset the index
                        //idx = 0;
                        //for (auto rit = num.rbegin(); rit != num.rend(); ++rit) 
                                //res.append(*rit);
                        //num.clear();
                //}
                                
                ////update node ptrs
                //prevNode = currNode;
                //currNode = currNode->getNext();
        //}
        //if (num.size()) { // if there are elts not appended in the list
                //for (auto it = num.begin(); it != num.end(); ++it)
                        //res.append(*it);
        //}

        //return res;
//}

//In place
Node * reverseKGroup(Node * head, int k) {
	if (head == nullptr) return head;

	//create a dummy node
	Node dummy(-1);
	dummy._pNext = head;

	//reverse
	Node * prev = &dummy;
	Node * cur = head;
	Node * oldNext, newTail;
	int i;
	while (cur != nullptr) {
		for (i = 0; i < k && cur != nullptr; ++i) {
			if (i == 0) newTail = cur;
			oldNext = cur->_pNext;
			cur->_pNext = prev->_pNext;
			prev->_pNext = cur;
			cur = oldNext;
		}
		//break the old link
		newTail->_pNext = nullptr;
		if (i == k) prev = newTail;
		
	}

	//reverse the left-out nodes 
	//if the length of the list is not a
	//multiple of k
	if (i != k) {
		//set the first node as the tail of the list
		newTail = prev->_pNext;
		cur = prev->_pNext;
		while (cur != nullptr) {
			oldNext = cur->_pNext;
			cur->_pNext = prev->_pNext;
			prev->_pNext = cur;
			cur = oldNext;
		}
		newTail->_pNext = nullptr;
	}

	return dummy._pNext;
}

int main() {
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	//vector<int> vec = {1, 3} ;
	//vector<int> vec;
	List l = buildList(vec);

	Node * res = reverseKGroup(l.getHead(), 3);
	showNode(res);

	//List res = reverseKGroup(l, 5);

	//res.show();

	return 0;
}
