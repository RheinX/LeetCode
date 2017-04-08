//Description
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Example 1:
//Input: [7, 1, 5, 3, 6, 4]
//	Output : 5
//
//	max.difference = 6 - 1 = 5 (not 7 - 1 = 6, as selling price needs to be larger than buying price)
//	Example 2 :
//	Input : [7, 6, 4, 3, 1]
//	Output : 0
//
//	In this case, no transaction is done, i.e.max profit = 0.

//SOlution:
//set the *min_value equal the first element of vector,*answer=0
//loop the vector,find the minimun of value and the biggest offset of current with *min_value
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;

		int minValue = prices.front();
		int answer = 0;
		for (auto v:prices){
			if (minValue > v)
				minValue = v;
			
			if (v - minValue > answer)
				answer = v - minValue;
		}

		return answer;
	}
};