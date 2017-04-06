//Description
//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that 
//adding up all the values along the path equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//5
/// \
//4   8
/// / \
//11  13  4
/// \      \
//7    2      1
//return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.

//Solution
//we just do it recursively
//we should notice that the current must be a leaf node when sum=0
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;

		int remain = sum - root->val;

		if (!remain&&!root->left&&!root->right)
			return true;

		return this->hasPathSum(root->left, remain) || this->hasPathSum(root->right, remain);
	}

};