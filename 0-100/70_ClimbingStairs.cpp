//Description
//You are climbing a stair case.It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?

//Answer:
//	����һά��������жϣ�iλ�õ�ֵ���ɵ���ķ�����flag[i]=flag[i-1]+flag[i-2].
//ע��:memset�Զ�̬�����ʼ�������⡣


#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int* flag = new int[n + 1];
		for (int i = 0; i <= n; i++)
			flag[i] = 0;
		flag[0] = 1;
		for (int i = 0; i <= n; i++) {
			if (i + 1 <= n)
				flag[i + 1] += flag[i];

			if (i + 2 <= n)
				flag[i + 2] += flag[i];
		}

		return flag[n];
	}
};

int main() {
	Solution a;
	cout << a.climbStairs(35) << endl;
	system("pause");
	return 0;
}