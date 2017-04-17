//Description
//Given an array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

//Soltion :
//Solution 1:
//An instance of type of unordered_set<int> *list can be instanced to store the nums
//push into *list if the num[i] exist,otherwise retrench it
//the shortcuts of it is do not meet the requirement that don't use extra memory 

//Solution 2:
//sort the nums and loop it 

//Solution 3:
//use the XOR to solve this problem
//0^N=N,N^N=0,and this meet commutative law

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//Solution 1:
	/*	unordered_set<int> list;
		for (auto v:nums){
			if (list.find(v) == list.end()) list.insert(v);
			else list.erase(v);
		}
		auto answer = list.begin();
		return *answer;*/

		//Solutio 2:
		/*sort(nums.begin(), nums.end());
		int i = 0;
		while (i<nums.size()-1){
			if (nums[i] != nums[i + 1])
				return nums[i];

			i += 2;
		}
		return nums.back();*/

		//Solution 3:
		int answer = 0;
		for (auto v : nums)
			answer ^= v;

		return answer;
	}
};