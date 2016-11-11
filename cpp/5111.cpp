#include <iostream>
#include <stack>
#include "bin_tree.h"

using namespace std;

void flattenTree(TreeNode * root) {
	TreeNode * prev = nullptr;
	TreeNode * cur;
	stack<TreeNode *> stk;

	//initialize
	stk.push(root);

	while (!stk.empty()) {
		//get root node
		cur = stk.top();
		stk.pop();

		//push children into stack
		if (cur->_right)
			stk.push(cur->_right);
		if (cur->_left)
			stk.push(cur->_left);
		
		//covert the root node into linked list node
		if (prev != nullptr)
			prev->_right = cur;
		//disable its left node
		cur->_left = nullptr;
		//update prev node
		prev = cur;
	}
}
		
int main() {
	int array[] = {1, 2, 3, 4, 5, 6};
	TreeNode * root = buildBinTree(array, 6);

	flattenTree(root);

	showBinTree(root);

	return 0;
}

