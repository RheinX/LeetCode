//Description
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

//Solution 1:
//the similiar solution like 102
//we set a int *depth and put every childnode of every level,*depth++
//unitl the vector is empty

//Solution 2:
//just do it recursively:if *root=null,return 0,else retun 1+depth(*root->child);
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
	int maxDepth(TreeNode* root) {
		//Solution 1
		/*if (!root)
			return 0;

		vector<TreeNode*> answer;
		int depth = 0;
		answer.push_back(root);
		while (!answer.empty()){
			vector<TreeNode*> another;
			for (auto v:answer){
				if (v->left) another.push_back(v->left);
				if (v->right) another.push_back(v->right);
			}
			answer = another;
			depth++;
		}

		return depth;*/

		//Solution 2
		return root == NULL ? 0 : 1 + max(this->maxDepth(root->left), this->maxDepth(root->right));
	}
};