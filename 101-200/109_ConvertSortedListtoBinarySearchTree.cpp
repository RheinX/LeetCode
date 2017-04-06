//Description
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

//Solution:
//similiar to the previous problem,in this time,we pass two parameters
//the head node *head and the length of current list
//we just need to get the center node throught the length of current list
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int i = 0;
		ListNode* p = head;
		while (head){
			i++;
			head = head->next;
		}

		//return this->build_Tree(p, i);

		this->node = p;
		return this->build_Tree(0, i - 1);
	}
private:
	ListNode* node;
	TreeNode* build_Tree(ListNode* head, int length) {
		if (length <= 0 )
			return NULL;

		int center = length / 2;
		ListNode* p = head;
		int i = 0;
		while (NULL!=p&&i<center){
			p = p->next;
			i++;
		}

		if (!p)
			return NULL;

		TreeNode* root = new TreeNode(p->val);
		root->left = this->build_Tree(head, i);
		root->right = this->build_Tree(p->next, length - i - 1);

		return root;
	}

	TreeNode* build_Tree(int start, int end) {
		if (start > end)
			return NULL;

		int mid = start + (end - start) / 2;
		TreeNode* left = this->build_Tree(start, mid - 1);

		TreeNode* root = new TreeNode(this->node->val);
		root->left = left;
		this->node = this->node->next;

		TreeNode* right = this->build_Tree(mid + 1, end);
		root->right = right;

		return root;
	}
};
