//Description
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? 
//Find all unique quadruplets in the array which gives the sum of target.
//
//Note : The solution set must not contain duplicate quadruplets.
//
//	For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//	A solution set is :
//[
//	[-1, 0, 0, 1],
//	[-2, -1, 1, 2],
//	[-2, 0, 0, 2]
//]

//Solution
//do it as problem 15
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> answer;

		if (nums.size() < 4)
			return answer;

		/*if (nums.size() == 4 && target == accumulate(nums.begin(), nums.end(), 0)) {
		answer.push_back(nums);
		return answer;
		}
		else if(nums.size() == 4 && target != accumulate(nums.begin(), nums.end(), 0))
		return answer;*/

		sort(nums.begin(), nums.end());

		for (int first = 0; first < nums.size() - 3; first++) {
			for (int second = first + 1; second < nums.size() - 2; second++) {
				int need = target - nums[first] - nums[second];
				int head = second + 1, last = nums.size() - 1;


				while (head < last) {
					if (nums[head] + nums[last] == need) {
						vector<int> now = { nums[first],nums[second],nums[head],nums[last] };
						answer.push_back(now);
						last--; head++;

						while (nums[head - 1] == nums[head]) {
							head++;
						}
						while (nums[last + 1] == nums[last]) {
							last--;

						}
					}
					else if (nums[head] + nums[last] > need) {
						last--;
						while (nums[last + 1] == nums[last]) {
							last--;
						}
					}
					else {
						head++;
						while (nums[head - 1] == nums[head]) {
							head++;
						}
					}
				}
				while (nums[second] == nums[second + 1])
					second++;
			}
			while (nums[first] == nums[first + 1])
				first++;
		}
		return answer;
	}
};
