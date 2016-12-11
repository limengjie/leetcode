//this is the 297th question in leetcode
#include <iostream>
#include <string>
#include "bin_tree.h" //TreeNode
#include "serialization.h"

using namespace std;

TreeNode * deserialization(const string str) {
        if (str.empty())
                return nullptr;

        TreeNode ** parent = new TreeNode *[str.size()];
        int pi = 0; //parent's index

        //cout << "0\n";

        //build binary tree from a string
        //initialization
        TreeNode * root = new TreeNode(str[0] - '0');
        parent[0] = root;
        int twoChildren = 0; //check if save the node as right child
        for (size_t i = 1; i < str.size(); ++i) {
                if (str[i] != '\0') {
                        //get its parent
                        while (pi < str.size()) {
                                if (parent[pi] != nullptr) 
                                        break;
                                ++pi;
                        }
                        //construct node
                        TreeNode * pnode = new TreeNode(str[i] - '0');
                        //link to its parent
                        if (twoChildren == 0) 
                                parent[pi]->_left = pnode;
                        else if (twoChildren == 1)
                                parent[pi]->_right = pnode;

                        //update
                        ++twoChildren;
                        if (twoChildren > 1) {
                                twoChildren = 0;
                                ++pi;
                        }
                        parent[i] = pnode;
                }
        }
        return root;
}

int main() {
        string str = {'1', '2', '3', '\0', '\0', '4'};

        ////print string
        //for (size_t i = 0; i < str.size(); ++i) {
                //cout << str[i] << endl;
        //}
        ////cout << str << endl;
        //
        TreeNode * root = deserialization(str);
        //cout << "2\n";
        showBinTree(root);
        //cout << "3\n";

        return 0;
}
