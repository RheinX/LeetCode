//description
//Given a m x n grid filled with non - negative numbers, 
//find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time


//Answer
//�����ⷽ�����ƣ�����ʱ����������ϲ����󲿽�С���Ǹ������к�����ÿ�ε���ǰһ�����ɡ�


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;

		int row = grid.size();
		int column = grid.front().size();

		for (int i = 1; i < column; i++)
			grid[0][i] += grid[0][i - 1];

		for (int i = 1; i < row; i++)
			grid[i][0] += grid[i - 1][0];

		for (int i = 1; i < row; i++) {
			for (int j = 1; j < column; j ++) {
				grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
			}
		}

		return grid.back().back();
	}
};