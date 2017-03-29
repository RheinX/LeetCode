//description
//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//The digits are stored such that the most significant digit is at the head of the list.

//Answer 1
//利用从前的加法，每次判断进位，调整大小，进位

//Answer 2
//只需对位数进行判断，若是当前位上的数小于9，则进位后返回，否则加一

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//方法一
		if (digits.empty()) {
			digits.push_back(1);
			return digits;
		}
		
		int carry = 0;
		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend();it++) {
			int number;
			if (it == digits.rbegin())
				number = *it + 1 + carry;
			else
				number = *it + carry;
			*it = number % 10;
			carry =number/ 10;
		}
			if (carry)
			digits.insert(digits.begin(), carry);

		return digits;

		//方法二
		if (digits.empty()) {
			digits.push_back(1);
			return digits;
		}

		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend();it++) {
			if (*it < 9) {
				*it=*it+1;
				return digits;
			}
			else
				*it = 0;
		}
		digits.insert(digits.begin(), 1);

		return digits;

	}
};

int main() {
	vector<int> test = { 9,9,9 };
	Solution a;
	vector<int> answer = a.plusOne(test);
	for (int v:answer){
		cout << v;
	}
	system("pause");
	return 0;
}