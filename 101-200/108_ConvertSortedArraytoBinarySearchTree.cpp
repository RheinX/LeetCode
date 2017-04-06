//Description
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

//Solution :
//Solution 1:
// as the definition of AVL tree,we definite f(n) means that the number of nodes
//so we can get that |f(left)-f(right)|<=2
//offset is 2 is the worst suition,in our problem,it will not happen
//consequently,we just divide it into two suition:the number if odd
//we just need to find the root by the number of vector,and then
//we can do this recursively,what we should notice is that when the left value=index of root
//we should set the root->left=null,otherwise,it will trap into die loop

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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return this->get_answer(nums, 0, nums.size() - 1);
	}
private:
	TreeNode* get_answer(vector<int>& nums, int first, int end) {
		if (first > end)
			return NULL;

		if (first == end) {
			TreeNode* one = new TreeNode(nums[first]);
			one->left = one->right = NULL;
			return one;
		}

		int root_position = (first + end) / 2;
		TreeNode* root = new TreeNode(nums[root_position]);
		if (root_position == first) root->left = NULL;
		else root->left = this->get_answer(nums, first, root_position - 1);
		root->right = this->get_answer(nums, root_position + 1, end);
	}
};