//Description
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//1
//\
//2
///
//3
//return[1, 3, 2].
//
//Note: Recursive solution is trivial, could you do it iteratively ?


//Solution :
//Soluion 1:
//use the recursive

//Solution 2:
//we can do it it iteratively ,use the stack to store the father node
//what we should notice is that we when pop root,the stack is empty
//at this time,there are some wrong with the it ,thus,we add a suition 
//*root!=null

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
	/*	vector<int> answer;
		if (NULL == root)
			return answer;
		if (NULL != root->left) {
			vector<int> left_v = inorderTraversal(root->left);
			answer.insert(answer.end(), left_v.begin(),left_v.end());
		}

		answer.push_back(root->val);

		if (NULL != root->right) {
			vector<int> left_v = inorderTraversal(root->right);
			answer.insert(answer.end(), left_v.begin(), left_v.end());
		}		

		return answer;*/

		vector<int> answer;
		stack<TreeNode*> my_stack;
		if (NULL == root)
			return answer;

		while (NULL != root || !my_stack.empty()) {
			while (NULL != root) {
				my_stack.push(root);
				root = root->left;
			}

			root = my_stack.top();
			answer.push_back(root->val);
			my_stack.pop();

			root = root->right;
		}

		return answer;
	}
};