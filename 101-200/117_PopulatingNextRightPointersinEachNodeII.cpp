//Description
//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree ? Would your previous solution still work ?
//
//Note :
//
//	You may only use constant extra space.
//	For example,
//	Given the following binary tree,
//	1
//	/ \
//	2    3
//	/ \    \
//	4   5    7
//	After calling your function, the tree should look like :
//1->NULL
/// \
//2 -> 3->NULL
/// \    \
//4-> 5 -> 7->NULL

//Solution:
//Solution 1:
//we define another function that link the child nodes of current level
//first we let the *root's children link,and let the next of latter child node point to functtion(*root->next)
//sure,we should judge the root is empty and the children is empty
//then ,we can make the children link
//if there is no chilren link,it return NULL
//thus,in the main function,we also use recursivision and add a condition where when previous fuction return NULL,we return
//what we should notice that when the conquence of previous function is not null,the node has been linked
//so,the parameter of current function should be filled with the conquence of previous function
#include <vector>
using namespace std;

 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

 class Solution {
 public:
	 void connect(TreeLinkNode *root) {
		 if (!root)
			 return;

		 TreeLinkNode* p = root;

		 TreeLinkNode* next = this->get_next_head(p);
		 if (!next)
			 return;
		 this->connect(next);

	 }
 private:
	 TreeLinkNode* get_next_head(TreeLinkNode* root) {
		 if (!root)
			 return NULL;

		 if (root->left&&root->right) {
			 root->left->next = root->right;
			 root->right->next = this->get_next_head(root->next);
			 return root->left;
		 }
		 else if (root->left && !root->right) {
			 root->left->next = this->get_next_head(root->next);
			 return root->left;
		 }
		 else if (!root->left&&root->right) {
			 root->right->next = this->get_next_head(root->next);
			 return root->right;
		 }
		 else
			 return this->get_next_head(root->next);

	 }
 };