//Description
//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//1         3     3      2      1
//\ / / / \      \
//3     2     1      1   3      2
/// / \                 \
//2     1         2                 3

//Solution:
//set d(i) means the answer we need,f(i,n) means that i is the root of BST and the total numbr is n
//thus ,we can get this formulate:
//D(n)=F(1,n)+F(2,n)+...+F(n-1,n)
//then,we should analyse the relation with d() and f()
//if iTH is the root of BST,so 1 to i-1 is the left subtree of it,it is G(i-1)
//at the same way,the right subtree is G(n-i),so the following formulate we can get
//F(i,n)=G(i-1)*G(n-i)
//D(n)=¡ÆD(i-1)*D(n-i)  i-[1,n-1]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> d(n + 1, 0);

		d[0] = 1; d[1] = 1;
		for (int i = 2; i < n + 1; i++) {
			for (int j = 1; j <= i; j++)
				d[i] += d[j - 1] * d[i - j];
		}

		return d[n];
	}
};