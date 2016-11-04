#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <vector>

//struct ListNode {
        //int val;
        //ListNode * next;
        //ListNode(int x) : val(x), next(nullptr) {}
//}; 

class Node {
        //private:
        public:
                int _val;
                Node * _pNext;
                //ctor
                Node() : _val(0), _pNext(nullptr) {}
                Node(int x) : _val(x), _pNext(nullptr) {}
                int getVal() { return _val; }
                Node * getNext() { return _pNext; }
                void setVal(int v) { _val = v; }
                void setNext(Node * pNode) { _pNext = pNode; }
};

class List {
        private:
                Node * _pHead;
                Node * _pTail;
        public:
                //ctor
                List();
                List(int v);
                //List(Node * n);
                Node * getHead() { return _pHead; }
                Node * getTail() { return _pTail; }
                void setHead(Node * head) { _pHead = head; }
                void setTail(Node * tail) { _pTail = tail; }
                void append(int n);
                //int pop();
                void show() const;
};

List buildList(std::vector<int> vec);
void showNode(Node * n);

#endif
