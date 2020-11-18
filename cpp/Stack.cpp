//customized stack
//only store positive values
#include <iostream>
using namespace std;

template <typename T>
struct Node {
   T val;
   Node* next;
   Node(T v): val(v), next(nullptr) {}
};

template <typename T>
class Stack {
private:
   Node<T>* head = nullptr;
public:
   void push(T v) {
      //create a new node
      Node<T>* node = new Node<T>(v);
      //update head
      node->next = head;
      head = node;
   }
   void pop() {
      if (empty()) return;
      Node<T> * oldHead = head;
      head = head->next;
      oldHead->next = nullptr;
      delete oldHead;
   }
   T top() {
      return empty() ? -1: head->val;
   }
   bool empty() {
      return head == nullptr;
   }
};
   
int main() {
   Stack<int> stk;
   cout << stk.top() << endl;;
   stk.push(1);
   stk.push(2);
   stk.push(3);
   cout << stk.top() << endl;;
   stk.pop();
   stk.pop();
   cout << stk.top() << endl;;
   stk.pop();
   stk.pop();
   stk.pop();
   cout << stk.top() << endl;;

   return 0;
}
