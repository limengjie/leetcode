//find least common ancestor of a binary tree
#include <iostream>
#include "bin_tree.h"

using namespace std;

//In bst, if a node is ancestor of a bunch of nodes,
//it must be greater than all of the nodes at the LHS subtree,
//and less than all of the nodes at the RHS subtree.


//if we found one of the target nodes, this node is the LCA
//if we found a node which is greater than one node, 
//and less than another node, it is the LCA
TreeNode * LCA_bst(TreeNode * root, int n0, int n1) {
        //if root == nullptr, cannot find target
        if (root == nullptr || root->_val == n0 || root->_val == n1)
                return root;

        if ((root->_val - n0) * (root->_val - n1) < 0) {
                //if root's value is between target values, 
                //it is LCA
                return root;
        }
        else if (root->_val > n0 && root->_val > n1) {
                //if root's value is greater than target values,
                //the LCA must at its left hand side
                LCA_bst(root->_left, n0, n1);
        }
        else if (root->_val < n0 && root->_val < n1) {
                //if root's value is less than target values,
                //the LCA must at its right hand side
                LCA_bst(root->_right, n0, n1);
        }
}


int main() {
	int array[] = {10, 5, 2, 31, 6};

	//build BST
	TreeNode * root = buildBST(array, 5);
	cout << "original tree\n";
	showBinTree(root);
        
    int n0 = 2, n1 = 6;
    TreeNode * lca = LCA_bst(root, n0, n1);

    cout << "The least common ancestor of ";
    cout << n0 << " and " << n1;
    cout << " is " << lca->_val << endl;

    return 0;
}


