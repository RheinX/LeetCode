//Description
//Given an array with n objects colored red, white or blue, 
//sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//Note:
//You are not suppose to use the library's sort function for this problem.
//click to show follow up.
//Follow up :
//A rather straight forward solution is a two - pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, 
//then overwrite array with total number of 0's, then 1's and followed by 2's.
//Could you come up with an one - pass algorithm using only constant space ?

//Answer:
//Answer 1
//just use the function sort()

//Answer 2:
//we can loop the array and get the numbers of three colors then just loop the array and rewrite the array

//Answer 3:
//将0放到首部，2放到尾部。用两个指针控制0和2应该出现的位置，
//最后的1自然排好。此题需要注意的当2交换后，2原有的位置可能出现1，
//而代表1的指针未曾改变，处理的方式是此时不令i增加，循环时再次判断当前位置的元素值。


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int r = 0, b = nums.size() - 1;

		for (int i = 0; i <= b;) {
			if (0 == nums[i])
				swap(nums[i++], nums[r++]);
			else if (2 == nums[i])
				swap(nums[i], nums[b--]);
			else
				i++;
		}
	}
};