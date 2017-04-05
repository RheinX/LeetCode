//Description
//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

//Solution
//the first element of preorder is the head node
//the nodes behind head node in inorder is leftchild of head,the behind is rightchild
//do it recursively and if perorder is empty ,just return null

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;

		TreeNode *head = new TreeNode(preorder.front());

		vector<int> left;
		vector<int> right;
		vector<int>::iterator it = inorder.begin();
		while (it!=inorder.end()&&*it!=preorder.front()){
			left.push_back(*it);
			it++;
		}
		it++;
	
		while (it<inorder.end()){
			right.push_back(*it);
			it++;
		}
		preorder.erase(preorder.begin());
		vector<int> pre_left(preorder.begin(), preorder.begin() + left.size());
		vector<int> pre_right(preorder.end() - right.size(), preorder.end());

		head->left = this->buildTree(pre_left, left);
		head->right = this->buildTree(pre_right, right);

		return head;
	}
};