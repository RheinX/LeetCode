//Description
//Given a 2D binary matrix filled with 0's and 1's, 
//find the largest rectangle containing only 1's and return its area.
//For example, given the following matrix :
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 6.

//Answer:
//we can view every row as a histogram,thus,we can solve this by the solution of previous problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix.front().empty())
			return 0;

		int row = matrix.size();
		int column = matrix.front().size();
		vector<vector<int>> heights(row, vector<int>(column));
		for (int i = 0; i < column; i++)
			heights[0][i] = matrix[0][i] - '0';

		for (int i = 1; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (matrix[i][j] - '0')
					heights[i][j] = heights[i - 1][j] + 1;
				else
					heights[i][j] = 0;
			}
		}

		int answer = 0;
		for (int i = 0; i < row; i++)
			answer = max(answer, this->largestRectangleArea(heights[i]));

		return answer;
	}

private:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())
			return 0;

		int answer = 0;
		vector<int> index;
		for (int i = 0; i < heights.size();) {
			if (!index.empty() && heights[i] < heights[index.back()]) {
				int height_index = index.back(); index.pop_back();
				int count = i - (index.empty() ? -1 : index.back()) - 1;
				if (answer < count*heights[height_index])
					answer = count*heights[height_index];
			}
			else
				index.push_back(i++);
		}

		while (!index.empty()) {
			int height_index = index.back(); index.pop_back();
			int count = heights.size() - (index.empty() ? -1 : index.back()) - 1;
			if (answer < count*heights[height_index])
				answer = count*heights[height_index];
		}

		return answer;
	}
};