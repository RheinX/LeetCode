//Description
//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.
//
//
//
//Input:Digit string "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//Solution
//use two vector,it store all the answer the previous number represent
//and another push the new one into

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> answer;
		if ("" == digits)
			return answer;

		string symbol[] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		answer.push_back("");
		for (int i = 0; i < digits.size(); i++) {
			vector<string> answer2;
			for (int j = 0; j < answer.size(); j++) {
				string prefix = answer[j];

				int a = digits[i] - 48;
				for (char v : symbol[int(digits[i]) - 48]) {
					answer2.push_back(prefix + v);
				}
			}
			answer.clear();
			answer = answer2;
		}
		return answer;
	}
};
