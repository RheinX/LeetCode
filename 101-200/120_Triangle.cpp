//description
//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//
//Subscribe to see which companies asked this question.

//Solution :
//Solution 1:
//use the simpliest BFS

//Solution
//use dp from bottom to up
//minpath[k][i] = min(minpath[k + 1][i], minpath[k + 1][i + 1]) + triangle[k][i];

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		auto answer = triangle.back();
		for (int i = triangle.size() - 2; i >= 0;i--) {
			for (int j = 0; j < triangle[i].size();j++) {
				answer[j] = min(answer[j], answer[j + 1]) + triangle[i][j];
			}
		}
		return answer[0];
	}
};