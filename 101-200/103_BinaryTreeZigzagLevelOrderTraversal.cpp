//Description
//Given a binary tree, return the zigzag level order traversal of its nodes' values. 
//(ie, from left to right, then right to left for the next level and alternate between).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its zigzag level order traversal as :
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]

//Solution
//we can do a litter change on the base of 102
//add a variable of bool,*flag,if(flag) we reorder the *now,and push it into answer

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> answer;
		if (!root)
			return answer;
		vector<TreeNode*> previou;
		previou.push_back(root);
		this->get_answer(answer, previou,false);

		return answer;
	}
private:
	void get_answer(vector<vector<int>> &answer, const vector<TreeNode*> previous,bool flag) {
		if (previous.empty())
			return;

		vector<int> now;
		vector<TreeNode*> next;
		for (auto v : previous) {
			now.push_back(v->val);
			if (v->left) next.push_back(v->left);
			if (v->right) next.push_back(v->right);
		}
		if (flag)
			now = vector<int>(now.rbegin(), now.rend());
		answer.push_back(now);
		this->get_answer(answer, next,!flag);
	}
};