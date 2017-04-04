//Description
//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//	Example2 : x = -123, return -321
//
//	click to show spoilers.
//
//	Note :
//	The input is assumed to be a 32 - bit signed integer.Your function should return 0 when the reversed integer overflows

//Solution
//Solution 1:
//change the int to string,reverse it and change to int at last
//we should judge if it beyond the rang

//Solution 2:
//just loop and change

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		//方法一
		////将int转换成int
		//stringstream s;
		//string answer;
		//s << x;
		//s >> answer;

		////若x小于0
		//if (x < 0)
		//	answer = answer.substr(1, answer.size() - 1);

		////倒叙输出
		//string answer2;
		//for (int i = answer.size() - 1; i >= 0; i--)
		//	answer2 += answer[i];

		//s.clear();
		//long long y;
		//s << answer2;
		//s >> y;
		//
		//if (y >= INT_MAX)
		//	return 0;
		//return x > 0 ? y : -y;

		//方法二
		long long now = 1, answer = 0;
		while (x != 0) {
			answer += x % 10;
			x = x / 10;
			answer *= 10;
		}

		return abs(answer / 10) >= INT_MAX ? 0 : answer / 10;
	}


};

