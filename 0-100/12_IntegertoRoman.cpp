//Description
//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999

//Solution
//we can first list the experssion of roman number 
//divide the number and change them into roman number segregately
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string M[] = { "","M","MM","MMM" };
		string C[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		string X[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		string I[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };

		return M[num / 1000] + C[num / 100 % 10] + X[num / 10 % 10] + I[num % 10];
	}
};