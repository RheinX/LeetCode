//Description
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

//Solution
//we can use the stack to solve this problem
//if the character is left one,push it
//otherwise,it can match the stack.pop,continue,otherwise retrun false
//we should notice that when meet the right one,we should judge the stack is empty
//becase the index of three kinds is different,we can do a improvement
//when meet the left one ,push the responding right into stack 
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> answer;
		for (char v : s) {
			if ('(' == v || '[' == v || '{' == v)
				answer.push(v);
			else {
				if (answer.empty())
					return false;
				char former = answer.top();
				if ('(' == former) {
					if (')' == v)
						answer.pop();
					else
						return false;
				}
				else {
					if (2 == int(v) - int(former))
						answer.pop();
					else
						return false;
				}
			}
		}
		return answer.empty();
	}
};
