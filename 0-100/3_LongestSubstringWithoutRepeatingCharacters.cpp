//Description
//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. 
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

//Solution
//the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values,
//and keep two pointers which define the max substring.
//move the right pointer to scan through the string, and meanwhile update the hashmap.
//If the character is already in the hashmap, 
//then move the left pointer to the right of the same character last found.Note that the two pointers can only move forward

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0;
		int size = s.size();
		int max = 0;
		string answer;

		while (i < size&&j < size) {
			if (answer.find(s[j]) != string::npos) {
				int location = answer.find(s[j]);
				answer.erase(0, location + 1);
				i++;
			}


			answer += s[j++];
			max = max > answer.size() ? max : answer.size();
		}

		return max;
	}
};