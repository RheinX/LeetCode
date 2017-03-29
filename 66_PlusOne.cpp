//description
//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//The digits are stored such that the most significant digit is at the head of the list.

//Answer 1
//���ô�ǰ�ļӷ���ÿ���жϽ�λ��������С����λ

//Answer 2
//ֻ���λ�������жϣ����ǵ�ǰλ�ϵ���С��9�����λ�󷵻أ������һ

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//����һ
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

		//������
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