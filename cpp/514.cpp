#include <iostream>
#include <vector>
#include <queue>
#include "bin_tree.h"

using namespace std;

//recursion
//void trav(TreeNode * pnode, int level, vector<vector<int> > & res) {
//	//base condition
//	if (pnode == nullptr) return;
//
//	//the first node enter the new level
//	if (level > res.size())
//		res.push_back(vector<int>());
//
//	//save current node
//	res[level - 1].push_back(pnode->_val);
//
//	//save the subtree
//	trav(pnode->_left, level + 1, res);
//	trav(pnode->_right, level + 1, res);
//}
//	
//
//vector<vector<int> > levelOrderTrav(TreeNode * pnode) {
//	vector<vector<int> > result;
//	
//	trav(pnode, 1, result);
//
//	return result;
//}

//itoration
vector<vector<int> > levelOrderTrav(TreeNode * root) {
	vector<vector<int>> res;//save res
	queue<TreeNode *> node_q;
	queue<int> level_q;
	int level = 1;
	TreeNode * pnode;
	
	//initialize
	//put root in queue
	node_q.push(root);
	level_q.push(level);

	while (!node_q.empty()) {
		//get node info
		pnode = node_q.front();
		level = level_q.front();

		//save the 1st entry at new level
		if (level > res.size())
			res.push_back(vector<int>());

		//save the node
		res[level - 1].push_back(pnode->_val);

		//push its children into queue
		if (pnode->_left != nullptr) {
			node_q.push(pnode->_left);
			level_q.push(level + 1);
		}
		if (pnode->_right != nullptr) {
			node_q.push(pnode->_right);
			level_q.push(level + 1);
		}
			
		//update queue
		node_q.pop();
		level_q.pop();
	}

	return res;
}
		
int main() {
//	int array[] = {6, 4, 10, 2, 5, 7, 11, 1, 3, 0, 0, 9, 8};
	int array[] = {1, 0, 2, 3};
	TreeNode * root = buildBinTree(array, 4);

	vector<vector<int> > res = levelOrderTrav(root);
	show2dVec(res);

	return 0;
}
		
		
	
