//Description
//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//•	Integers in each row are sorted from left to right.
//•	The first integer of each row is greater than the last integer of the previous row.
//For example,
//Consider the following matrix :
//[
//	[1, 3, 5, 7],
//	[10, 11, 16, 20],
//	[23, 30, 34, 50]
//]
//Given target = 3, return true

//Answer :
//Answer 1:
//使用两次二分法，首先定位其所在行数，之后二分法判断具体位置。

//Answer 2:
//将二维数组看做一个一维数组使用二分法。


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()||matrix.front().empty()||target<matrix.front().front() || target>matrix.back().back())
			return false;

		int row = matrix.size();
		int column = matrix.front().size();
		int first = 0, tail = row*column - 1;
		
		while(first != tail) {
			int mid = (first + tail-1) / 2;
			if (matrix[mid / column][mid%column] == target)
				return true;
			else if (matrix[mid / column][mid%column] < target)
				first = mid + 1;
			else
				tail = mid;
		}

		return matrix[first / column][first%column] == target;

	}
};