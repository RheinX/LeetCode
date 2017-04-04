//Description
//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.

//Solution:
//Solution 1:
//use the DFS to solve this problem,it is ok,but in this suition,TLX

//Solution 2:
//dp:f(i,j) means that there i numbers in s1 and j numbers in j can make up of s3
//flag[i][j] = (flag[i - 1][j] && s1[i - 1] == s3[i + j - 1])
//              || (flag[i][j - 1] && s2[j - 1] == s3[i + j - 1])
//sure ,we should divide the suition where the i j equal 0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		/*if (s1.empty() && s2.empty() && s3.empty())
			return true;

		if (!s1.empty() && s1.front() == s3.front()) {
			if (isInterleave(s1.substr(1), s2, s3.substr(1)))
				return true;
		}

		if (!s2.empty() && s2.front() == s3.front()) {
			if (isInterleave(s1, s2.substr(1), s3.substr(1)))
				return true;
		}

		return false;*/
		if (s1.size() + s2.size() != s3.size())
			return false;
		vector<vector<bool>> flag(s1.size() + 1, vector<bool>(s2.size() + 1, false));

		for (int i = 0; i <= s1.size(); i++) {
			for (int j = 0; j <= s2.size(); j++) {
				if (!i && !j)
					flag[i][j] = true;
				else if (!i)
					flag[i][j] = flag[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				else if (!j)
					flag[i][j] = flag[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				else 
					flag[i][j] = (flag[i - 1][j] && s1[i - 1] == s3[i + j - 1])
						|| (flag[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}

		return flag[s1.size()][s2.size()];
	}
};