//Description
//Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value

//Solution:
//do a rescuation,judge its left node ,itself and right node
//we should notice that ,it may be give us one or two null pointer
//we can simplify the code as this
//if (p == null && q == null) return true;
//if (p == null || q == null) return false;
//if (p.val == q.val)
//return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
//return false;
#include <iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (NULL == p&&NULL == q) return true;
		if (NULL == p&&NULL != q || (NULL != p&&NULL == q)) return false;
		bool answer = true;
		if (NULL != p->left&&NULL != q->left)
			answer = answer&isSameTree(p->left, q->left);
		else if (NULL == p->left&&NULL == q->left)
			answer = answer;  //unusefule operation
		else
			return false;

		/*if (NULL == p&&NULL == q) return true;
		else if (NULL!=p&&NULL!=q&&p->val == q->val){}
		else return false;*/
		if (p->val != q->val)
			return false;

		if (NULL != p->right&&NULL != q->right)
			answer = answer&isSameTree(p->right, q->right);
		else if (NULL == p->right&&NULL == q->right)
			answer = answer;  //unusefule operation
		else
			return false;
		

		return answer;
	}
};