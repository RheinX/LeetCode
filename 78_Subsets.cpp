//Description
//Given a set of distinct integers, nums, return all possible subsets.
//Note: The solution set must not contain duplicate subsets.
//	For example,
//	If nums = [1, 2, 3], a solution is :
//[
//	[3],
//	[1],
//	[2],
//	[1, 2, 3],
//	[1, 3],
//	[2, 3],
//	[1, 2],
//	[]
//]

//Answer :
//Answer 1:
//利用上一题的查找固定大小的子集数组，将子集的大小从1扩充到size() - i即可。

//Answer 2:
//使用位运算
//class Solution {
//public:
//	vector<vector<int> > subsets(vector<int> &S) {
//		sort(S.begin(), S.end());
//		int elem_num = S.size();
//		int subset_num = pow(2, elem_num);
//		vector<vector<int> > subset_set(subset_num, vector<int>());
//		for (int i = 0; i < elem_num; i++)
//			for (int j = 0; j < subset_num; j++)
//				if ((j >> i) & 1)
//					subset_set[j].push_back(S[i]);
//		return subset_set;
//	}
//}
//
//This is an amazing solution.Learnt a lot.Let me try to explain this to those who didn't get the logic.
//
//Number of subsets for {1, 2, 3 } = 2 ^ 3 .
//why ?
//case    possible outcomes for the set of subsets
//1->Take or dont take = 2
//2->Take or dont take = 2
//3->Take or dont take = 2
//
//therefore, total = 2 * 2 * 2 = 2 ^ 3 = { {} ,{ 1 } ,{ 2 } ,{ 3 } ,{ 1,2 } ,{ 1,3 } ,{ 2,3 } ,{ 1,2,3 } }
//
//Lets assign bits to each outcome->First bit to 1, Second bit to 2 and third bit to 3
//Take = 1
//Dont take = 0
//
//0) 0 0 0->Dont take 3, Dont take 2, Dont take 1 = {}
//1) 0 0 1->Dont take 3, Dont take 2, take 1 = { 1 }
//2) 0 1 0->Dont take 3, take 2, Dont take 1 = { 2 }
//3) 0 1 1->Dont take 3, take 2, take 1 = { 1 , 2 }
//4) 1 0 0->take 3, Dont take 2, Dont take 1 = { 3 }
//5) 1 0 1->take 3, Dont take 2, take 1 = { 1 , 3 }
//6) 1 1 0->take 3, take 2, Dont take 1 = { 2 , 3 }
//7) 1 1 1->take 3, take 2, take 1 = { 1 , 2 , 3 }
//
//In the above logic, Insert S[i] only if (j >> i) & 1 == true   { j E{ 0,1,2,3,4,5,6,7 }   i = ith element in the input array }
//
//element 1 is inserted only into those places where 1st bit of j is 1
//if (j >> 0 & 1) == > for above above eg. this is true for sl.no.(j) = 1, 3, 5, 7
//
//element 2 is inserted only into those places where 2nd bit of j is 1
//if (j >> 1 & 1) == for above above eg. this is true for sl.no.(j) = 2, 3, 6, 7
//
//element 3 is inserted only into those places where 3rd bit of j is 1
//if (j >> 2 & 1) == for above above eg. this is true for sl.no.(j) = 4, 5, 6, 7
//
//Time complexity : O(n * 2 ^ n), for every input element loop traverses the whole solution set length i.e. 2 ^ n
//
//
//一个集合，其子集个数个pow(2, n)个。判断第i个子集包含哪些数字，可将其化为二进制，
//出现1的位置上即对应应该出现在i子集的数字。为了判断第i个位置上的位数是否为1，
//使用右移符号，即将二进制右移i位至最低位，和1进行与运算即可。


//Answer 3
//递归回溯法

//Answer 4
//This problem can also be solved iteratively.Take[1, 2, 3] in the problem statement as an example.
//The process of generating all the subsets is like :
//1.	Initially : [[]]
//2.	Adding the first number to all the existed subsets : [[], [1]];
//3.	Adding the second number to all the existed subsets : [[], [1], [2], [1, 2]];
//4.	Adding the third number to all the existed subsets : [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		vector<vector<int>> subs(1, vector<int>());
//		for (int i = 0; i < nums.size(); i++) {
//			int n = subs.size();
//			for (int j = 0; j < n; j++) {
//				subs.push_back(subs[j]);
//				subs.back().push_back(nums[i]);
//			}
//		}
//		return subs;
//	}
//};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> answer;
		vector<int> a;
		answer.push_back(a);
		control_bp(answer, nums);

		return answer;
	}
private:
	void bp(vector<vector<int>>& answer, int lack, vector<int> now, int p,vector<int> &nums) {
		if (!lack) {
			answer.push_back(now);
			return;
		}

		for (int i = p; i < nums.size(); i++) {
			now.push_back(nums[i]);
			bp(answer, lack - 1, now, i + 1,nums);
			now.pop_back();
		}
	}

	void control_bp(vector<vector<int>>& answer, vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++) {
			vector<int> now;
			now.push_back(nums[i]);
			answer.push_back(now);
			for (int j = 1; j < nums.size() - i; j++) {
				bp(answer, j, now, i+1, nums);
			}
		}
	}
};

int main() {
	Solution a;
	vector<int> test = { 1,2,3,4 };
	vector<vector<int>> answer = a.subsets(test);
	for (auto v:answer){
		for (auto value:v){
			cout << value << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}