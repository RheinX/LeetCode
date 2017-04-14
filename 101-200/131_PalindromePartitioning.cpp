//Description
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
//	["aa", "b"],
//	["a", "a", "b"]
//]

//Solution:
//first we define a m¡¤m matrix(m is the size of s)*flag
//*flag[i][i+j]=1 means s.sub(i,j) is a palindrome string
//the function of initate matrix is in the (5)
//then we use BFS to solve this problem recursively
#include<vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		if (s.empty())
			return vector<vector<string>>{};

		vector<vector<int>> flag(s.size(), vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++) {
			flag[i][i] = 1;
			if (i < s.size() - 1)
				flag[i][i + 1] = s[i] == s[i + 1];
		}
			

		//initita the matrix
		for (int offset = 2; offset < s.size();offset++) {
			for (int start = 0; start < s.size() - offset; start++) {
					flag[start][start + offset] = 
						flag[start + 1][start + offset - 1] && (s[start] == s[start + offset]);
			}
		}

		vector<vector<string>> answer;
		vector<string> now;
		this->DP(answer, now, 0, s, flag);

		return answer;
	}
private:
	void DP(vector<vector<string>> &answer, vector<string> now, int begin, const string& s, const vector<vector<int>> &flag) {
		if (begin >= s.size()) {
			answer.push_back(now);
			return;
		}
		for (int i = 0; i < s.size() - begin;i++) {
			if (flag[begin][begin + i]) {
				now.push_back(s.substr(begin, i + 1));
				this->DP(answer, now, begin + i + 1, s, flag);
				now.pop_back();
			}
		}
	}
};
