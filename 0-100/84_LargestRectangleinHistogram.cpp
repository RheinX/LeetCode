//Description:
//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, 
//find the area of largest rectangle in the histogram.
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//For example,
//Given heights = [2, 1, 5, 6, 2, 3],
//return 10.

//Answer
//Answer 1:
//loop the whole array
//the max area of current element is the total of all element which height is >= its around it  
//so to find the max area of current element,wo just should loop forward and back array 
//add the height[i] until height[j]<height[i]
//but time limit out when meet the last test which the all element is 1 and the size of array is very large

//Answer 2:
//do a improvement at the base of solution 1:
//we can set a vector *index to store the index which need to add area
//when we find that the height[i]<height[index.back()],it means that the area is become largest for index.back()
//height=index.back()  area=(i-index.pop_back().back()-1)*height
//sure,we should segregate the suition where *index is empty ,then the length shoud add one


#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
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

		while (!index.empty()){
			int height_index = index.back(); index.pop_back();
			int count = heights.size() - (index.empty() ? -1 : index.back()) - 1;
			if (answer < count*heights[height_index])
				answer = count*heights[height_index];
		}

		return answer;
	}
};
