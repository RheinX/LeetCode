//Description
//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).
//Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

//Solution
//it just should find the largest container,we should loop it
//but we can do a litter improvement:use two pointer
//move the smaller one every time
//the worst suition we should move m times and the contary ,we just need m/2 movements
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0, left = 0, right = height.size() - 1;
		while (left < right) {
			int current = (right - left)*(height[right]>height[left] ? height[left] : height[right]);

			if (current > max)
				max = current;

			if (height[left] > height[right])
				right--;
			else
				left++;
		}
		return max;
	}
};

