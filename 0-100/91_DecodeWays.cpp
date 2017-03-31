//description
//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//The number of ways decoding "12" is 2

//Solution:
//Solution 1
//use the DFS to calculate the answer
//what we should pay attention is that when we meet '0',we should return
//but time limit exceeded

//Solution 2
//use the dp
//when we meet the element '0' which not occur at start,we just jump it


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s.front() == '0')
			return 0;

		vector<int> answer(s.size() + 1, 0);
		answer[0] = 1;
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] - '0') == 0)
				continue;;
			answer[i + 1] += answer[i];
			if (i < s.size() - 1) {
				if (s[i] - '0' < 2 || (2 == s[i] - '0'&&s[i + 1] - '0' < 7)) {
					answer[i + 2] += answer[i];
				}
			}
		}

		return answer.back();
	}
};
