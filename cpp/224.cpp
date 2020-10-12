#include <iostream>
#include <string>
#include <stack>

using namespace std;

//basic calculator
int calc(stack<int>& stk)
{
    int sum = 0;
    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
            
    return sum;
}

int helper(string s, size_t& i)
{
    stack<int> stk;
    int sign = 1;
    int num = 0;
    for (; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
            num = num * 10 + (s[i] - '0');
        else if (s[i] != ' ') // '(', ')', '+' ,'-'
        {
            switch(s[i])
            {
                case '(':
                    num = helper(s, ++i);
                    break;
                case '+':
                    stk.push(num * sign);
                    num = 0;
                    sign = 1;
                    break;
                case '-':
                    stk.push(num * sign);
                    num = 0;
                    sign = -1;
                    break;
                case ')':
                    stk.push(num * sign);
                    return calc(stk);
            }
        }
        if (i == s.size() - 1)
	    stk.push(num * sign);
    }
    return calc(stk);
}

int calculate(string s) {
   if (s.empty()) return 0;
   size_t i = 0;
   return helper(s, i);
}

int main() {
   string s {"(1+(5+4+2)-3)+(6+8)"};
   //string s {"(2+3+4)+3"};
   cout << calculate(s) << endl;

   return 0;
}
