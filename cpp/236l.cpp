//find least common ancestor for a binary tree
#include <iostream>
#include "bin_tree.h"

using namespace std;

//a straight forward way
//save the path of two nodes
//and compare each step to find the lca
int getPath(TreeNode * root, int n, vector<TreeNode *> & p) {
	if (root == nullptr) return 0; //not found

	if (root->_val == n) {
		p.insert(p.begin(), root);
		return n;
	}

	int l_val = getPath(root->_left, n, p);
	int r_val = getPath(root->_right, n, p);
	
	if (l_val + r_val != 0)//if the target node in its subtree
		p.insert(p.begin(), root);

	return n;
}

	
TreeNode * getLCA(const vector<TreeNode *> & p0, const vector<TreeNode *> & p1) {
	if (p0.empty() || p1.empty()) {
		cout << "empty vector\n";
		return nullptr;
	}

	TreeNode * lca = nullptr;

	auto it0 = p0.begin();
	auto it1 = p1.begin();
	for (; it0 != p0.end() && it1 != p1.end(); ++it0, ++it1) {
		if (*it0 == *it1)
			lca = *it0;
		else
			break;
	}

	return lca;
}


TreeNode * LCA_bin_tree(TreeNode * root, int n0, int n1) {
	vector<TreeNode *> p0, p1;
	getPath(root, n0, p0);
	getPath(root, n1, p1);

	////print two paths
	//for (size_t i = 0; i < p0.size(); ++i) 
		//cout << p0[i]->_val << " ";
	//cout << endl;

	//for (size_t i = 0; i < p1.size(); ++i) 
		//cout << p1[i]->_val << " ";
	//cout << endl;

	TreeNode * lca = getLCA(p0, p1);
	return lca;
}

////this is the optimal solution
//TreeNode * LCA_bin_tree(TreeNode * root, int n0, int n1) {
	////if root == nullptr, reach the end of the tree
	////if root == n0/n1, find the target nodes
	//if (root == nullptr || 
		//root->_val == n0 ||
		//root->_val == n1) 
		//return root;

	//TreeNode * left  = LCA_bin_tree(root->_left, n0, n1);
	//TreeNode * right = LCA_bin_tree(root->_right, n0, n1);

	//if (left != nullptr && right != nullptr) {
		////this is the lca for sure, return it
		//cout << "lca = " << root->_val << endl;
		//return root;
	//}
	////otherwise, return the ptr which is not nullptr
	//return (left != nullptr) ? left : right;
//}


int main() {
	int array[] = {10, 5, 2, 0, 0, 31, 6};

	//build BST
	TreeNode * root = buildBinTree(array, 7);
	cout << "original tree\n";
	showBinTree(root);
        
    int n0 = 31, n1 = 6;
    TreeNode * lca = LCA_bin_tree(root, n0, n1);

	if (lca != nullptr) {
		cout << "The least common ancestor of ";
		cout << n0 << " and " << n1;
		cout << " is " << lca->_val << endl;
	}

	return 0;
}
