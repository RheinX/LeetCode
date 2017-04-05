//Descrription
//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

//Solution
//as the previous problem,but the last element of postorder is the head
//I use the index of array instead of changing vector
//the offset_* mean the locaiton of last element
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty()||postorder.empty()||inorder.size()!=postorder.size())
			return NULL;
		map<int, int> my_map;
		for (int i = 0; i < inorder.size();i++) {
			my_map.insert(pair<int, int>(inorder[i], i));
		}
		return this->buildTree_index(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1,my_map);
	}
private:
	TreeNode* buildTree_index(vector<int>& inorder, vector<int>& postorder, int start_inorder, int offset_inorder,
		int start_postorder, int offset_postorder,const map<int,int> &my_map) {
		if (offset_inorder < start_inorder || offset_postorder < start_postorder)
			return NULL;

		TreeNode* head = new TreeNode(postorder[offset_postorder]);

		int position = my_map.find(postorder[offset_postorder])->second;

		head->left = this->buildTree_index(inorder, postorder, start_inorder, position - 1, start_postorder, 
			start_postorder + position - 1 - start_inorder,my_map);
		head->right = this->buildTree_index(inorder, postorder, position + 1, offset_inorder, 
			start_postorder + position - start_inorder, offset_postorder - 1,my_map);
		
		return head;
	}
};