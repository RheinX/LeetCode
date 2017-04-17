//Description
//There are N children standing in a line.Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements :
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give ?

//Solution:
//for the first time,we make sure that the left value is bigger than right
//for the second time,we make sure that right is bigger than left
//we should notice that for the second time,we cannot let answer[i] = answer[i + 1] + 1;
//etc 2 3 1£¨results£©,it will let 3 to 2 
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> answer(ratings.size(), 1);
		for (int i = 1; i < ratings.size();i++) {
			if (ratings[i] > ratings[i - 1])
				answer[i] = answer[i - 1] + 1;
		}

		for (int i = ratings.size() - 2; i >= 0;i--) {
			if (ratings[i] > ratings[i + 1])
				answer[i] = max(answer[i], answer[i + 1] + 1);
		}

		return accumulate(answer.begin(), answer.end(),0);
	}
};