#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <vector> //show2dVec

using namespace std;

struct TreeNode {
	int _val;
	TreeNode * _left;
	TreeNode * _right;
	TreeNode(int x): _val(x), _left(nullptr), _right(nullptr) {}
};

typedef struct TreeNode TreeNode;

TreeNode * buildBinTree(int array[], int len);
void showBinTree(TreeNode * root);
void show2dVec(vector<vector<int> > & vec);

#endif
