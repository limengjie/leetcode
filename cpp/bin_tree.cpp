#include <iostream>
#include <queue>      // showBinTree
#include <stack>      //showBST
#include <algorithm>  //sort
#include "bin_tree.h"

using namespace std;

//insert node in level order
TreeNode* insertLevelOrder(int arr[], int i, int n)
{
   TreeNode* root = nullptr;
   if (i < n)
   {
      root = new TreeNode(arr[i]);
      root->_left  = insertLevelOrder(arr, 2*i + 1, n);
      root->_right = insertLevelOrder(arr, 2*i + 2, n);
   }
   return root;
}
		
TreeNode* buildBinTree(int array[], int len) {
   return insertLevelOrder(array, 0, len);
}
void showBinTree(TreeNode* root) {
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

void sinkBST(TreeNode* root, int n) {
	if (root == nullptr) {
		cout << "invalid tree\n";
		return ;
	}
	
	TreeNode* newNode = new TreeNode(n);
	TreeNode* pnode = root;
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

TreeNode* sortedArrayToBST(int arr[], int start, int end)
{
        //base case
        if (start > end) return nullptr;
        
        //get middle elt and make it root
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        //recursively construct left and right subtree
        root->_left  = sortedArrayToBST(arr, start, mid - 1);
        root->_right = sortedArrayToBST(arr, mid + 1, end);

        return root;
}

//construct a binary search tree from a given array
TreeNode* buildBST(int arr[], int len) {
	//sort
        sort(arr, arr + len);
        //build
	return sortedArrayToBST(arr, 0, len - 1);
}

//inorder traverse BST
void showBST(TreeNode* root)
{
   stack<TreeNode*> stk;
   TreeNode* p = root;
   while (!stk.empty() || p != nullptr)
   {
     if (p != nullptr) 
     {
        stk.push(p);
        p = p->_left;
     }
     else 
     {
        p = stk.top();
        stk.pop();
        cout << p->_val << " ";
        p = p->_right;
     }
   }
   cout << endl;
}

TreeNode* insertBST(TreeNode* root, int value) 
{
   if (!root)
      return new TreeNode(value);

   if (value < root->_val)
      root->_left  = insertBST(root->_left, value);
   else if (value > root->_val)
      root->_right = insertBST(root->_right, value);

   return root;
}

int main() {
	int A[] = {10, 5, 2, 31, 6, -1, 8};
	//int A[] = {1, 2, 3, 4, 5};
        int n = sizeof(A) / sizeof(A[0]); 

	TreeNode* tree = buildBST(A, n);
        tree = insertBST(tree, 7);
	//showBinTree(tree);
        showBST(tree);

	return 0;
}
