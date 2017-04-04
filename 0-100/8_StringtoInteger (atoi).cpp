//Description
//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases.
//If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes : It is intended for this problem to be specified vaguely(ie, no given input specs).
//You are responsible to gather all the input requirements up front

//Solution
//first we should locate the first not null character
//and then judge if it is positive
//we loop the rest part 
//if it beyond the part of '0'-'9' break and if it out of range ,return the int_max/min
//in case of the out of range ,we should set the total long long
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long total = 0;
		int location = 0, flag = 1;
		while (str[location] == ' ')
			location++;

		if (str[location] == '+' || str[location] == '-')
			flag = str[location++] == '-' ? -1 : 1;


		while (str[location] >= '0'&&str[location] <= '9') {
			total = total * 10 + str[location++] - '0';

			if (total >= INT_MAX  && flag == 1)
				return INT_MAX;
			else if (flag == -1 && -total <= INT_MIN)
				return INT_MIN;
		}

		return total*flag;
	}
};
