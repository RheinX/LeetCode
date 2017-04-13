//Description
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//
//Your algorithm should run in O(n) complexity.

//Solution :
//SOlution 1:
//sort the vector first
//and use two variable to finish the problem
//notice that there are exist duplicate elements

//Solution 2:
//use the map to store the value and its responding value
//we set the length of  consecutive elements sequence in the boundary elements
//every time we check the v-1 and v+1,change the boundary value
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//Solution 1
		/*sort(nums.begin(), nums.end());

		if (nums.empty())
			return 0;

		int answer = 1,flag=1;
		for (int i = 1; i < nums.size();i++) {
			if (nums[i] == nums[i - 1]) {
				continue;
			}
			else if (nums[i] - 1 != nums[i - 1]) {
				answer = max(flag, answer);
				flag = 1;
			}
			else
				flag++;
		}
		return max(flag,answer);*/

		//Solution 2:
		map<int, int> numList;
		int answer = 0;
		for (auto v : nums) {
			if (numList.find(v) == numList.end()) {
				numList.insert(pair<int, int>(v, 0));

				int left = 0, right = 0;
				if (numList.end() != numList.find(v + 1)) right = numList.find(v + 1)->second;
				if (numList.end() != numList.find(v - 1)) left = numList.find(v - 1)->second;

				numList.find(v - left)->second = left + right + 1;
				numList.find(v + right)->second = left + right + 1;
				answer = max(answer, left + right + 1);
			}
		}

		return answer;
	}
};