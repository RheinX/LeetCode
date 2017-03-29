//Description
//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//For example,
//Given sorted array nums = [1, 1, 1, 2, 2, 3],
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
//It doesn't matter what you leave beyond the new length

//Answer :
//Answer 1:
//利用map记录每个字母出现的次数

//Answer 2:
//由于题目是默认排好序的，因此只需要判断当前元素和num[i - 2]是否相同即可。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//方法一
		/*map<int, int> my_map;
		int position = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (my_map.end() != my_map.find(nums[i]) && my_map.find(nums[i])->second < 2) {
				nums[position++] = nums[i];
				my_map.find(nums[i])->second++;
			}
			else if(my_map.end() == my_map.find(nums[i])){
				my_map.insert(pair<int, int>(nums[i], 1));
				nums[position++] = nums[i];
			}
		}

		return position;*/

		//方法二
		sort(nums.begin(), nums.end());
		int i = 0;
		for (auto v:nums){
			if (i < 2 || v != nums[i - 2])
				nums[i++] = v;
		}

		return i;
	}
};

int main() {
	vector<int> test = { 1,1,1,2,2,2,3,4 };
	Solution a;
	cout << a.removeDuplicates(test) << endl;
	system("pause");
	return 0;
}
