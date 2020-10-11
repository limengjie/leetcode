#ifndef __SERIALIZATION__
#define __SERIALIZATION__

#include <string>
#include "bin_tree.h" //TreeNode

//TreeNode * deserialization(string & str);
TreeNode * deserialization(const string str);

void serialize(const TreeNode * root, string & str);

string serialization(const TreeNode * root);
	


#endif
