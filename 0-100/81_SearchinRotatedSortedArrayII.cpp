//Description
//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed ?
//
//Would this affect the run - time complexity ? How and why ?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Write a function to determine if a given target is in the array.
//
//The array may contain duplicates.

//Answer:
//Answer 1:
//just use the function find

//Answer 2:
//use the binary-search after sorting the array
//of course,we should judge if the array is null

//Answer 3:
//also use the binary-search ,just divide four suitions
//1.num[mid]==target
//2.num[mid]<num[tail]
//3.num[mid]>num[tail]
//4.num[mid]==num[tail]
//for suition 2 and 3 ,it also divide three suition where we should judge the position of target
//but there the solution is same among two solutions 
//for suition 4,the element may be all same

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//Solution 1
		//return nums.end() != find(nums.begin(), nums.end(), target);

		//Solution 2
	/*	if (nums.empty())
			return false;
		sort(nums.begin(), nums.end());
		int head = 0, tail = nums.size() - 1;

		while (head<tail){
			int mid = (head + tail) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] < target)
				head = mid + 1;
			else
				tail = mid - 1;
		}

		return nums[head] == target;*/

		//Solution 3
		if (nums.empty())
			return false;

		int head = 0, tail = nums.size() - 1;
		while (head<tail){
			int mid = (head + tail) / 2;
			if (nums[mid] == nums[tail]) {
				return true;
			}
			else if (nums[mid]>nums[tail]) {
				if (nums[mid] > target&&target >= nums[head])
					tail = mid;
				else
					head = mid + 1;
			}
			else if (nums[mid] < nums[tail]) {
				if (nums[mid] < target&&target <= nums[tail])
					head = mid + 1;
				else
					tail = mid;
			}
			else
				tail--;
		}

		return nums[head] == target;
	}
};
