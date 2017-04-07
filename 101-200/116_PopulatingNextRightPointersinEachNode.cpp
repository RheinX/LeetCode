//Description
//Given a binary tree
//
//struct TreeLinkNode {
//	TreeLinkNode *left;
//	TreeLinkNode *right;
//	TreeLinkNode *next;
//}
//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//For example,
//Given the following perfect binary tree,
//1
/// \
//2    3
/// \ / \
//4  5  6  7
//After calling your function, the tree should look like :
//1->NULL
/// \
//2 -> 3->NULL
/// \ / \
//4->5->6->7->NULL

//Solution
//we link next level every time
//set two extra pointer,*p point to the current node,*next point to *p->next
//and then we can link the children of *p and *next
//we just only make the *p and *node move back unitl the *node is null
#include <iostream>
using namespace std;


 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root||!root->left)
			return;
		
		TreeLinkNode* next = root->next;
		TreeLinkNode* p = root;

		if (!next)
			root->left->next = root->right;

		while (next){
			p->left->next = p->right;
			p->right->next = next->left;
			next->left->next = next->right;

			p = next;
			next = next->next;
		}
		p->right->next = NULL;

		this->connect(root->left);
	}
};