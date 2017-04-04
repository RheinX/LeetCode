//Description
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? 
//Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//
//	For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

//Solution 
//this kind problem can be called K-Sum problems with a target
//we can choose one number,and then change it to (k-1)-Sum problem
//and the choose another one ,change it to (k-2)-Sum ...
//at last we get the problem that we should find two number in a array that their sum is  target

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;
		if (nums.size() < 3)
			return answer;
		//ÅÅÐò
		sort(nums.begin(), nums.end());
		int size_num = nums.size();

		int former = nums[0];
		for (int i = 0; i < size_num - 2; i++) {
			if (i > 0) {
				if (nums.size() < 1)
					break;
				while (former == nums[0] && nums.size() > 1) {
					vector<int>::iterator it = nums.begin();
					nums.erase(it);

				}
			}
			if (nums.size() < 1)
				break;
			int target = nums[0];
			former = nums[0];
			vector<int>::iterator it = nums.begin();
			nums.erase(it);

			if (nums.size() < 2)
				break;
			vector<int>::iterator first = nums.begin();
			vector<int>::iterator end = nums.end();
			end--;
			while (first < end) {
				if (0 == ((*first) + (*end) + target)) {
					vector<int> now = { target,*first,*end };
					answer.push_back(now);
					do {
						first++;
					} while (*first == *(first - 1));

					do {
						end--;
					} while (*end == *(end + 1));
				}
				else if (*first + *end + target < 0)
					first++;
				else
					end--;
			}

		}
		return answer;
	}

};

