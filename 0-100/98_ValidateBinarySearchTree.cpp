//Description
//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//Example 1 :
//	2
//	/ \
//	1   3
//	Binary tree[2, 1, 3], return true.
//	Example 2:
//1
/// \
//2   3
//Binary tree[1, 2, 3], return false.

//Solution:
//Solution 1:
//we can set a extra function with two para:min and  max
//we should notice that the test case may be occure INT_MIN and INT_MAX
//thus ,the min and max type should be long at leat
//and the we should not fill the para with iNT_MIN-1
//(this bacause the int_min and 1 is int,so the total of them is also int)


//Solution 2:
//if we get the in-order traversal of BST,the vector is a ascending array
//we can also write the code as the following
//class Solution {
//public:
//	bool isValidBST(TreeNode* root) {
//		TreeNode* prev = NULL;
//		return validate(root, prev);
//	}
//	bool validate(TreeNode* node, TreeNode* &prev) {
//		if (node == NULL) return true;
//		if (!validate(node->left, prev)) return false;
//		if (prev != NULL && prev->val >= node->val) return false;
//		prev = node;
//		return validate(node->right, prev);
//	}
//};


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
	 bool isValidBST(TreeNode* root) {
		 /* if (NULL == root)
			  return true;
		  return this->childRoorJudge(root, -2147483649, 2147483649);*/

		 if (NULL == root)
			 return true;
		 vector<int> answer = this->inorderTraversal(root);

		 for (int i = 1; i < answer.size(); i++)
			 if (answer[i] <= answer[i - 1])
				 return false;

		 return true;
	 }

 private:
	 bool childRoorJudge(TreeNode* root, long minValue, long maxValue) {
		 if (NULL == root->left&&NULL == root->right)
			 return true;
		 bool answer = true;
		 if (NULL != root->left) {
			 if (root->left->val<root->val&&root->left->val>minValue) {
				 answer &= childRoorJudge(root->left, minValue, root->val);
			 }
			 else return false;
		 }

		 if (NULL != root->right) {
			 if (root->right->val > root->val&&root->right->val < maxValue) {
				 answer &= childRoorJudge(root->right, root->val, maxValue);
			 }
			 else return false;
		 }

		 return answer;

	 }
	 vector<int> inorderTraversal(TreeNode* root) {
		 vector<int> answer;
		 if (NULL == root)
			 return answer;
		 if (NULL != root->left) {
			 vector<int> left_v = inorderTraversal(root->left);
			 answer.insert(answer.end(), left_v.begin(), left_v.end());
		 }
		 answer.push_back(root->val);
		 if (NULL != root->right) {
			 vector<int> left_v = inorderTraversal(root->right);
			 answer.insert(answer.end(), left_v.begin(), left_v.end());
		 }
		 return answer;
	 }
 };