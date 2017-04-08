//description
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times).
//However, you may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

//Solution
//suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt.
//And suppose another one is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as "(b - a) + (d - b')".So you just target at monotone sequences.
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int answer = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1])
				answer += prices[i] - prices[i - 1];
		}

		return answer;
	}
};