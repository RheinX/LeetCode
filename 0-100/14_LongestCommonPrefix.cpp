//Description
//Write a function to find the longest common prefix string amongst an array of strings.

//Solution
//get the shorter prefix among two related string every time
//notice:we should judege the suition where vector is empty
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string answer = strs[0];

		for (int i = 1; i < strs.size(); i++)
			answer = this->Get_Same_String(answer, strs[i]);

		return answer;
	}

	string Get_Same_String(string s, string p) {
		string answer;
		int size = s.size() > p.size() ? p.size() : s.size();
		for (int i = 0; i < size; i++) {
			if (s[i] == p[i])
				answer += s[i];
			else
				break;
		}
		return answer;
	}
};

