//description:
//Follow up for "Unique Paths":
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.

//Answer
//Answer 1:
//�����ⷽ�����ƣ����ö�ά����������ã�
//��������Ϊ·�ϼ�vector��Ӧλ��Ϊ1ʱ����������flagΪ0���ɡ�
//��Ҫ�������ڵ�һ�к͵�һ�У����������жϣ��ж����л�������vector��Ӧλ���Ƿ�Ϊ1��
//��Ϊ1���򱣳�flagΪ0��ͬʱ֮��flagΪ0�������Ϊ1.

//Answer 2:
//�뷽��һidea��ͬ�������Ż�
//int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//dp[0][1] = 1;
//for (int i = 1; i <= m; ++i)
//	for (int j = 1; j <= n; ++j)
//		if (!obstacleGrid[i - 1][j - 1])
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//return dp[m][n];


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;

		int **flag = new int *[obstacleGrid.size()];
		for (int i = 0; i < obstacleGrid.size(); i++) {
			flag[i] = new int[obstacleGrid.front().size()];
			for (int j = 0; j < obstacleGrid.front().size(); j++) {
				flag[i][j] = 0;
			}
		}
		if (obstacleGrid[0][0])
			return 0;
		
		flag[0][0] = 1;
		for (int i = 1; i < obstacleGrid.front().size(); i++) {
			if (1 != obstacleGrid[0][i])
				flag[0][i] = 1;
			else
				break;
		}
		for (int i = 1; i < obstacleGrid.size(); i++) {
			if (1 != obstacleGrid[i][0])
				flag[i][0] = 1;
			else
				break;
		}
		for (int i = 1; i < obstacleGrid.size(); i++) {
			for (int j = 1; j < obstacleGrid.front().size(); j++) {
				if (!obstacleGrid[i][j])
					flag[i][j] += flag[i - 1][j] + flag[i][j - 1];
			}
		}

		return flag[obstacleGrid.size() - 1][obstacleGrid.front().size() - 1];
	}
};

int main() {
	vector<vector<int>> test{ {0,0},{0,0} };
	Solution a;
	cout << a.uniquePathsWithObstacles(test) << endl;
	system("pause");
	return 0;
}