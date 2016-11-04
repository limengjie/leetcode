#include <iostream>
#include "linkedList.h"

using namespace std;

//in place, only use Node(int x) ctor
Node * add2num(Node * la, Node * lb) {
        Node dummy(-1);
        Node * res = &dummy;
        Node * na, * nb;
        int a, b, sum, carry = 0;
        for (na = la, nb = lb; na != nullptr || nb != nullptr;
                        na = na == nullptr ? nullptr : na->_pNext,
                        nb = nb == nullptr ? nullptr : nb->_pNext,
                        res = res->_pNext) {
                a = (na == nullptr) ? 0 : na->_val;
                b = (nb == nullptr) ? 0 : nb->_val;

                cout << "a = " << a << ", b = " << b << endl;

                sum = a + b + carry;
                carry = sum / 10;
                sum %= 10;

                cout << "sum = " << sum << endl;

                res->_pNext = new Node(sum);
                //res = res->_pNext;
                //cout << "after update next\n";
        }
        if (carry)
                res->_pNext = new Node(carry);

        return dummy._pNext;
}

//List add2num(List la, List lb) {
        //List res = List();
        //Node * aNode = la.getHead();
        //Node * bNode = lb.getHead();
        //int a, b, sum, carry = 0;
        //while (aNode != nullptr || bNode != nullptr) {
                ////get numbers
                //if (aNode == nullptr) 
                        //a = 0;
                //else {
                        //a = aNode->getVal();
                        //aNode = aNode->getNext();
                //}
                //if (bNode == nullptr)
                        //b = 0;
                //else {
                        //b = bNode->getVal();
                        //bNode = bNode->getNext();
                //}

                ////calculate
                //sum = a + b + carry;
                //carry = sum / 10;
                //sum %= 10;

                ////save the result
                //res.append(sum);
        //}
        //if (carry != 0)
                //res.append(carry);

        //return res;
//}

int main() {
        vector<int> va = {3, 3};
        vector<int> vb = {1, 2, 9, 9};

        List la = buildList(va);
        List lb = buildList(vb);

        la.show();
        lb.show();

        Node * res = add2num(la.getHead(), lb.getHead());
        showNode(res);

        //if (res) {
                //for (Node * cur = res; cur; cur = cur->_pNext) 
                        //cout << cur->_val << "\t";
                //cout << endl;
        //}

        //List res(add2num(la.getHead(), lb.getHead()));

        //res.show();

        return 0;
}
