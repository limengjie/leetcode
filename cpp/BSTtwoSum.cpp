#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "bin_tree.h"

using namespace std;

TreeNode* inorder(stack<TreeNode*>& stk, bool isReverse)
{
   TreeNode* p = stk.top();
   stk.pop();

   while (p != nullptr) 
   {
      stk.push(p);
      if (!isReverse) p = p->_left;
      else p = p->_right;
   }
   
   
   if (stk.empty()) return nullptr;
   p = stk.top();
   stk.pop();
   // cout << p->_val << endl;
   if (p)
   {
      if (!isReverse)
         stk.push(p->_right);
      else
         stk.push(p->_left);
   }
   
   return p;
 
}

bool findTarget(TreeNode* bst0, TreeNode* bst1, int target)
{
   TreeNode* n0, *n1;
   stack<TreeNode*> stk0, stk1;
   stk0.push(bst0);
   stk1.push(bst1);
   n0 = inorder(stk0, false);
   n1 = inorder(stk1, true);
   while (n0 and n1)
   {
      cout << "n0 = " << n0->_val << ", n1 = " << n1->_val << endl;
      int sum = n0->_val + n1->_val;
      if (sum < target)
         n0 = inorder(stk0, false);
      else if (sum > target)
         n1 = inorder(stk1, true);
      else
         return true;
   }

   return false;
}

int main()
{
   int arr0[5] = {1, 2, 3, 4, 5};
   int arr1[3] = {6, 17, 28};
   TreeNode * bst0 = buildBST(arr0, 5);
   TreeNode * bst1 = buildBST(arr1, 3);
   
   if (findTarget(bst0, bst1, 22)) cout << "target found\n";
   else cout << "target not found\n";

   return 0;
}
