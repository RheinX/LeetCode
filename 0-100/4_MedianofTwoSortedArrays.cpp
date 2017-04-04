//Description
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2 :
//	nums1 = [1, 2]
//	nums2 = [3, 4]
//
//	The median is(2 + 3) / 2 = 2.5

//Solution :
//Solution 1:
//merge two vector into one vector,sort it
//and then return the answer,but it didn't meet the O(log(m + n))

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;

		nums.insert(nums.end(), nums1.begin(), nums1.end());
		nums.insert(nums.end(), nums2.begin(), nums2.end());
		sort(nums.begin(), nums.end());


		return nums.size() % 2 == 0 ?
			(double)(nums[(nums.size() - 1) / 2] + (double)nums[nums.size() / 2]) / 2 :
			nums[(nums.size() - 1) / 2];
	}

};