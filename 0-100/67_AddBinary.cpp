//description
//Given two binary strings, return their sum(also a binary string).
//For example,
//a = "11"
//b = "1"
//Return "100".

//Answer:
//Answer 1:
//倒叙之后，首先循环处理较小的共有部分，之后处理厂部分的剩余部分。之后判断carry是否为1，若为1添加1。

//Answer 2:
//循环一次，每次循环判断当前是否超出size即可。
//string s = "";
//
//int c = 0, i = a.size() - 1, j = b.size() - 1;
//while (i >= 0 || j >= 0 || c == 1)
//{
//	c += i >= 0 ? a[i--] - '0' : 0;
//	c += j >= 0 ? b[j--] - '0' : 0;
//	s = char(c % 2 + '0') + s;
//	c /= 2;
//}
//
//return s;



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		//方法一
		string long_s = a.size() > b.size() ? a : b;
		string short_s= a.size() <= b.size() ? a : b;
		string long_string(long_s.rbegin(), long_s.rend());
		string short_string(short_s.rbegin(), short_s.rend());
		string answer;

		int carry = 0;
		for (int i = 0; i < short_string.size(); i++) {
			int number = short_string[i] - 48 + long_string[i] - 48 + carry;
			answer+=char(number % 2 + 48);
			carry = number / 2;
		}

		for (int i = short_string.size(); i < long_string.size(); i++) {
			int number = long_string[i] - 48 + carry;
			answer += char(number % 2 + 48);
			carry = number / 2;
		}

		if (carry)
			answer += '1';

		string answer2(answer.rbegin(), answer.rend());
		return answer2;

		//方法二
		int size_a = a.size()-1;
		int size_b = b.size()-1;
		int flag = 1;
		int carry = 0;
		string answer = "";
		while (flag||0<size_a||0<size_b){
			carry += size_a >= 0 ? a[size_a--] - '0' : 0;
			carry += size_b >= 0 ? b[size_b--] - '0' : 0;
			answer.insert(0, 1,carry % 2 + '0');
			carry /= 2;

			if (0>size_a && 0>size_b)
				flag = 0;
		}

		if (carry)
			answer.insert(0, 1, '1');

		return answer;
		
	}
};

int main() {
	Solution a;
	cout << a.addBinary("1", "1") << endl;
	system("pause");
	return 0;
}