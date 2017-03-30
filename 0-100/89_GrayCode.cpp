//Description
//The gray code is a binary numeral system where two successive values differ in only one bit.
//Given a non - negative integer n representing the total number of bits in the code, 
//print the sequence of gray code.A gray code sequence must begin with 0.
//For example, given n = 2, return[0, 1, 3, 2].Its gray code sequence is :
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//Note :
//	For a given n, a gray code sequence is not uniquely defined.
//	For example, [0, 2, 3, 1] is also a valid gray code sequence according to the above definition.
//	For now, the judge is able to judge based on one instance of gray code sequence.Sorry about that.

//extra:the structor of gray code
//1λ����������������
//(n + 1)λ�������е�ǰ2n�����ֵ���nλ����������֣���˳����д����ǰ׺0
//(n + 1)λ�������еĺ�2n�����ֵ���nλ����������֣���������д����ǰ׺1[3]
//n + 1λ������ļ��� = nλ�����뼯��(˳��)��ǰ׺0 + nλ�����뼯��(����)��ǰ׺1

//Answer
//Answer 1:
//we define the vector of answer when n=0(vector={0})
//wejust need to loop n times and each time add the element:*v+pow(2,i)

//Answer 2:
//g(i)=i^(i/2)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		//Solution 1
		/*vector<int> answer = { 0,1 };
		if (n < 1)
			return vector<int>{0};

		if (1 == n)
			return answer;

		for (int i = 1; i < n; i++) {
			int length = answer.size();
			for (int j = length - 1; j >= 0; j--) {
				answer.push_back(answer[j] + pow(2, i));
			}
		}

		return answer;*/

		//Solution 2
		vector<int> answer;
		for (int i = 0; i < 1 << n; i++)
			answer.push_back(i^i >> 1);
		return answer;
	}
};

int main() {
	Solution a;
	vector<int> answer = a.grayCode(3);
	for (auto v:answer){
		cout << v << endl;
	}
	system("pause");
	return 0;
}