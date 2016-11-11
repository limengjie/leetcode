#include <iostream>
#include "bin_tree.h"

using namespace std;

////only print
//void preorderTrav(TreeNode * root) {
//	//base condition
//	if (root == nullptr) return;
//	//print root first
//	cout << root->_val << " ";
//	//print left subtree
//	preorderTrav(root->_left);
//	//print right subtree
//	preorderTrav(root->_right);
//}

void preorderTrav(TreeNode * pnode, vector<int> & res) {
	//base condition
	if (pnode == nullptr) return;

	//save the curent node
	res.push_back(pnode->_val);

	//save the rest nodes
	if (pnode->_left)
		preorderTrav(pnode->_left, res);
	if (pnode->_right)
		preorderTrav(pnode->_right, res);
}
	

void inorderTrav(TreeNode * pnode, vector<int> & res) {
	//base condition
	if (pnode == nullptr) return;

	//save the left node
	if (pnode->_left)
		inorderTrav(pnode->_left, res);

	//save the curent node
	res.push_back(pnode->_val);


	//save the right node
	if (pnode->_right)
		inorderTrav(pnode->_right, res);
}

void postorderTrav(TreeNode * pnode, vector<int> & res) {
	//base condition
	if (pnode == nullptr) return;

	//save the left node
	if (pnode->_left)
		inorderTrav(pnode->_left, res);
	
	//save the right node
	if (pnode->_right)
		inorderTrav(pnode->_right, res);

	//save the curent node
	res.push_back(pnode->_val);
}
	

int main() {
//	int array[] = {6, 4, 10, 2, 5, 7, 11, 1, 3, 0, 0, 9, 8};
	int array[] = {1, 0, 2, 3};
	TreeNode * root = buildBinTree(array, 4);

	vector<int> result; 
	postorderTrav(root, result);

	//print vector
	for (size_t i = 0; i < result.size(); ++i) 
		cout << result[i] << " ";
	cout << endl;

//	only print
//	preorderTrav(root);
//	cout << endl;

	return 0;
}
	
