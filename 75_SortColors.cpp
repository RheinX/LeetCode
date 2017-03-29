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
//��0�ŵ��ײ���2�ŵ�β����������ָ�����0��2Ӧ�ó��ֵ�λ�ã�
//����1��Ȼ�źá�������Ҫע��ĵ�2������2ԭ�е�λ�ÿ��ܳ���1��
//������1��ָ��δ���ı䣬����ķ�ʽ�Ǵ�ʱ����i���ӣ�ѭ��ʱ�ٴ��жϵ�ǰλ�õ�Ԫ��ֵ��


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