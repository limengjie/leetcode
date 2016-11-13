#include <iostream>
#include <queue> // showBinTree
#include "bin_tree.h"

using namespace std;

//assume the value of node are great than 0

//construct a binary tree from a given array
TreeNode * buildBinTree(int array[], int len) {
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
	TreeNode * pT;
	nodes.push(root);
	
	while (!nodes.empty()) {
		pT = nodes.front();
		cout << pT->_val << " ";
		if (pT->_left != nullptr)
			nodes.push(pT->_left);
		if (pT->_right != nullptr)
			nodes.push(pT->_right);
		nodes.pop();
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


//int main() {
//	int A[] = {1, 0, 2, 3};
//
//	TreeNode * tree = buildBinTree(A, 4);
//	showBinTree(tree);
//
//	return 0;
//}
