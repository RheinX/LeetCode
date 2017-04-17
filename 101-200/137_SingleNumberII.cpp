//Description
//Given an array of integers, every element appears three times except for one, which appears exactly once.
//Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

//Solution:
//Solution 1:
//like the previous problem,we set an map to do this

//Solution 2:
//Beautiful.Let me describe it to see if I'm understanding it right:
//
//First time number appear->save it in "ones"
//
//Second time->clear "ones" but save it in "twos" for later check
//
//Third time -> try to save in "ones" but value saved in "twos" clear it.
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		/*unordered_map<int, int> list;
		for (auto v:nums){
			if (list.find(v) == list.end())
				list.insert(pair<int, int>(v, 1));

			else if (1 == list.find(v)->second)
				list.find(v)->second = 2;
			else
				list.erase(v);
		}

		return list.begin()->first;*/

		//Solution 2:
		int one = 0,two = 0;
		for (auto v:nums){
			one = (one^v)&~two;
			two = (two^v)&~one;
		}

		return one;
	}
};