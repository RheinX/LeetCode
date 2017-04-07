//description
//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like :
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6

//Solution:
//Solution 1:
//we can get the vector of perorder traverse of tree
//delete the first node of vector and then build the tree as the requirement
//we should notice that the head node to the function that get the preorder travers will pointer to the hail at last
//hence we should add a node pointer to head

//Solution 2:
//we can set a private variable *node and let it pointer to the null
//every time we set the root->right recursivelt and the node will pointer to the tail at last
//and then we let the *node pointer to the current node
//so the *node will back in every recursion

//Solution 3:

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
	void flatten(TreeNode* root) {
		////Solution 1:
		//if (!root)
		//	return;
		//TreeNode* head = root;
		//vector<int> node = this->inorderTraversal(head);
		//node.erase(node.begin());
		//root->left = NULL;
		//TreeNode* p = root;
		//for (auto v : node) {
		//	TreeNode* next = new TreeNode(v);
		//	p->right = next;
		//	p = next;
		//}

		//Solution 2:
		if (!root)
			return;
		this->flatten(root->right);
		this->flatten(root->left);
		root->right = this->node;
		root->left = NULL;
		this->node = root;

	}
private:
	TreeNode *node = NULL;
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> answer;
		if (NULL == root)
			return answer;
		answer.push_back(root->val);
		if (NULL != root->left) {
			vector<int> left_v = inorderTraversal(root->left);
			answer.insert(answer.end(), left_v.begin(), left_v.end());
		}
		if (NULL != root->right) {
			vector<int> left_v = inorderTraversal(root->right);
			answer.insert(answer.end(), left_v.begin(), left_v.end());
		}
		return answer;
	}
};