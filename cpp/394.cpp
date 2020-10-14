#include <iostream>
#include <string>
#include <stack>

using namespace std;

string helper(string s, size_t& i)
{
    string res, sub_str;
    int freq = 0;
    while (i < s.size())
    {
        if (isdigit(s[i]))
           freq = freq* 10 + (s[i] - '0');
        else if (isalpha(s[i])) 
           res.push_back(s[i]);
        else if (s[i] == '[') 
        {
	    sub_str = helper(s, ++i);
            while (freq)
            {
               res += sub_str;
               freq--;
            }
        }
        else if (s[i] == ']' or i == s.size() - 1) 
           return res;
        i++;
    }
    return res;
}

string calculate(string s) {
   if (s.empty()) return 0;
   size_t i = 0;
   return helper(s, i);
}

int main() {
   string s {"3[a]2[bc]"};
   cout << calculate(s) << endl;

   return 0;
}
