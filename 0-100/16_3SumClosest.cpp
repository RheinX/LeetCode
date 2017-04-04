//Description
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, 
//target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

//Solution
//we can also get a number as the previous problem
//and then use the binary-search to do

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 4) {
			return accumulate(nums.begin(), nums.end(), 0);
		}


		sort(nums.begin(), nums.end());
		int offfset = nums[0] + nums[1] + nums[2] - target;
		offfset = abs(offfset);
		int answer = nums[0] + nums[1] + nums[2];

		/*const int size_num = nums.size();
		for (int i = 0; i < size_num - 2; i++) {
		int now = nums[0];
		vector<int>::iterator it = nums.begin();
		nums.erase(it);

		vector<int>::iterator first = nums.begin();
		vector<int>::iterator end = nums.end();
		end--;

		while (first<end){
		int value = *first + *end + now - target;
		if (offfset > abs(value)) {
		answer = *first + *end + now;
		offfset = abs(value);
		}

		if (value>0)
		end--;
		else if (value < 0)
		first++;
		else if (value = 0)
		return 0;

		}
		}*/

		for (int i = 0; i < nums.size() - 2; i++) {
			int first = i + 1;
			int end = nums.size() - 1;

			while (first < end) {
				int now_answer = nums[i] + nums[first] + nums[end];
				if (offfset > abs(now_answer - target)) {
					offfset = abs(now_answer - target);
					answer = now_answer;
				}

				(now_answer > target) ? end-- : first++;
				if (now_answer == target)
					return target;
			}
		}
		return answer;
	}
};
