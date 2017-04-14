//Description
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut.

//Solution:
//Solution 1:
//add the functio of previous problem
//return the minium-1 of subsets of previous answer
//consequently TLX

//Solution 2:
//define the variable *cut to cut the string *cut times
//if return true,return *cut
//TLX

//Solution 3:
//we always use the DP when we meet the question that seek for optimal solution
//we can define two-demesion array *answer:answer[i][n] means that the minimum cut from c[i] to c[n]
//answer[i][n]=min(answer[i][j]+answer[j+1][n]+1)(i<=j<n)
//we can simpfy this into one-demision array:answer[i] mean that from i to n
//answer[i]=min(1+answer[j+1]) if c[i] to c[j] is palindrome
#include<vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
		vector<int> answer(s.size() + 1);
		for (int i = 0; i <= s.size(); i++)
			answer[i] = s.size() - i;

		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j < s.size();j++) {
				if (s[i] == s[j] && (j - i < 2 || flag[i + 1][j - 1])) {
					flag[i][j] = true;
					answer[i] = min(answer[i], answer[j + 1] + 1);
				}
			}
		}

		return answer[0] - 1;
	}
};
