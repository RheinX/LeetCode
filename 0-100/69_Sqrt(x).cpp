//description
//Implement int sqrt(int x).
//Compute and return the square root of x.

//Answer 1
//ѭ��i����a = x >> I, ���ǵ�ǰa��ƽ��С��x������һ��a��ƽ������a��
//����������a֮�С���xΪ1ʱ����Ҫ�������ǡ��˷�����ʱ��

//Answer 2
//����˼������������ƽ������x������һ��С��x��˼�룬ʹ��ţ��ƽ����˼��
//A(k + 1) = (A(K) + x / A(k)) / 2
//��A(K)С��xʱ�������ء�����֮�⣬��Ҫע�����Ϊ����A��k��Խ�磬������long���͡�

//Answer 3
//ʹ�ö��ַ������жϣ�һ��Ķ��ַ��ᳬʱ�������Ҫ�����Ż���a*a>x����Ҫ��ʱ���a>x / aҪ����



#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		//����һ��ţ�ٷ�
		/*int answer = x;
		while (pow(answer,2)>x){
			answer = (answer + x / answer) / 2;
		}
		return answer;*/

		//������,���ֲ���
		if (x < 1)
			return 0;
		int left = 1, right = x;
		while (1){
			int mid = (left + right) / 2;
			if (mid*mid == x)
				return mid;
			if (mid> x/mid)
				right = mid;
			else {
				if (mid+1 > x/(mid+1))
					return mid;

				left = mid;
			}

		}

	}
};

int main() {
	Solution a;
	for (int i = 1; i < 100; i++)
		cout << a.mySqrt(i) << endl;
	system("pause");
	return 0;
}