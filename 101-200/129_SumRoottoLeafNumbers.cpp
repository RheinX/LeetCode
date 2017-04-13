//Description
//Given a binary tree containing digits from 0 - 9 only, each root - to - leaf path could represent a number.
//
//An example is the root - to - leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root - to - leaf numbers.
//
//For example,
//
//1
/// \
//2   3
//The root - to - leaf path 1->2 represents the number 12.
//The root - to - leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

//Solution:
//Solution 1:
//do a BFS,we should notice that when a node is leaf-node,we should add its value to answer
//and return,if judge whether the node is null ,his father node will be added twice
//sure,we should judge if the root is null

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
	int sumNumbers(TreeNode* root) {
		int answer = 0;
		this->BFS(answer, root, 0);
		return answer;
	}

public:
	void BFS(int &answer, TreeNode* root, int father_value) {
		father_value = father_value * 10 + root->val;
		if (!root->left&&!root->right) {
			answer += father_value;
			return;
		}

		if(root->left)	this->BFS(answer, root->left, father_value);
		if(root->right)	this->BFS(answer, root->right, father_value);
	}
};