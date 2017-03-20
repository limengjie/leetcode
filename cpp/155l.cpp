//min stack

#include <iostream>
#include <stack>
#include <climits> //INT_MAX

using namespace std;

class MinStack {
        private:
                stack<int> min_stack;
                int min;
        public:
                MinStack() {
                        min = INT_MAX;
                }
                void push(int x) {
                        if (x < min) {
                                //store the current min val
                                min_stack.push(min);
                                //update the min val
                                min = x;
                        }
                        min_stack.push(x);
                }
                void pop() {
                        int old_top = min_stack.top();
                        min_stack.pop();
                        if (old_top == min) {//if the min val is popped
                                //update the next min val as the new min val
                                min = min_stack.top();
                                min_stack.pop();
                        }
                }
                int top() {
                        return min_stack.top();
                }
                int getMin() {
                        return min;
                }
                void test() {
                        while (!min_stack.empty()) {
                                cout << min_stack.top() << endl;
                                min_stack.pop();
                        }
                }
};

int main() {
        int min;
        MinStack minstack;
        minstack.push(3);
        minstack.push(0);
        minstack.push(2);
        minstack.push(-1);
        //minstack.test();
        //min = minstack.getMin();
        //cout << "min = " << min << endl;
        //minstack.pop();
        //min = minstack.getMin();
        //cout << "min = " << min << endl;

        return 0;
}





