//Description
//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//1         3     3      2      1
//\ / / / \      \
//3     2     1      1   3      2
/// / \                 \
//2     1         2                 3

//Solution :
//simliar to the next problem
//we can use the rescurion to solve this one by change the root 
//notice that null should be push deliberately
#include <vector>
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
	vector<TreeNode*> generateTrees(int n) {
		if (!n)
			return vector<TreeNode*>{};

		return this->contruct_Tree(1, n);

	}

private:
	vector<TreeNode*> contruct_Tree(int start,int end) {
		vector<TreeNode*> answer;
		if (start > end)
			return vector<TreeNode*>{};

		if (start == end) {
			answer.push_back(new TreeNode(start));
			return answer;
		}
		
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> left_Tree = this->contruct_Tree(start, i-1);
			vector<TreeNode*> right_Tree = this->contruct_Tree(i + 1, end);

			for (auto lNode:left_Tree){
				for (auto RNode:right_Tree){
					TreeNode *root = new TreeNode(i);
					root->left = lNode;
					root->right = RNode;

					answer.push_back(root);
				}
			}
		}

		return answer;
	}
};