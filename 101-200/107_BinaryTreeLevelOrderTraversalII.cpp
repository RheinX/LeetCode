//Description
//Given a binary tree, return the bottom - up level order traversal of its nodes' values. 
//(ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]

//Solution
//just like the 102,return the resort of answer

#include <iostream>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> answer;
		if (!root)
			return answer;
		vector<TreeNode*> previou;
		previou.push_back(root);
		this->get_answer(answer, previou);

		return vector<vector<int>>(answer.rbegin(), answer.rend());
	}
private:
	void get_answer(vector<vector<int>> &answer, const vector<TreeNode*> previous) {
		if (previous.empty())
			return;

		vector<int> now;
		vector<TreeNode*> next;
		for (auto v : previous) {
			now.push_back(v->val);
			if (v->left) next.push_back(v->left);
			if (v->right) next.push_back(v->right);
		}

		answer.push_back(now);
		this->get_answer(answer, next);
	}
};