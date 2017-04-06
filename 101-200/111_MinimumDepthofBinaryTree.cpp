//Description
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

//Solution :
//Solution 1:
//we can push the all nodes of a level into a vector
//if a node in vector has no children,it means the depth of it is answer we need 

//Solution 2:
//we can do it recursively,we get the minimun depth of left and right child
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		//Solution 1
		/*vector<TreeNode*> level_node;
		int i = 0;
		if (!root)
			return i;

		level_node.push_back(root);
		i++;

		while (true){
			vector<TreeNode*> next_level;
			for (auto v:level_node){
				if (!v->left&&!v->right) return i;
				if (v->left) next_level.push_back(v->left);
				if (v->right) next_level.push_back(v->right);
			}
			level_node = next_level;
			i++;
		}

		return i;*/

		//Solution 2:
		if (!root)
			return 0;
		int depth_left = this->minDepth(root->left);
		int depth_right = this->minDepth(root->right);

		return (depth_left == 0 || depth_right == 0)
			? depth_right + depth_left + 1 : min(depth_left, depth_right) + 1;
	}
};
