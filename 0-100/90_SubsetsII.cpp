//description
//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//Note: The solution set must not contain duplicate subsets.
//	For example,
//	If nums = [1, 2, 2], a solution is :
//[
//	[2],
//	[1],
//	[1, 2, 2],
//	[2, 2],
//	[1, 2],
//	[]
//]

//Solution
//Solutio 1:
//we can solve this problem by using the bit operator and map
//we just use the same solution with the subset1,and check the whether the tuple has existed before insert
//sure,before do this ,we should sort the nums,otherwise there will some tuple with same elements in different order

//Solution 2:
//for the duplicates,we can view it as a entirety
//so ,it can be add to other tuple with the way of don't put it at all,put one,two....all  element to others
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		//Solution 1
		//sort(nums.begin(), nums.end());
		//map<vector<int>, int> my_map;
		//vector<vector<int>> answer;
		//for (int i = 0; i < 1 << nums.size(); i++) {
		//	vector<int> now;
		//	for (int j = 0; j < nums.size(); j++) {
		//		if ((i >> j) & 1)
		//			now.push_back(nums[j]);
		//	}
		//	if (my_map.end() == my_map.find(now)) {
		//		answer.push_back(now);
		//		my_map.insert(pair<vector<int>, int>(now, 1));
		//	}
		//}
		//return answer;

		//Solution 2
		sort(nums.begin(), nums.end());
		vector<vector<int>> answer = { {} };
		for (int i = 0; i < nums.size();) {
			//get the number of duplicates
			int count = 0;
			while (i+count<nums.size()&&nums[i+count]==nums[i]){
				count++;
			}

			int length_previous = answer.size();
			for (int j = 0; j < length_previous; j++) {
				vector<int> now = answer[j];
				for (int n = 0; n < count; n++) {
					now.push_back(nums[i]);
					answer.push_back(now);
				}
			}
			i += count;
		}

		return answer;
	}
};
