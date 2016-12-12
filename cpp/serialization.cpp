//this is the 297th question in leetcode
#include <iostream>
#include <string>
#include <queue>
#include "bin_tree.h" //TreeNode
#include "serialization.h"

using namespace std;

//TreeNode * deserialization(const string str) {
        //if (str.empty())
                //return nullptr;

        //TreeNode ** parent = new TreeNode *[str.size()];
        //int pi = 0; //parent's index

        ////cout << "0\n";

        ////build binary tree from a string
        ////initialization
        //TreeNode * root = new TreeNode(str[0] - '0');
        //parent[0] = root;
        //int twoChildren = 0; //check if save the node as right child
        //for (size_t i = 1; i < str.size(); ++i) {
                //if (str[i] != '\0') {
                        ////get its parent
                        //while (pi < str.size()) {
                                //if (parent[pi] != nullptr) 
                                        //break;
                                //++pi;
                        //}
                        ////construct node
                        //TreeNode * pnode = new TreeNode(str[i] - '0');
                        ////link to its parent
                        //if (twoChildren == 0) 
                                //parent[pi]->_left = pnode;
                        //else if (twoChildren == 1)
                                //parent[pi]->_right = pnode;

                        ////update
                        //++twoChildren;
                        //if (twoChildren > 1) {
                                //twoChildren = 0;
                                //++pi;
                        //}
                        //parent[i] = pnode;
                //}
        //}
        //return root;
//}


//recursive version(wrong)
//TreeNode * deserialization(string & str) {
        //if (str.empty()) 
                //return nullptr;

        //if (str[0] == '\0') {
                //str.erase(str.begin());
                //cout << str << endl;
                //return nullptr;
        //}

        //TreeNode * root = new TreeNode(str[0] - '0');
        //str.erase(str.begin());
        //cout << str << endl;

        //root->_left = deserialization(str);
        //root->_right = deserialization(str);

        //return root;
//}


//itorative version
TreeNode * deserialization(const string str) {
        if (str.empty()) return nullptr;

       queue<TreeNode *> parents; 
       queue<int> twoChildren;

       TreeNode * root = new TreeNode(str[0] - '0');
       parents.push(root);
       twoChildren.push(2);
       for (size_t i = 1; i < str.size(); ++i) {
               //get parent
              TreeNode * parent = parents.front(); 
              //construct node
              TreeNode * pnode;
              if (str[i] == '\0') 
                      pnode = nullptr;
              else
                      pnode = new TreeNode(str[i] - '0');
              //link node to parent
              if (twoChildren.front() == 2)
                      parent->_left = pnode;
              else if (twoChildren.front() == 1)
                      parent->_right = pnode;
              //update
              parents.push(pnode);
              twoChildren.push(2);
              --twoChildren.front();
              if (twoChildren.front() == 0) {
                      parents.pop();
                      twoChildren.pop();
              }
       }
       return root;
}





void serialize(const TreeNode * root, string & str) {
        if (root == nullptr) {
                str.push_back('\0');

                return;
        }

        //traverse the binary tree in preorder
        str.push_back(root->_val + '0');

        serialize(root->_left, str);
        serialize(root->_right, str);
}




string serialization(const TreeNode * root) {
        string str;
        serialize(root, str);

        return str;
}


int main() {
        string str = {'1', '2', '3', '\0', '\0', '4'};

        //
        TreeNode * root = deserialization(str);
        //cout << "2\n";
        //showBinTree(root);
        //cout << "3\n";
        
        string res = serialization(root);
        ////print string
        //for (size_t i = 0; i < res.size(); ++i) {
                //cout << res[i] << endl;
        //}
        cout << res << endl;

        return 0;
}
