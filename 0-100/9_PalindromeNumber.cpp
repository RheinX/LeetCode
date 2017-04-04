//description
//Determine whether an integer is a palindrome.Do this without extra space.
//
//click to show spoilers.
//
//Some hints :
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", 
//you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.

//Solution:
//Solution 1:
//loop the value and get the maximum and minumun value every time

//Solution 2:
//reverse the value get a
//return a==x
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		//方法一
		/*if (x < 0)
		return false;
		int length = 0;
		long long x2 = x;
		while (x2 != 0) {
		length++;
		x2 /= 10;
		}

		for (int i = 0; i < length / 2; i++) {
		int max = x / pow(10, length - i*2 - 1);
		int min = x % 10;

		if (max != min)
		return false;

		x = x - max*pow(10, length - i * 2 - 1) - min;
		x /= 10;
		}

		return true;*/

		//方法二
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;

		long total;
		while (x > total) {
			total = total * 10 + x % 10;
			x /= 10;
		}

		return (x == total || x == total / 10);
	}
};

