//Description
//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent - child connections.
//The path must contain at least one node and does not need to go through the root.
//
//For example :
//Given the below binary tree,
//
//1
/// \
//2   3
//Return 6.

//Solution
//the key of problem is that we should deal with the maxPathSum(root),maxPathSum(root->left),maxPathSum(root->right)
//hence,we set a global variable to get the max varible 
//we should also some extra operations
//we can understand it by annotation
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		this->answer = INT_MIN;
		this->find_answer(root);
		return answer;
	}
private:
	int find_answer(TreeNode* root) {
		if (!root)
			return 0;

		//if the total value of children is below 0,we can discard it
		int value_l = max(0,this->find_answer(root->left));
		int value_r = max(0, this->find_answer(root->right));

		//we do not and should not get the max of children seperatelt
		//becase when root->val<0 and his children is all null,it will cause error
		this->answer = max(this->answer, value_l + value_r + root->val);

		return root->val + max(value_r , value_l);
	}

	int answer;
};