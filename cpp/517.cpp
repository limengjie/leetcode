#include <iostream>
#include "bin_tree.h"

using namespace std;

void inorderTrav(TreeNode * root, vector<TreeNode *> & sorted) {
	if (root == nullptr) return;

	if (root->_left != nullptr)
		inorderTrav(root->_left, sorted);

	sorted.push_back(root);
	
	if (root->_right != nullptr)
		inorderTrav(root->_right, sorted);
}
	
void recoverOrder(vector<TreeNode *> & vec) {
	TreeNode * prev;
	TreeNode * errNode0, * errNode1;

	//find the unordered node from left to right
	prev = *vec.begin();
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		if (prev->_val > (*it)->_val) {
			errNode0 = prev;
			break;
		}
		prev = *it;
	}
	cout << "1st error node = " << errNode0->_val << endl;
		
	//find the unordered node from right to left
	prev = *vec.rbegin();
	for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
		if (prev->_val < (*rit)->_val) {
			errNode1 = prev;
			break;
		}
		prev = *rit;
	}
	cout << "2nd error node = " << errNode1->_val << endl;

//if don't need to switch
if (errNode0 == nullptr || errNode1 == nullptr) {
		cout << "this array is sorted\n";
		return;
	}
	
	//switch	
	int temp = errNode0->_val;
	errNode0->_val = errNode1->_val;
	errNode1->_val = temp;
}

void recoverBinTree(TreeNode * root) {
	//place Tree nodes into an array
	//using inorder traverse
	vector<TreeNode *> sorted;
	inorderTrav(root, sorted);

	//recovery
	recoverOrder(sorted);
}
	

//helper funct
void switchNodes(vector<TreeNode *> & vec, int p0, int p1) {
	if (vec.size() <= p0 || vec.size() <= p1) {
		cout << "out of bound\n";
		return;
	}

	int temp = vec[p0]->_val;
	vec[p0]->_val = vec[p1]->_val;
	vec[p1]->_val = temp;
}

void showVec(vector<TreeNode *> & sorted) {
	for (size_t i = 0; i < sorted.size(); ++i) {
		cout << sorted[i]->_val << " ";
	}
	cout << endl;
}

	
int main() {
	int array[] = {10, 5, 2, 31, 6};

	//build BST
	TreeNode * root = buildBST(array, 5);
	vector<TreeNode *> sorted;
	cout << "original tree\n";
	showBinTree(root);

	//place nodes into vector
	inorderTrav(root, sorted);
	//showVec(sorted);
	
	//mess them up
	switchNodes(sorted, 2, 4);
	cout << "after switch\n";
	showVec(sorted);
	showBinTree(root);

	//recover
	recoverOrder(sorted);
	cout << "after recover\n";
	showVec(sorted);
	showBinTree(root);

	return 0;
}
