//Description
//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,

//Solution :
//just as the pervious problem,we just change it by the BFS
#include<iostream>
#include<vector>
using namespace std;


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> answer;
		vector<int> now;

		this->get_answer(answer, root, sum, now);

		return answer;
	}
private:
	void get_answer(vector<vector<int>> &answer, TreeNode* root, int sum, vector<int> now) {
		if (!root)
			return;

		now.push_back(root->val);
		if (!(sum - root->val) && !root->left && !root->right) {
			answer.push_back(now); return;
		}

		this->get_answer(answer, root->right, sum - root->val, now);
		this->get_answer(answer, root->left, sum - root->val, now);
	}
};