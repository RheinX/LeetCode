//Description
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.

//Solution:
//Solution 1:
//loop the string one time,and get two string :one is order string without invalid character
//another is reverse order

//Solution 2:
//set two pointers points to first and last position initatively
//then we should move the position of pointers and let them point to the position where in its is not invalid character
//judge the character of pointers

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		//Solution 1
		/*string s1, s2;
		transform(s.begin(), s.end(), s.begin(), toupper);
		for (int i = 0; i < s.size(); i++) {
			if (this->isalphanumeric(s[i]))
				s1 += s[i];

			if (this->isalphanumeric(s[s.size() - i - 1]))
				s2 += s[s.size() - i - 1];
		}

		return s1 == s2;*/

		//Solution 2
		transform(s.begin(), s.end(), s.begin(), toupper);
		int first = 0, end = s.size() - 1;
		while (first<=end){
			if (!this->isalphanumeric(s[first])) {
				first++;continue;
			}
				
			if (!this->isalphanumeric(s[end])) {
				end--; continue;
			}
			
			if (s[first] != s[end])
				return false;
			else {
				first++; end--;
			}
		}

		return true;
	}
private:
	bool isalphanumeric(char a) {
		if ((a <= 57 && a >= 48) || (a <= 90 && a >= 65) || (a <= 122 && a >= 97))
			return true;
		return false;
	}
};