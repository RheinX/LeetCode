//description
//Implement int sqrt(int x).
//Compute and return the square root of x.

//Answer 1
//循环i，令a = x >> I, 若是当前a的平方小于x，且上一个a的平方大于a，
//所求即在两个a之中。当x为1时，需要单独考虑。此方法超时。

//Answer 2
//总体思想依旧是利用平方根》x，而上一个小于x的思想，使用牛顿平方根思想
//A(k + 1) = (A(K) + x / A(k)) / 2
//当A(K)小于x时，即返回。除此之外，需要注意的是为避免A（k）越界，声明称long类型。

//Answer 3
//使用二分法进行判断，一般的二分法会超时，因此需要进行优化。a*a>x所需要的时间比a>x / a要长。



#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		//方法一，牛顿法
		/*int answer = x;
		while (pow(answer,2)>x){
			answer = (answer + x / answer) / 2;
		}
		return answer;*/

		//方法二,二分查找
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