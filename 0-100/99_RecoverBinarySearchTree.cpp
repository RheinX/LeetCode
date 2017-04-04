//Description
//Two elements of a binary search tree(BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward.Could you devise a constant space solution ?

//Solution:
//Solution 1:
//we can get the vector of inorder traverse,sort it
//fill the tree again

//Solution 2:
//we can loop the tree in in-order traverse
//if the val of pervious's node >= current's,it means this node need be change
//tips:sometimes ,it only one previous,so we can do this as follows

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
	void recoverTree(TreeNode* root) {
		//if (!root)
		//	return;

		//vector<int> answer = this->inorderTraversal(root);
		//sort(answer.rbegin(), answer.rend());
		////lambda expression
		////sort(answer.begin(), answer.end(), [](const int &i, const int &j) {return i > j; });
		//this->fillTree(root, answer);
		
		find(root);
		int a = first->val;
		first->val = second->val;
		second->val = a;
	}
private:
	TreeNode* first = NULL;
	TreeNode* second = NULL;
	TreeNode* pre = new TreeNode(INT_MIN);

	void find(TreeNode* root) {
		if (!root)
			return;

		find(root->left);

		if (!first&&pre->val >= root->val)
			first = pre;

		if (first&&pre->val >= root->val)
			second = root;

		pre = root;

		find(root->right);
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

	void fillTree(TreeNode* root, vector<int> &answer) {
		if (root->left) {
			fillTree(root->left, answer);
		}

		root->val = answer.back();
		answer.pop_back();
		if (answer.empty())
			return;

		if (root->right)
			fillTree(root->right, answer);

	}
};