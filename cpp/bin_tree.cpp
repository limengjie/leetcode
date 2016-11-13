#include <iostream>
#include <queue> // showBinTree
#include "bin_tree.h"

using namespace std;

//assume the value of node are great than 0

//construct a binary tree from a given array
TreeNode * buildBinTree(int array[], int len) {
	if (len == 0 || array == nullptr) 
		return nullptr;

	//create an array created[] to keep track of 
	//created nodes(they will become parents later), 
	//initialize all entries as nullptr
	TreeNode ** created = new TreeNode * [len];
	for (int i = 0; i < len; ++i) 
		created[i] = nullptr;

	int twoChildren = 0; //check if a node has two children
	int parent = 0;// the index of parent node
	if (array == nullptr) return nullptr;
	TreeNode * root = new TreeNode(array[0]);
	created[0] = root;
	for (int i = 1; i < len; ++i) {
		int v = array[i];
		//if there is a valid node
		if (v > 0) {
			//create a new node
			TreeNode * pnode = new TreeNode(v);
			//get its parent node
			while (created[parent] == nullptr) {
				if (parent > len)
					return nullptr;
				++parent;
			}

			//link child and parent
			if (twoChildren == 0) {
				created[parent]->_left = pnode;
				cout << "left: " << v << endl;
			} else {
				created[parent]->_right = pnode;
				cout << "right: " << v << endl;
			}
			//save the node for later use
			//it may become others parent
			created[i] = pnode;
		}
		//update index
		++twoChildren;
		if (twoChildren == 2) {
			twoChildren = 0;
			++parent;
		}
	}
	free(created);

	return root;
}
		
void showBinTree(TreeNode * root) {
	queue<TreeNode *> nodes; 
	queue<int> level_q;
	int cur_lvl = 0;
	TreeNode * pT;
	nodes.push(root);
	level_q.push(1);
	
	while (!nodes.empty()) {
		pT = nodes.front();
		if (cur_lvl < level_q.front()) {
			++cur_lvl;
			cout << endl;
		}
		cout << pT->_val << " ";
		if (pT->_left != nullptr) {
			nodes.push(pT->_left);
			level_q.push(cur_lvl + 1);
		}
		if (pT->_right != nullptr) {
			nodes.push(pT->_right);
			level_q.push(cur_lvl + 1);
		}
		//update node
		nodes.pop();
		level_q.pop();
	}
	cout << endl;
}
	
//helper funct
void show2dVec(vector<vector<int> > & vec) {
	cout << "[ \n";
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << "[";
		for (size_t j = 0; j < vec[i].size(); ++j) {
			cout << vec[i][j];
			if (j != vec[i].size() - 1) {
				cout << ", ";
			}
		}
		cout << "]\n";
	}
	cout << "]\n";
}

void sinkBST(TreeNode * root, int n) {
	if (root == nullptr) {
		cout << "invalid tree\n";
		return ;
	}
	
	TreeNode * newNode = new TreeNode(n);
	TreeNode * pnode = root;
	while (pnode != nullptr) {
		if (pnode->_val == n)
			return;
		else if (n < pnode->_val) {
			//if the node doesn't have children
			//insert the new node
			if (pnode->_left == nullptr) {
				pnode->_left = newNode;	
				return;
			}
			pnode = pnode->_left;
		}
		else if (n > pnode->_val) {
			//if the node doesn't have children
			//insert the new node
			if (pnode->_right == nullptr) {
				pnode->_right = newNode;	
				return;
			}
			pnode = pnode->_right;
		}
	}
} 

//construct a binary tree from a given array
TreeNode * buildBST(int array[], int len) {
	if (len == 0 || array == nullptr) 
		return nullptr;
	
	//initialize
	TreeNode * root = new TreeNode(array[0]);
	for (int i = 1; i < len; ++i) {
		sinkBST(root, array[i]);
	}
	
	return root;
}


//int main() {
//	int A[] = {10, 5, 2, 31, 6};
//
//	TreeNode * tree = buildBST(A, 5);
//	showBinTree(tree);
//
//	return 0;
//}
