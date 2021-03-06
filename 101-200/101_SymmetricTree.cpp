//Description
//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following[1, 2, 2, null, 3, null, 3] is not:
//1
/// \
//2   2
//\   \
//3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively

//Solution:
//Solution 1:
//solve it recursively,notice that we should make sure that both of pointers are not null


#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;

		return this->mirror_check(root->left, root->right);
	}
private:
	bool mirror_check(TreeNode* left, TreeNode* right) {
		if (left&&right)
			return left->val == right->val&&this->mirror_check(left->left, right->right)
			&& this->mirror_check(left->right, right->left);

		return !left&&!right;
	}
};