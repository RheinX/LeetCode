//Description
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].

//Solution :
//Solution 1:
//juset loop the array twice and find the answer

//Solution 2:
//loop the array and insert the element to the map at the same time
//loop the array again,find if there exists the respond element by the map

//Solution 3:
//loop the array and find the answer at the same time by insert and find the element at the same time

#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> answers;

		//二重循环查找
		/*for (int i = 0; i < nums.size(); i++) {
		for (int j = i+1; j < nums.size(); j++) {
		if (nums.at(i) + nums.at(j) == target) {
		answers.push_back(i);
		answers.push_back(j);
		return answers;
		}
		}
		}*/

		////map查找
		//map<int, int> map_num;
		//for (int i = 0; i < nums.size(); i++) {
		//	map_num.insert(pair<int, int>(nums.at(i), i));
		//}
		// 
		//for (int i = 0; i < nums.size(); i++) {
		//	map<int, int>::iterator iterator = map_num.find(target - nums.at(i));
		//	if (iterator != map_num.end() && iterator->second != i) {
		//		answers.push_back(iterator->second);
		//		answers.push_back(i);
		//		
		//		return answers;
		//	}
		//}

		//单次map循环查找
		map<int, int> map_num;
		for (int i = 0; i < nums.size(); i++) {
			//插入数据
			map_num.insert(pair<int, int>(nums[i], i));

			//匹配查询
			map<int, int>::iterator ito = map_num.find(target - nums[i]);
			if (ito != map_num.end() && ito->second != i) {
				answers.push_back(ito->second);
				answers.push_back(i);

				return answers;
			}
		}
	}


};