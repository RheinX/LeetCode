//description:
//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time.
//The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//How many possible unique paths are there ?

//Solution:
//Answer 1:
//use the algor BFS,time limit out

//Answer 2:
//递归，超时。
//if (m == 1 || n == 1) return 1;
//return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);

//Answer 3:
//除了第一排和第一列，每一格可到达的方法都有flag[i - 1][j] + flag[i][j - 1]种，
//而第一排和第一列的格子可到达的方法只有一种。



#include <iostream>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		////方法一
		//int answer = 0;
		//this->find_answer(answer, 1, m, 1, n);

		//方法二
		
		int** flag = new int*[m];
		for (int i = 0; i < m; i++) {
			flag[i] = new int[n];
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0)
					flag[i][j] = 1;
				else
					flag[i][j] = 0;
			}
				
		}

		for (int i = 1; i < m;i++) {
			for (int j = 1; j < n; j++) {
				flag[i][j] += flag[i - 1][j] + flag[i][j - 1];
			}
		}

		return flag[m - 1][n - 1];
	}
private:
	void find_answer(int &answer, int cur_m, int m, int cur_n,int n) {
		if (cur_m == m&&cur_n == n) {
			answer++;
			return;
		}

		if (cur_m == m)
			this->find_answer(answer, cur_m, m, cur_n + 1, n);
		else if (cur_n == n)
			this->find_answer(answer, cur_m + 1, m, cur_n, n);
		else {
			this->find_answer(answer, cur_m, m, cur_n + 1, n);
			this->find_answer(answer, cur_m + 1, m, cur_n, n);
		}
	}
};

int main() {
	Solution a;
	cout << a.uniquePaths(1, 2) << endl;
	system("pause");
	return 0;
}

