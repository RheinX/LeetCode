//Description
//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a binary tree 
//in which the depth of the two subtrees of every node never differ by more than 1.

//Solution :
//Solution 1:
//use two recursive funtion,one judge if the current meet the requirement
//another get the depth of current
//the time complexity of this is O(n^2)

//Solution 2:
//the solution1 is from top to bottom to judge
//so we can from bottm to top to judge,it needs O(n)
//we can also generate a function to get its depth
//but do a litter improvement:when it isn't a balanced BSP,it return -1
//so when a childnode is not a balanced tree,we just need to return -1


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
	bool isBalanced(TreeNode* root) {
		//Solution 1
		/*if (!root)
			return true;

		if (abs(this->get_length(root->left) - this->get_length(root->right)) > 1)
			return false;

		return this->isBalanced(root->left) && this->isBalanced(root->right);*/

		//Solution 2
		return this->judge_child(root) != -1;
	}
private:
	int get_length(TreeNode* root) {
		if (!root)
			return 0;

		return 1 + max(this->get_length(root->left), this->get_length(root->right));
	}

	int judge_child(TreeNode* node) {
		//if the node is balanced,return its depth,else return -1
		if (!node)
			return 0;

		int left_depth = judge_child(node->left);
		if (-1 == left_depth)
			return -1;
		int right_depth = judge_child(node->right);
		if (-1 == right_depth)
			return -1;

		if (labs(left_depth - right_depth) > 1)
			return -1;

		return 1 + max(left_depth, right_depth);
	}
};

